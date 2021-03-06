// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use these files except in compliance with the License. You may obtain
// a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#include "pch.h"
#include "CanvasCachedGeometry.h"

namespace ABI { namespace Microsoft { namespace Graphics { namespace Canvas
{
    IFACEMETHODIMP CanvasCachedGeometryFactory::CreateFill(
        ICanvasGeometry* geometry,
        ICanvasCachedGeometry** cachedGeometry)
    {
        return CreateFillWithFlatteningTolerance(
            geometry, 
            D2D1_DEFAULT_FLATTENING_TOLERANCE, 
            cachedGeometry);
    }

    IFACEMETHODIMP CanvasCachedGeometryFactory::CreateFillWithFlatteningTolerance(
        ICanvasGeometry* geometry,
        float flatteningTolerance,
        ICanvasCachedGeometry** cachedGeometry)
    {
        return ExceptionBoundary(
            [&]
            {
                CheckInPointer(geometry);
                CheckAndClearOutPointer(cachedGeometry);

                ComPtr<ICanvasDevice> device;
                ThrowIfFailed(geometry->get_Device(&device));

                auto newCanvasCachedGeometry = GetManager()->Create(device.Get(), geometry, flatteningTolerance);
                
                ThrowIfFailed(newCanvasCachedGeometry.CopyTo(cachedGeometry));
            });
    }

    IFACEMETHODIMP CanvasCachedGeometryFactory::CreateStroke(
        ICanvasGeometry* geometry,
        float strokeWidth,
        ICanvasCachedGeometry** cachedGeometry)
    {
        return ExceptionBoundary(
            [&]
            {
                CreateStrokeImpl(geometry, strokeWidth, nullptr, D2D1_DEFAULT_FLATTENING_TOLERANCE, cachedGeometry);
            });
    }

    IFACEMETHODIMP CanvasCachedGeometryFactory::CreateStrokeWithStrokeStyle(
        ICanvasGeometry* geometry,
        float strokeWidth,
        ICanvasStrokeStyle* strokeStyle,
        ICanvasCachedGeometry** cachedGeometry)
    {
        return ExceptionBoundary(
            [&]
            {
                CheckInPointer(strokeStyle);
                CreateStrokeImpl(geometry, strokeWidth, strokeStyle, D2D1_DEFAULT_FLATTENING_TOLERANCE, cachedGeometry);
            });
    }

    IFACEMETHODIMP CanvasCachedGeometryFactory::CreateStrokeWithStrokeStyleAndFlatteningTolerance(
        ICanvasGeometry* geometry,
        float strokeWidth,
        ICanvasStrokeStyle* strokeStyle,
        float flatteningTolerance,
        ICanvasCachedGeometry** cachedGeometry)
    {
        return ExceptionBoundary(
            [&]
            {
                CheckInPointer(strokeStyle);
                CreateStrokeImpl(geometry, strokeWidth, strokeStyle, flatteningTolerance, cachedGeometry);
            });
    }

    void CanvasCachedGeometryFactory::CreateStrokeImpl(
        ICanvasGeometry* geometry,
        float strokeWidth,
        ICanvasStrokeStyle* strokeStyle,
        float flatteningTolerance,
        ICanvasCachedGeometry** cachedGeometry)
    {
        CheckInPointer(geometry);
        CheckAndClearOutPointer(cachedGeometry);

        ComPtr<ICanvasDevice> device;
        ThrowIfFailed(geometry->get_Device(&device));

        auto newCanvasCachedGeometry = GetManager()->Create(
            device.Get(), 
            geometry, 
            strokeWidth,
            strokeStyle,
            flatteningTolerance);

        ThrowIfFailed(newCanvasCachedGeometry.CopyTo(cachedGeometry));
    }

    CanvasCachedGeometry::CanvasCachedGeometry(
        std::shared_ptr<CanvasCachedGeometryManager> manager,
        ID2D1GeometryRealization* d2dGeometryRealization,
        ComPtr<ICanvasDevice> const& device)
        : ResourceWrapper(manager, d2dGeometryRealization)
        , m_canvasDevice(device.Get())
    {

    }

    IFACEMETHODIMP CanvasCachedGeometry::Close()
    {
        m_canvasDevice.Close();
        return ResourceWrapper::Close();
    }

    IFACEMETHODIMP CanvasCachedGeometry::get_Device(ICanvasDevice** device)
    {
        return ExceptionBoundary(
            [&]
            {
                CheckAndClearOutPointer(device);
                auto& canvasDevice = m_canvasDevice.EnsureNotClosed();
                ThrowIfFailed(canvasDevice.CopyTo(device));
            });
    }

    // Cached fills
    ComPtr<CanvasCachedGeometry> CanvasCachedGeometryManager::CreateNew(
        ICanvasDevice* device,
        ICanvasGeometry* geometry,
        float flatteningTolerance)
    {
        CheckInPointer(device);
        CheckInPointer(geometry);

        auto deviceInternal = As<ICanvasDeviceInternal>(device);

        auto d2dGeometry = GetWrappedResource<ID2D1Geometry>(geometry);

        auto d2dGeometryRealization = deviceInternal->CreateFilledGeometryRealization(
            d2dGeometry.Get(),
            flatteningTolerance);

        auto canvasCachedGeometry = Make<CanvasCachedGeometry>(
            shared_from_this(),
            d2dGeometryRealization.Get(),
            device);
        CheckMakeResult(canvasCachedGeometry);

        return canvasCachedGeometry;
    }

    // Cached strokes
    ComPtr<CanvasCachedGeometry> CanvasCachedGeometryManager::CreateNew(
        ICanvasDevice* device,
        ICanvasGeometry* geometry,
        float strokeWidth,
        ICanvasStrokeStyle* strokeStyle,
        float flatteningTolerance)
    {
        CheckInPointer(device);
        CheckInPointer(geometry);

        auto deviceInternal = As<ICanvasDeviceInternal>(device);

        auto d2dGeometry = GetWrappedResource<ID2D1Geometry>(geometry);

        auto d2dGeometryRealization = deviceInternal->CreateStrokedGeometryRealization(
            d2dGeometry.Get(),
            strokeWidth,
            MaybeGetStrokeStyleResource(d2dGeometry.Get(), strokeStyle).Get(),
            flatteningTolerance);

        auto canvasCachedGeometry = Make<CanvasCachedGeometry>(
            shared_from_this(),
            d2dGeometryRealization.Get(),
            device);
        CheckMakeResult(canvasCachedGeometry);

        return canvasCachedGeometry;
    }

    ComPtr<CanvasCachedGeometry> CanvasCachedGeometryManager::CreateWrapper(
        ICanvasDevice* device,
        ID2D1GeometryRealization* resource)
    {
        auto canvasCachedGeometry = Make<CanvasCachedGeometry>(
            shared_from_this(),
            resource,
            device);
        CheckMakeResult(canvasCachedGeometry);

        return canvasCachedGeometry;
    }

    ActivatableClassWithFactory(CanvasCachedGeometry, CanvasCachedGeometryFactory);

}}}}
