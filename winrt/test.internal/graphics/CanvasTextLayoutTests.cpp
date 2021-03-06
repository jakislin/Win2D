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
#include "CanvasTextLayout.h"
#include "StubCanvasTextFormatAdapter.h"
#include "MockDWriteFactory.h"
#include "MockDWriteTextLayout.h"
#include "MockDWriteFontCollection.h"
#include "StubCanvasTextLayoutAdapter.h"

namespace canvas
{
    using namespace ABI::Windows::UI::Text;

    TEST_CLASS(CanvasTextLayoutTests)
    {
    public:

        struct Fixture
        {
            ComPtr<ICanvasTextFormat> Format;
            std::shared_ptr<CanvasTextLayoutManager> LayoutManager;
            std::shared_ptr<StubCanvasTextLayoutAdapter> Adapter;

            Fixture()
                : Adapter(std::make_shared<StubCanvasTextLayoutAdapter>())
            {
                auto formatAdapter = std::make_shared<StubCanvasTextFormatAdapter>();
                auto formatManager = std::make_shared<CanvasTextFormatManager>(formatAdapter);

                Format = formatManager->Create();

                LayoutManager = std::make_shared<CanvasTextLayoutManager>(Adapter);
            }

            ComPtr<CanvasTextLayout> CreateSimpleTextLayout()
            {
                return LayoutManager->Create(WinString(L"A string"), Format.Get(), 0.0f, 0.0f);
            }
        };

        TEST_METHOD_EX(CanvasTextLayoutTests_Implements_Expected_Interfaces)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            ASSERT_IMPLEMENTS_INTERFACE(textLayout, ICanvasTextLayout);
            ASSERT_IMPLEMENTS_INTERFACE(textLayout, ABI::Windows::Foundation::IClosable);
            ASSERT_IMPLEMENTS_INTERFACE(textLayout, ICanvasResourceWrapperNative);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_Closure)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();
            
            Assert::AreEqual(S_OK, textLayout->Close());

            CanvasTextDirection textDirection{};
            HSTRING str{};
            float fl{};
            FontStretch fontStretch{};
            FontStyle fontStyle{};
            FontWeight fontWeight{};
            CanvasLineSpacingMethod lineSpacingMethod{};
            CanvasVerticalAlignment verticalAlignment{};
            ParagraphAlignment paragraphAlignment{};
            CanvasTextTrimmingGranularity trimmingGranularity{};
            INT32 i{};
            INT32* arr{};
            uint32_t u{};
            CanvasWordWrapping wordWrapping{};
            CanvasDrawTextOptions drawTextOptions{};
            Size size{};
            boolean b{};
            CanvasVerticalGlyphOrientation verticalGlyphOrientation{};
            CanvasOpticalAlignment opticalAlignment{};
            Rect rect{};
            CanvasTextLayoutRegion hitTestDesc{};
            Vector2 pt{};
            CanvasTextLayoutRegion* hitTestDescArr{};

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFormatChangeIndices(&u, &arr));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_FlowDirection(&textDirection));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_FlowDirection(textDirection));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultFontFamily(&str));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultFontSize(&fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultFontStretch(&fontStretch));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultFontStyle(&fontStyle));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultFontWeight(&fontWeight));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_IncrementalTabStop(&fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_IncrementalTabStop(fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LineSpacingMethod(&lineSpacingMethod));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_LineSpacingMethod(lineSpacingMethod));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LineSpacing(&fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_LineSpacing(fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LineSpacingBaseline(&fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_LineSpacingBaseline(fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DefaultLocaleName(&str));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_VerticalAlignment(&verticalAlignment));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_VerticalAlignment(verticalAlignment));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_ReadingDirection(&textDirection));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_ReadingDirection(textDirection));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_ParagraphAlignment(&paragraphAlignment));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_ParagraphAlignment(paragraphAlignment));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_TrimmingGranularity(&trimmingGranularity));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_TrimmingGranularity(trimmingGranularity));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_TrimmingDelimiter(&str));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_TrimmingDelimiter(str));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_TrimmingDelimiterCount(&i));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_TrimmingDelimiterCount(i));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_WordWrapping(&wordWrapping));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_WordWrapping(wordWrapping));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_Options(&drawTextOptions));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_Options(drawTextOptions));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_MaximumLayoutSize(&size));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_MaximumLayoutSize(size));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetMinimumLayoutWidth(&fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFontFamily(0, &str));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetFontFamily(0, 0, str));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFontSize(0, &fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetFontSize(0, 0, fl));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFontStretch(0, &fontStretch));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetFontStretch(0, 0, fontStretch));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFontStyle(0, &fontStyle));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetFontStyle(0, 0, fontStyle));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetFontWeight(0, &fontWeight));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetFontWeight(0, 0, fontWeight));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetLocaleName(0, &str));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetLocaleName(0, 0, str));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetStrikethrough(0, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetStrikethrough(0, 0, b));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetUnderline(0, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetUnderline(0, 0, b));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetPairKerning(0, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetPairKerning(0, 0, b));

            Assert::AreEqual(RO_E_CLOSED, textLayout->GetLeadingCharacterSpacing(0, &fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->GetTrailingCharacterSpacing(0, &fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->GetMinimumCharacterAdvanceWidth(0, &fl));
            Assert::AreEqual(RO_E_CLOSED, textLayout->SetCharacterSpacing(fl, fl, fl, 0, 0));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_VerticalGlyphOrientation(&verticalGlyphOrientation));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_VerticalGlyphOrientation(verticalGlyphOrientation));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_OpticalAlignment(&opticalAlignment));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_OpticalAlignment(opticalAlignment));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LastLineWrapping(&b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->put_LastLineWrapping(b));

            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LayoutBounds(&rect));
            Assert::AreEqual(RO_E_CLOSED, textLayout->get_LineCount(&i));
            Assert::AreEqual(RO_E_CLOSED, textLayout->get_DrawBounds(&rect));
            Assert::AreEqual(RO_E_CLOSED, textLayout->HitTest(Vector2{}, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->HitTestWithCoords(0, 0, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->HitTestWithDescription(Vector2{}, &hitTestDesc, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->HitTestWithDescriptionAndCoords(0, 0, &hitTestDesc, &b));
            Assert::AreEqual(RO_E_CLOSED, textLayout->GetCaretPosition(0, b, &pt));
            Assert::AreEqual(RO_E_CLOSED, textLayout->GetCaretPositionWithDescription(0, b, &hitTestDesc, &pt));
            Assert::AreEqual(RO_E_CLOSED, textLayout->GetCharacterRegions(0, 0, &u, &hitTestDescArr));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_NullArgs)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            INT32* arr;
            CanvasTextLayoutRegion hitTestDesc{};
            CanvasTextLayoutRegion* hitTestDescArr{};
            boolean b{};
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFormatChangeIndices(nullptr, &arr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_FlowDirection(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultFontFamily(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultFontSize(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultFontStretch(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultFontStyle(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultFontWeight(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_IncrementalTabStop(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LineSpacingMethod(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LineSpacing(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LineSpacingBaseline(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DefaultLocaleName(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_VerticalAlignment(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_ReadingDirection(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_ParagraphAlignment(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_TrimmingGranularity(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_TrimmingDelimiter(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_TrimmingDelimiterCount(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_WordWrapping(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_MaximumLayoutSize(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetMinimumLayoutWidth(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontFamily(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontSize(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontStretch(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontStyle(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontWeight(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetLocaleName(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetStrikethrough(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetUnderline(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetPairKerning(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetLeadingCharacterSpacing(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetTrailingCharacterSpacing(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetMinimumCharacterAdvanceWidth(0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_VerticalGlyphOrientation(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_OpticalAlignment(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LastLineWrapping(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LayoutBounds(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_LineCount(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->get_DrawBounds(nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->HitTest(Vector2{}, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->HitTestWithCoords(0, 0, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->HitTestWithDescription(Vector2{}, &hitTestDesc, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->HitTestWithDescriptionAndCoords(0, 0, &hitTestDesc, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCaretPosition(0, b, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCaretPositionWithDescription(0, b, &hitTestDesc, nullptr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCharacterRegions(0, 0, nullptr, &hitTestDescArr));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_NegativeIntegralArgs)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            WinString stringIn(L"any_string");
            HSTRING stringOut;
            float fl;
            FontStretch fontStretch;
            FontStyle fontStyle;
            FontWeight fontWeight;
            boolean b;
            CanvasTextLayoutRegion hitTestDesc{};
            Vector2 pt{};
            CanvasTextLayoutRegion* hitTestDescArr{};
            uint32_t u{};

            Assert::AreEqual(E_INVALIDARG, textLayout->put_TrimmingDelimiterCount(-1));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontFamily(-1, &stringOut));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontFamily(-1, 0, stringIn));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontFamily(0, -1, stringIn));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontSize(-1, &fl));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontSize(-1, 0, fl));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontSize(0, -1, fl));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontStretch(-1, &fontStretch));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontStretch(-1, 0, fontStretch));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontStretch(0, -1, fontStretch));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontStyle(-1, &fontStyle));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontStyle(-1, 0, fontStyle));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontStyle(0, -1, fontStyle));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetFontWeight(-1, &fontWeight));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontWeight(-1, 0, fontWeight));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetFontWeight(0, -1, fontWeight));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetLocaleName(-1, &stringOut));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetLocaleName(-1, 0, stringIn));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetLocaleName(0, -1, stringIn));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetStrikethrough(-1, &b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetStrikethrough(-1, 0, b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetStrikethrough(0, -1, b));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetUnderline(-1, &b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetUnderline(-1, 0, b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetUnderline(0, -1, b));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetPairKerning(-1, &b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetPairKerning(-1, 0, b));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetPairKerning(0, -1, b));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetLeadingCharacterSpacing(-1, &fl));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetTrailingCharacterSpacing(-1, &fl));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetMinimumCharacterAdvanceWidth(-1, &fl));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetCharacterSpacing(fl, fl, fl, -1, 0));
            Assert::AreEqual(E_INVALIDARG, textLayout->SetCharacterSpacing(fl, fl, fl, 0, -1));

            Assert::AreEqual(E_INVALIDARG, textLayout->GetCaretPosition(-1, false, &pt));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCaretPositionWithDescription(-1, false, &hitTestDesc, &pt));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCharacterRegions(-1, 0, &u, &hitTestDescArr));
            Assert::AreEqual(E_INVALIDARG, textLayout->GetCharacterRegions(0, -1, &u, &hitTestDescArr));
        }

        //
        // All of the 'simple' properties which don't operate on a string range of text layout are
        // grouped together and tested using the macros below.
        //

#define TEST_METHOD_GLOBAL_GETTER(name, mockName, dwriteValue, canvasValueType, canvasValue) \
        TEST_METHOD_EX(CanvasTextLayoutTests_get_##name)                    \
        {                                                                                  \
            Fixture f;                                                                     \
                                                                                           \
            auto textLayout = f.CreateSimpleTextLayout();                                  \
                                                                                           \
            f.Adapter->MockTextLayout->##mockName##.SetExpectedCalls(1,                    \
                [&]()                                                                      \
            {                                                                              \
                return dwriteValue;                                                        \
            });                                                                            \
                                                                                           \
            canvasValueType value;                                                         \
            Assert::AreEqual(S_OK, textLayout->get_##name##(&value));       \
            Assert::AreEqual(canvasValue, value);                                          \
        }  

#define TEST_METHOD_GLOBAL_SETTER(name, mockName, dwriteValueType, dwriteValue, canvasValue)      \
        TEST_METHOD_EX(CanvasTextLayoutTests_put_##name)                                          \
        {                                                                                         \
            Fixture f;                                                                            \
                                                                                                  \
            auto textLayout = f.CreateSimpleTextLayout();                                         \
                                                                                                  \
            f.Adapter->MockTextLayout->##mockName##.SetExpectedCalls(1,                           \
                [&](dwriteValueType value)                                                        \
                {                                                                                 \
                    Assert::AreEqual(dwriteValue, value);                                         \
                    return S_OK;                                                                  \
                });                                                                               \
            Assert::AreEqual(S_OK, textLayout->put_##name##(canvasValue));                        \
        }

        TEST_METHOD_GLOBAL_GETTER(FlowDirection, GetFlowDirectionMethod, DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT, CanvasTextDirection, CanvasTextDirection::RightToLeft);
        TEST_METHOD_GLOBAL_SETTER(FlowDirection, SetFlowDirectionMethod, DWRITE_FLOW_DIRECTION, DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT, CanvasTextDirection::RightToLeft);
        TEST_METHOD_GLOBAL_GETTER(DefaultFontSize, GetFontSize_BaseFormat_Method, 99.0f, float, 99.0f);
        TEST_METHOD_GLOBAL_GETTER(DefaultFontStretch, GetFontStretch_BaseFormat_Method, DWRITE_FONT_STRETCH_SEMI_EXPANDED, FontStretch, FontStretch_SemiExpanded);
        TEST_METHOD_GLOBAL_GETTER(DefaultFontStyle, GetFontStyle_BaseFormat_Method, DWRITE_FONT_STYLE_ITALIC, FontStyle, FontStyle_Italic);
        TEST_METHOD_GLOBAL_GETTER(DefaultFontWeight, GetFontWeight_BaseFormat_Method, DWRITE_FONT_WEIGHT_DEMI_BOLD, FontWeight, FontWeight{ 600 });

        TEST_METHOD_GLOBAL_GETTER(IncrementalTabStop, GetIncrementalTabStopMethod, 99.0f, float, 99.0f);
        TEST_METHOD_GLOBAL_SETTER(IncrementalTabStop, SetIncrementalTabStopMethod, float, 99.0f, 99.0f);

        TEST_METHOD_GLOBAL_GETTER(VerticalAlignment, GetParagraphAlignmentMethod, DWRITE_PARAGRAPH_ALIGNMENT_FAR, CanvasVerticalAlignment, CanvasVerticalAlignment::Bottom);
        TEST_METHOD_GLOBAL_SETTER(VerticalAlignment, SetParagraphAlignmentMethod, DWRITE_PARAGRAPH_ALIGNMENT, DWRITE_PARAGRAPH_ALIGNMENT_FAR, CanvasVerticalAlignment::Bottom);

        TEST_METHOD_GLOBAL_GETTER(ReadingDirection, GetReadingDirectionMethod, DWRITE_READING_DIRECTION_BOTTOM_TO_TOP, CanvasTextDirection, CanvasTextDirection::BottomToTop);
        TEST_METHOD_GLOBAL_SETTER(ReadingDirection, SetReadingDirectionMethod, DWRITE_READING_DIRECTION, DWRITE_READING_DIRECTION_BOTTOM_TO_TOP, CanvasTextDirection::BottomToTop);

        TEST_METHOD_GLOBAL_GETTER(ParagraphAlignment, GetTextAlignmentMethod, DWRITE_TEXT_ALIGNMENT_TRAILING, ParagraphAlignment, ParagraphAlignment_Right);
        TEST_METHOD_GLOBAL_SETTER(ParagraphAlignment, SetTextAlignmentMethod, DWRITE_TEXT_ALIGNMENT, DWRITE_TEXT_ALIGNMENT_TRAILING, ParagraphAlignment_Right);

        TEST_METHOD_GLOBAL_GETTER(WordWrapping, GetWordWrappingMethod, DWRITE_WORD_WRAPPING_EMERGENCY_BREAK, CanvasWordWrapping, CanvasWordWrapping::EmergencyBreak);
        TEST_METHOD_GLOBAL_SETTER(WordWrapping, SetWordWrappingMethod, DWRITE_WORD_WRAPPING, DWRITE_WORD_WRAPPING_EMERGENCY_BREAK, CanvasWordWrapping::EmergencyBreak);

        TEST_METHOD_GLOBAL_GETTER(VerticalGlyphOrientation, GetVerticalGlyphOrientationMethod, DWRITE_VERTICAL_GLYPH_ORIENTATION_STACKED, CanvasVerticalGlyphOrientation, CanvasVerticalGlyphOrientation::Stacked);
        TEST_METHOD_GLOBAL_SETTER(VerticalGlyphOrientation, SetVerticalGlyphOrientationMethod, DWRITE_VERTICAL_GLYPH_ORIENTATION, DWRITE_VERTICAL_GLYPH_ORIENTATION_STACKED, CanvasVerticalGlyphOrientation::Stacked);

        TEST_METHOD_GLOBAL_GETTER(OpticalAlignment, GetOpticalAlignmentMethod, DWRITE_OPTICAL_ALIGNMENT_NO_SIDE_BEARINGS, CanvasOpticalAlignment, CanvasOpticalAlignment::NoSideBearings);
        TEST_METHOD_GLOBAL_SETTER(OpticalAlignment, SetOpticalAlignmentMethod, DWRITE_OPTICAL_ALIGNMENT, DWRITE_OPTICAL_ALIGNMENT_NO_SIDE_BEARINGS, CanvasOpticalAlignment::NoSideBearings);

        TEST_METHOD_GLOBAL_GETTER(LastLineWrapping, GetLastLineWrappingMethod, true, boolean, static_cast<boolean>(true));
        TEST_METHOD_GLOBAL_SETTER(LastLineWrapping, SetLastLineWrappingMethod, BOOL, static_cast<BOOL>(true), static_cast<boolean>(true));


        //
        // The simple properties which operate on a string range are grouped together, and tested below.
        //        

#define TEST_METHOD_RANGE_GETTER(name, mockName, dwriteType, dwriteValue, canvasType, canvasValue)  \
        TEST_METHOD_EX(CanvasTextLayoutTests_Get##name##)                                           \
        {                                                                                           \
            Fixture f;                                                                              \
                                                                                                    \
            f.Adapter->MockTextLayout->##mockName##.SetExpectedCalls(1,                             \
                [&](UINT32 currentPosition, dwriteType* out, DWRITE_TEXT_RANGE* textRange)          \
                {                                                                                   \
                    Assert::AreEqual(12345u, currentPosition);                                      \
                    Assert::IsNull(textRange);                                                      \
                    *out = dwriteValue;                                                             \
                    return S_OK;                                                                    \
                });                                                                                 \
                                                                                                    \
            auto textLayout = f.CreateSimpleTextLayout();                                           \
                                                                                                    \
            canvasType value;                                                                       \
            Assert::AreEqual(S_OK, textLayout->Get##name##(12345, &value));                         \
            Assert::AreEqual(canvasValue, value);                                                   \
        }

#define TEST_METHOD_RANGE_SETTER(name, mockName, dwriteType, dwriteValue, canvasValue)              \
        TEST_METHOD_EX(CanvasTextLayoutTests_Set##name##)                                           \
        {                                                                                           \
            Fixture f;                                                                              \
                                                                                                    \
            f.Adapter->MockTextLayout->##mockName##.SetExpectedCalls(1,                             \
                [&](dwriteType value, DWRITE_TEXT_RANGE textRange)                                  \
                {                                                                                   \
                    Assert::AreEqual(123u, textRange.startPosition);                                \
                    Assert::AreEqual(456u, textRange.length);                                       \
                    Assert::AreEqual(dwriteValue, value);                                           \
                    return S_OK;                                                                    \
                });                                                                                 \
                                                                                                    \
            auto textLayout = f.CreateSimpleTextLayout();                                           \
                                                                                                    \
            Assert::AreEqual(S_OK, textLayout->Set##name##(123, 456, canvasValue));                 \
        }

        TEST_METHOD_RANGE_GETTER(FontSize, GetFontSizeMethod, FLOAT, 16.0f, FLOAT, 16.0f);
        TEST_METHOD_RANGE_GETTER(FontStretch, GetFontStretchMethod, DWRITE_FONT_STRETCH, DWRITE_FONT_STRETCH_SEMI_EXPANDED, FontStretch, FontStretch_SemiExpanded);
        TEST_METHOD_RANGE_GETTER(FontStyle, GetFontStyleMethod, DWRITE_FONT_STYLE, DWRITE_FONT_STYLE_ITALIC, FontStyle, FontStyle_Italic);
        TEST_METHOD_RANGE_GETTER(FontWeight, GetFontWeightMethod, DWRITE_FONT_WEIGHT, DWRITE_FONT_WEIGHT_DEMI_BOLD, FontWeight, FontWeight{ 600 });

        TEST_METHOD_RANGE_GETTER(Strikethrough, GetStrikethroughMethod, BOOL, TRUE, boolean, static_cast<boolean>(true));
        TEST_METHOD_RANGE_GETTER(Underline, GetUnderlineMethod, BOOL, TRUE, boolean, static_cast<boolean>(true));

        TEST_METHOD_RANGE_SETTER(FontSize, SetFontSizeMethod, float, 99.0f, 99.0f);
        TEST_METHOD_RANGE_SETTER(FontStretch, SetFontStretchMethod, DWRITE_FONT_STRETCH, DWRITE_FONT_STRETCH_SEMI_EXPANDED, FontStretch_SemiExpanded);

        TEST_METHOD_RANGE_SETTER(FontStyle, SetFontStyleMethod, DWRITE_FONT_STYLE, DWRITE_FONT_STYLE_ITALIC, FontStyle_Italic);
        TEST_METHOD_RANGE_SETTER(FontWeight, SetFontWeightMethod, DWRITE_FONT_WEIGHT, DWRITE_FONT_WEIGHT_DEMI_BOLD, FontWeight{ 600 });

        TEST_METHOD_RANGE_SETTER(Strikethrough, SetStrikethroughMethod, BOOL, TRUE, static_cast<boolean>(true));
        TEST_METHOD_RANGE_SETTER(Underline, SetUnderlineMethod, BOOL, TRUE, static_cast<boolean>(true));

        TEST_METHOD_RANGE_GETTER(PairKerning, GetPairKerningMethod, BOOL, TRUE, boolean, static_cast<boolean>(true));
        TEST_METHOD_RANGE_SETTER(PairKerning, SetPairKerningMethod, BOOL, TRUE, static_cast<boolean>(true));

        //
        // The properties which don't follow common patterns are tested below.
        //

        TEST_METHOD_EX(CanvasTextLayoutTests_get_DefaultFontFamily)
        {
            Fixture f;

            std::wstring fontFamily = L"SomeFontFamily";

            f.Adapter->MockTextLayout->GetFontFamilyNameLength_BaseFormat_Method.AllowAnyCall([&] { return static_cast<uint32_t>(fontFamily.length()); });
            
            f.Adapter->MockTextLayout->GetFontFamilyName_BaseFormat_Method.SetExpectedCalls(1,
                [&](WCHAR* fontFamilyName, UINT32 nameSize)
                {        
                    Assert::AreEqual(static_cast<uint32_t>(fontFamily.length()) + 1, nameSize);
                    wmemcpy_s(fontFamilyName, nameSize, fontFamily.c_str(), fontFamily.length());
                    fontFamilyName[nameSize - 1] = 0;
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();
         
            HSTRING value;
            Assert::AreEqual(S_OK, textLayout->get_DefaultFontFamily(&value));

            Assert::AreEqual(fontFamily.c_str(), WindowsGetStringRawBuffer(value, nullptr));
        }

        template<class GET_LINE_SPACING_METHOD>
        void InitializeGetLineSpacingMethod(GET_LINE_SPACING_METHOD& lineSpacingMethod, DWRITE_LINE_SPACING_METHOD method, FLOAT spacing, FLOAT baseline)
        {            
            lineSpacingMethod.SetExpectedCalls(1,
                [method, spacing, baseline](DWRITE_LINE_SPACING_METHOD* lineSpacingMethod, FLOAT* lineSpacing, FLOAT* lineBaseline)
                {
                    *lineSpacingMethod = method;
                    *lineSpacing = spacing;
                    *lineBaseline = baseline;
                    return S_OK;
                });
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_LineSpacingMethod)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetLineSpacingMethod(f.Adapter->MockTextLayout->GetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_UNIFORM, 0, 0);

            CanvasLineSpacingMethod lineSpacingMethod;
            Assert::AreEqual(S_OK, textLayout->get_LineSpacingMethod(&lineSpacingMethod));
            Assert::AreEqual(CanvasLineSpacingMethod::Uniform, lineSpacingMethod);    
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_LineSpacing)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetLineSpacingMethod(f.Adapter->MockTextLayout->GetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_DEFAULT, 123.0f, 0);

            float fl;
            Assert::AreEqual(S_OK, textLayout->get_LineSpacing(&fl));
            Assert::AreEqual(123.0f, fl);         
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_LineSpacingBaseline)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetLineSpacingMethod(f.Adapter->MockTextLayout->GetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_DEFAULT, 0, 456.0f);

            float fl;
            Assert::AreEqual(S_OK, textLayout->get_LineSpacingBaseline(&fl));
            Assert::AreEqual(456.0f, fl);
        }

        template<class SET_LINE_SPACING_METHOD>
        void InitializeSetLineSpacingMethod(SET_LINE_SPACING_METHOD& lineSpacingMethod, DWRITE_LINE_SPACING_METHOD method, FLOAT spacing, FLOAT baseline)
        {
            lineSpacingMethod.SetExpectedCalls(1,
                [method, spacing, baseline](DWRITE_LINE_SPACING_METHOD lineSpacingMethod, FLOAT lineSpacing, FLOAT lineBaseline)
                {
                    Assert::AreEqual(method, lineSpacingMethod);
                    Assert::AreEqual(spacing, lineSpacing);
                    Assert::AreEqual(baseline, lineBaseline);
                    return S_OK;
                });
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_LineSpacingMethod)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeSetLineSpacingMethod(f.Adapter->MockTextLayout->SetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_UNIFORM, 0, 0);
            Assert::AreEqual(S_OK, textLayout->put_LineSpacingMethod(CanvasLineSpacingMethod::Uniform));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_LineSpacing)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeSetLineSpacingMethod(f.Adapter->MockTextLayout->SetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_DEFAULT, 123.0f, 0);
            Assert::AreEqual(S_OK, textLayout->put_LineSpacing(123.0f));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_LineSpacingBaseline)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeSetLineSpacingMethod(f.Adapter->MockTextLayout->SetLineSpacingMethod, DWRITE_LINE_SPACING_METHOD_DEFAULT, 0, 456.0f);
            Assert::AreEqual(S_OK, textLayout->put_LineSpacingBaseline(456.0f));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_DefaultLocaleName)
        {
            Fixture f;

            std::wstring locale = L"SomeLocaleName";

            auto textLayout = f.CreateSimpleTextLayout();

            f.Adapter->MockTextLayout->GetLocaleNameLength_BaseFormat_Method.AllowAnyCall([&] { return static_cast<uint32_t>(locale.length()); });
            
            f.Adapter->MockTextLayout->GetLocaleName_BaseFormat_Method.SetExpectedCalls(1,
                [&](WCHAR* localeName, UINT32 nameSize)
                {        
                    Assert::AreEqual(static_cast<uint32_t>(locale.length()) + 1, nameSize);
                    wmemcpy_s(localeName, nameSize, locale.c_str(), locale.length());
                    localeName[nameSize - 1] = 0;
                    return S_OK;
                });
         
            HSTRING value;
            Assert::AreEqual(S_OK, textLayout->get_DefaultLocaleName(&value));

            Assert::AreEqual(locale.c_str(), WindowsGetStringRawBuffer(value, nullptr));
        }

        template<class GET_TRIMMING_METHOD>
        void InitializeGetTrimmingMethod(GET_TRIMMING_METHOD& trimMethod, DWRITE_TRIMMING_GRANULARITY trimmingGranularity, UINT32 delimiter, UINT32 delimiterCount)
        {
            trimMethod.SetExpectedCalls(1,
                [trimmingGranularity, delimiter, delimiterCount](DWRITE_TRIMMING* trimmingOptions, IDWriteInlineObject** trimmingSign)
                {
                    trimmingOptions->granularity = trimmingGranularity;
                    trimmingOptions->delimiter = delimiter;
                    trimmingOptions->delimiterCount = delimiterCount;
                    return S_OK;
                });
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_TrimmingGranularityMethod)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_CHARACTER, 0, 0);

            CanvasTextTrimmingGranularity trimmingGranularity;
            Assert::AreEqual(S_OK, textLayout->get_TrimmingGranularity(&trimmingGranularity));
            Assert::AreEqual(CanvasTextTrimmingGranularity::Character, trimmingGranularity);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_TrimmingDelimiter)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, L'@', 0);

            HSTRING str;
            Assert::AreEqual(S_OK, textLayout->get_TrimmingDelimiter(&str));
            Assert::AreEqual(L"@", WindowsGetStringRawBuffer(str, nullptr));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_TrimmingGranularityDelimiterCount)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();
            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, 0, 456);

            INT32 count;
            Assert::AreEqual(S_OK, textLayout->get_TrimmingDelimiterCount(&count));
            Assert::AreEqual(456, count);
        }        

        template<class SET_TRIMMING_METHOD>
        void InitializeSetTrimmingMethod(SET_TRIMMING_METHOD& setTrimmingMethod, DWRITE_TRIMMING_GRANULARITY granularity, UINT32 delimiter, UINT32 delimiterCount)
        {
            setTrimmingMethod.SetExpectedCalls(1,
                [granularity, delimiter, delimiterCount](DWRITE_TRIMMING const* trimmingOptions, IDWriteInlineObject* trimmingSign)
                {
                    Assert::AreEqual(granularity, trimmingOptions->granularity);
                    Assert::AreEqual(delimiter, trimmingOptions->delimiter);
                    Assert::AreEqual(delimiterCount, trimmingOptions->delimiterCount);
                    return S_OK;
                });
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_TrimmingGranularity)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, 0, 0);
            InitializeSetTrimmingMethod(f.Adapter->MockTextLayout->SetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_CHARACTER, 0, 0);
            Assert::AreEqual(S_OK, textLayout->put_TrimmingGranularity(CanvasTextTrimmingGranularity::Character));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_TrimmingDelimiter)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, 0, 0);
            InitializeSetTrimmingMethod(f.Adapter->MockTextLayout->SetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, L'@', 0);
            Assert::AreEqual(S_OK, textLayout->put_TrimmingDelimiter(WinString(L"@")));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_TrimmingDelimiterCount)
        {
            Fixture f;
            auto textLayout = f.CreateSimpleTextLayout();

            InitializeGetTrimmingMethod(f.Adapter->MockTextLayout->GetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, 0, 0);
            InitializeSetTrimmingMethod(f.Adapter->MockTextLayout->SetTrimmingMethod, DWRITE_TRIMMING_GRANULARITY_NONE, 0, 123);
            Assert::AreEqual(S_OK, textLayout->put_TrimmingDelimiterCount(123));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_MaximumLayoutSize)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();
            
            f.Adapter->MockTextLayout->GetMaxWidthMethod.SetExpectedCalls(1, [&]() { return 123.0f; });
            f.Adapter->MockTextLayout->GetMaxHeightMethod.SetExpectedCalls(1, [&]() { return 456.0f; });

            Size size;
            Assert::AreEqual(S_OK, textLayout->get_MaximumLayoutSize(&size));
            Assert::AreEqual(123.0f, size.Width);
            Assert::AreEqual(456.0f, size.Height);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_put_MaximumLayoutSize)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            f.Adapter->MockTextLayout->SetMaxWidthMethod.SetExpectedCalls(1, [&](FLOAT value) { Assert::AreEqual(123.0f, value); return S_OK; });
            f.Adapter->MockTextLayout->SetMaxHeightMethod.SetExpectedCalls(1, [&](FLOAT value) { Assert::AreEqual(456.0f, value); return S_OK; });

            Assert::AreEqual(S_OK, textLayout->put_MaximumLayoutSize(Size{ 123.0f, 456.0f }));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetMinimumLayoutWidth)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            f.Adapter->MockTextLayout->DetermineMinWidthMethod.SetExpectedCalls(1,
                [&](FLOAT* out)
            {
                *out = 123.0f;
                return S_OK;
            });

            float value;
            Assert::AreEqual(S_OK, textLayout->GetMinimumLayoutWidth(&value));
            Assert::AreEqual(123.0f, value);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetFontFamily)
        {
            Fixture f;

            std::wstring fontFamily = L"SomeFontFamily";

            f.Adapter->MockTextLayout->GetFontFamilyNameLengthMethod.SetExpectedCalls(1,
                [&](UINT32 currentPosition, UINT32* nameLength, DWRITE_TEXT_RANGE* textRange) 
                { 
                    Assert::AreEqual(12345u, currentPosition);
                    Assert::IsNull(textRange);
                    *nameLength = static_cast<uint32_t>(fontFamily.length());
                    return S_OK;
                });

            f.Adapter->MockTextLayout->GetFontFamilyNameMethod.SetExpectedCalls(1,
                [&](UINT32 currentPosition, WCHAR* fontFamilyName, UINT32 nameSize, DWRITE_TEXT_RANGE* textRange)
                {
                    Assert::AreEqual(12345u, currentPosition);
                    Assert::AreEqual(static_cast<uint32_t>(fontFamily.length()) + 1, nameSize);
                    wmemcpy_s(fontFamilyName, nameSize, fontFamily.c_str(), fontFamily.length());
                    fontFamilyName[nameSize - 1] = 0;
                    Assert::IsNull(textRange);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            HSTRING value;
            Assert::AreEqual(S_OK, textLayout->GetFontFamily(12345, &value));

            Assert::AreEqual(fontFamily.c_str(), WindowsGetStringRawBuffer(value, nullptr));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetLocaleName)
        {
            Fixture f;

            std::wstring locale = L"SomeLocale";

            f.Adapter->MockTextLayout->GetLocaleNameLengthMethod.SetExpectedCalls(1,
                [&](UINT32 currentPosition, UINT32* nameLength, DWRITE_TEXT_RANGE* textRange)
                {
                    Assert::AreEqual(12345u, currentPosition);
                    Assert::IsNull(textRange);
                    *nameLength = static_cast<uint32_t>(locale.length());
                    return S_OK;
                });

            f.Adapter->MockTextLayout->GetLocaleNameMethod.SetExpectedCalls(1,
                [&](UINT32 currentPosition, WCHAR* localeName, UINT32 nameSize, DWRITE_TEXT_RANGE* textRange)
                {
                    Assert::AreEqual(12345u, currentPosition);
                    Assert::AreEqual(static_cast<uint32_t>(locale.length()) + 1, nameSize);
                    wmemcpy_s(localeName, nameSize, locale.c_str(), locale.length());
                    localeName[nameSize - 1] = 0;
                    Assert::IsNull(textRange);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            HSTRING value;
            Assert::AreEqual(S_OK, textLayout->GetLocaleName(12345, &value));

            Assert::AreEqual(locale.c_str(), WindowsGetStringRawBuffer(value, nullptr));
        }

        //
        // The logic for URI manipulation and loading custom fonts is shared
        // between CanvasTextFormat and CanvasTextLayout. There are tests 
        // exercising the custom font loading in the text format
        // unit tests, and so they are not exhaustively duplicated here.
        // 

        TEST_METHOD_EX(CanvasTextLayoutTests_SetFontFamily_EmptyUri)
        {
            Fixture f;

            std::wstring fontFamily = L"SomeFontFamily";

            f.Adapter->MockTextLayout->SetFontCollectionMethod.SetExpectedCalls(1,
                [&](IDWriteFontCollection* fontCollection, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::IsNull(fontCollection); // System font collection should be used
                    Assert::AreEqual(123u, textRange.startPosition);
                    Assert::AreEqual(456u, textRange.length);
                    return S_OK;
                });

            f.Adapter->MockTextLayout->SetFontFamilyNameMethod.SetExpectedCalls(1,
                [&](WCHAR const* fontFamilyName, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::AreEqual(fontFamily.c_str(), fontFamilyName);
                    Assert::AreEqual(123u, textRange.startPosition);
                    Assert::AreEqual(456u, textRange.length);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Assert::AreEqual(S_OK, textLayout->SetFontFamily(123, 456, WinString(fontFamily)));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_SetFontFamily_NonEmptyUri)
        {
            Fixture f;

            std::wstring uri = L"SomeUri";
            std::wstring fontFamily = L"SomeFontFamily";
            std::wstring fullName = uri + L"#" + fontFamily;

            auto mockFontCollection = Make<MockDWriteFontCollection>();

            f.Adapter->GetMockDWriteFactory()->CreateCustomFontCollectionMethod.SetExpectedCalls(1,
                [&](
                IDWriteFontCollectionLoader*,
                void const* key,
                UINT32 keySize,
                IDWriteFontCollection** out)
                {
                    std::wstring keyString(static_cast<const wchar_t*>(key));
                    std::wstring expectedKey = L"pathof(ms-appx:///" + uri + L")";
                    Assert::AreEqual(expectedKey, keyString);
                    Assert::AreEqual(static_cast<uint32_t>(expectedKey.length() * sizeof(wchar_t)), keySize);

                    return mockFontCollection.CopyTo(out);
                });


            f.Adapter->MockTextLayout->SetFontCollectionMethod.SetExpectedCalls(1,
                [&](IDWriteFontCollection* fontCollection, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::IsNotNull(fontCollection);
                    Assert::IsTrue(IsSameInstance(mockFontCollection.Get(), fontCollection));
                    Assert::AreEqual(123u, textRange.startPosition);
                    Assert::AreEqual(456u, textRange.length);
                    return S_OK;
                });

            f.Adapter->MockTextLayout->SetFontFamilyNameMethod.SetExpectedCalls(1,
                [&](WCHAR const* fontFamilyName, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::AreEqual(fontFamily.c_str(), fontFamilyName);
                    Assert::AreEqual(123u, textRange.startPosition);
                    Assert::AreEqual(456u, textRange.length);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Assert::AreEqual(S_OK, textLayout->SetFontFamily(123, 456, WinString(fullName)));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_SetLocaleName)
        {
            Fixture f;

            std::wstring locale = L"SomeLocale";

            f.Adapter->MockTextLayout->SetLocaleNameMethod.SetExpectedCalls(1,
                [&](WCHAR const* localeName, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::AreEqual(locale.c_str(), localeName);
                    Assert::AreEqual(123u, textRange.startPosition);
                    Assert::AreEqual(456u, textRange.length);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Assert::AreEqual(S_OK, textLayout->SetLocaleName(123, 456, WinString(locale)));
        }
        
        template<class GetCharacterSpacingMethodType>
        void InitializeGetCharacterSpacingMethod(GetCharacterSpacingMethodType& characterSpacingMethod, FLOAT leadingSpacing, FLOAT trailingSpacing, FLOAT minimumAdvanceWidth)
        {            
            characterSpacingMethod.SetExpectedCalls(1,
                [leadingSpacing, trailingSpacing, minimumAdvanceWidth](UINT32 currentPosition, FLOAT* leading, FLOAT* trailing, FLOAT* min, DWRITE_TEXT_RANGE* textRange)
                {
                    Assert::AreEqual(currentPosition, 123u);
                    Assert::IsNull(textRange);

                    *leading = leadingSpacing;
                    *trailing = trailingSpacing;
                    *min = minimumAdvanceWidth;

                    return S_OK;
                });
        }
        
        TEST_METHOD_EX(CanvasTextLayoutTests_GetLeadingCharacterSpacing)
        {
            Fixture f;

            InitializeGetCharacterSpacingMethod(f.Adapter->MockTextLayout->GetCharacterSpacingMethod, 456.0f, 0.0f, 0.0f);

            auto textLayout = f.CreateSimpleTextLayout();

            float value;
            Assert::AreEqual(S_OK, textLayout->GetLeadingCharacterSpacing(123, &value));
            Assert::AreEqual(456.0f, value);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetTrailingCharacterSpacing)
        {
            Fixture f;

            InitializeGetCharacterSpacingMethod(f.Adapter->MockTextLayout->GetCharacterSpacingMethod, 0.0f, 456.0f, 0.0f);

            auto textLayout = f.CreateSimpleTextLayout();

            float value;
            Assert::AreEqual(S_OK, textLayout->GetTrailingCharacterSpacing(123, &value));
            Assert::AreEqual(456.0f, value);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetMinimumCharacterAdvanceWidth)
        {
            Fixture f;

            InitializeGetCharacterSpacingMethod(f.Adapter->MockTextLayout->GetCharacterSpacingMethod, 0.0f, 0.0f, 456.0f);

            auto textLayout = f.CreateSimpleTextLayout();

            float value;
            Assert::AreEqual(S_OK, textLayout->GetMinimumCharacterAdvanceWidth(123, &value));
            Assert::AreEqual(456.0f, value);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_SetCharacterSpacing)
        {
            Fixture f;

            f.Adapter->MockTextLayout->SetCharacterSpacingMethod.SetExpectedCalls(1,
                [&](FLOAT leadingSpacing, FLOAT trailingSpacing, FLOAT minimumAdvanceWidth, DWRITE_TEXT_RANGE textRange)
                {
                    Assert::AreEqual(12.0f, leadingSpacing);
                    Assert::AreEqual(34.0f, trailingSpacing);
                    Assert::AreEqual(56.0f, minimumAdvanceWidth);
                    Assert::AreEqual(78u, textRange.startPosition);
                    Assert::AreEqual(90u, textRange.length);
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Assert::AreEqual(S_OK, textLayout->SetCharacterSpacing(12.0f, 34.0f, 56.0f, 78, 90));
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_DefaultOptions)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            CanvasDrawTextOptions drawTextOptions;
            Assert::AreEqual(S_OK, textLayout->get_Options(&drawTextOptions));
            Assert::AreEqual(CanvasDrawTextOptions::Default, drawTextOptions);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_OptionsSetAndGet)
        {
            Fixture f;

            auto textLayout = f.CreateSimpleTextLayout();

            Assert::AreEqual(S_OK, textLayout->put_Options(CanvasDrawTextOptions::NoPixelSnap));

            CanvasDrawTextOptions drawTextOptions;
            Assert::AreEqual(S_OK, textLayout->get_Options(&drawTextOptions));
            Assert::AreEqual(CanvasDrawTextOptions::NoPixelSnap, drawTextOptions);
        }


        TEST_METHOD_EX(CanvasTextLayoutTests_get_LayoutBounds)
        {
            Fixture f;

            f.Adapter->MockTextLayout->GetMetricsMethod.SetExpectedCalls(1,
                [&](DWRITE_TEXT_METRICS1* out)
                {
                    Assert::IsNotNull(out);
                    DWRITE_TEXT_METRICS1 metrics{};
                    metrics.left = 1;
                    metrics.top = 2;
                    metrics.width = 3;
                    metrics.height = 4;
                    *out = metrics;
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Rect bounds;
            Assert::AreEqual(S_OK, textLayout->get_LayoutBounds(&bounds));
            Assert::AreEqual(Rect{ 1, 2, 3, 4 }, bounds);
        }
        

        TEST_METHOD_EX(CanvasTextLayoutTests_get_LineCount)
        {
            Fixture f;

            f.Adapter->MockTextLayout->GetMetricsMethod.SetExpectedCalls(1,
                [&](DWRITE_TEXT_METRICS1* out)
                {
                    Assert::IsNotNull(out);
                    DWRITE_TEXT_METRICS1 metrics{};
                    metrics.lineCount = 1234;
                    *out = metrics;
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            int32_t lineCount;
            Assert::AreEqual(S_OK, textLayout->get_LineCount(&lineCount));
            Assert::AreEqual(1234, lineCount);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_get_DrawBounds)
        {
            Fixture f;

            f.Adapter->MockTextLayout->GetMaxWidthMethod.SetExpectedCalls(1,
                [&](){ return 10.0f;  });

            f.Adapter->MockTextLayout->GetMaxHeightMethod.SetExpectedCalls(1,
                [&](){ return 20.0f;  });

            f.Adapter->MockTextLayout->GetOverhangMetricsMethod.SetExpectedCalls(1,
                [&](DWRITE_OVERHANG_METRICS* out)
                {
                    Assert::IsNotNull(out);
                    DWRITE_OVERHANG_METRICS metrics{};
                    // Choose an overhang rect that extends out of the left-top edges,
                    // but inside the right-bottom edges.
                    metrics.left = 1;
                    metrics.top = 2;
                    metrics.right = -3;
                    metrics.bottom = -4;
                    *out = metrics;
                    return S_OK;
                });

            auto textLayout = f.CreateSimpleTextLayout();

            Rect bounds;
            Assert::AreEqual(S_OK, textLayout->get_DrawBounds(&bounds));

            // The result rect is computed based on the layout size and overhang metrics.
            Assert::AreEqual(Rect{ -1, -2, 10 + 1 + -3, 20 + 2 + -4 }, bounds);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_HitTest)
        {
            for (int i = 0; i < 2; ++i)
            {
                Fixture f;

                f.Adapter->MockTextLayout->HitTestPointMethod.SetExpectedCalls(1,
                    [&](FLOAT x, FLOAT y, BOOL* isTrailingHit, BOOL* isInside, DWRITE_HIT_TEST_METRICS* hitTestMetrics)
                {
                    Assert::AreEqual(1.0f, x);
                    Assert::AreEqual(2.0f, y);
                    *isTrailingHit = FALSE;
                    *isInside = TRUE;
                    *hitTestMetrics = DWRITE_HIT_TEST_METRICS{};
                    return S_OK;
                });

                auto textLayout = f.CreateSimpleTextLayout();

                boolean isHit;
                if (i==0)
                    Assert::AreEqual(S_OK, textLayout->HitTest(Vector2{ 1, 2 }, &isHit));
                else
                    Assert::AreEqual(S_OK, textLayout->HitTestWithCoords(1, 2, &isHit));

                Assert::IsTrue(!!isHit);
            }
        }

        void WriteHitTestDescription(DWRITE_HIT_TEST_METRICS* textLayoutRegion, uint32_t increment = 0)
        {
            textLayoutRegion->textPosition = 1 + increment;
            textLayoutRegion->length = 2 + increment;
            const float floatIncrement = static_cast<float>(increment);
            textLayoutRegion->left = 3 + floatIncrement;
            textLayoutRegion->top = 4 + floatIncrement;
            textLayoutRegion->width = 5 + floatIncrement;
            textLayoutRegion->height = 6 + floatIncrement;
        }

        void VerifyHitTestDescription(CanvasTextLayoutRegion const& textLayoutRegion, uint32_t increment = 0)
        {
            Assert::AreEqual(1 + static_cast<int>(increment), textLayoutRegion.CharacterIndex);
            Assert::AreEqual(2 + static_cast<int>(increment), textLayoutRegion.CharacterCount);
            const float floatIncrement = static_cast<float>(increment);
            Assert::AreEqual(Rect{ 
                3 + floatIncrement,
                4 + floatIncrement,
                5 + floatIncrement,
                6 + floatIncrement }, textLayoutRegion.LayoutBounds);
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_HitTestWithDescription)
        {
            for (int i = 0; i < 2; ++i)
            {
                Fixture f;

                f.Adapter->MockTextLayout->HitTestPointMethod.SetExpectedCalls(1,
                    [&](FLOAT x, FLOAT y, BOOL* isTrailingHit, BOOL* isInside, DWRITE_HIT_TEST_METRICS* hitTestMetrics)
                    {
                        Assert::AreEqual(1.0f, x);
                        Assert::AreEqual(2.0f, y);
                        *isTrailingHit = FALSE;
                        *isInside = FALSE;
                        *hitTestMetrics = DWRITE_HIT_TEST_METRICS{};
                        WriteHitTestDescription(hitTestMetrics);
                        return S_OK;
                    });

                auto textLayout = f.CreateSimpleTextLayout();

                boolean isHit;
                CanvasTextLayoutRegion description;
                if (i == 0)
                    Assert::AreEqual(S_OK, textLayout->HitTestWithDescription(Vector2{ 1, 2 }, &description, &isHit));
                else
                    Assert::AreEqual(S_OK, textLayout->HitTestWithDescriptionAndCoords(1, 2, &description, &isHit));

                VerifyHitTestDescription(description);
                Assert::IsFalse(!!isHit);
            }
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_HitTestWithDescriptionAndTrailingSide)
        {
            for (int i = 0; i < 2; ++i)
            {
                Fixture f;

                f.Adapter->MockTextLayout->HitTestPointMethod.SetExpectedCalls(1,
                    [&](FLOAT x, FLOAT y, BOOL* isTrailingHit, BOOL* isInside, DWRITE_HIT_TEST_METRICS* hitTestMetrics)
                    {
                        Assert::AreEqual(1.0f, x);
                        Assert::AreEqual(2.0f, y);
                        *isTrailingHit = TRUE;
                        *isInside = TRUE;
                        *hitTestMetrics = DWRITE_HIT_TEST_METRICS{};
                        WriteHitTestDescription(hitTestMetrics);
                        return S_OK;
                    });

                auto textLayout = f.CreateSimpleTextLayout();

                boolean isHit;
                CanvasTextLayoutRegion description;
                boolean trailingSideOfCharacter;
                if (i == 0)
                    Assert::AreEqual(S_OK, textLayout->HitTestWithDescriptionAndTrailingSide(Vector2{ 1, 2 }, &description, &trailingSideOfCharacter, &isHit));
                else
                    Assert::AreEqual(S_OK, textLayout->HitTestWithDescriptionAndCoordsAndTrailingSide(1, 2, &description, &trailingSideOfCharacter, &isHit));

                VerifyHitTestDescription(description);
                Assert::IsTrue(!!isHit);
                Assert::IsTrue(!!trailingSideOfCharacter);
            }
        }

        TEST_METHOD_EX(CanvasTextLayoutTests_GetCaretPosition)
        {
            for (int i = 0; i < 2; ++i)
            {
                Fixture f;

                f.Adapter->MockTextLayout->HitTestTextPositionMethod.SetExpectedCalls(1,
                    [&](UINT32 textPosition, BOOL isTrailingHit, FLOAT* pointX, FLOAT* pointY, DWRITE_HIT_TEST_METRICS* hitTestMetrics)
                    {
                        Assert::AreEqual(1u, textPosition);
                        Assert::IsTrue(!!isTrailingHit);
                        *pointX = 2.0f;
                        *pointY = 3.0f;
                        if(i==1)
                            WriteHitTestDescription(hitTestMetrics);
                        return S_OK;
                    });

                auto textLayout = f.CreateSimpleTextLayout();

                Vector2 caretLocation;
                CanvasTextLayoutRegion textLayoutRegion;
                if (i == 0)
                    Assert::AreEqual(S_OK, textLayout->GetCaretPosition(1, true, &caretLocation));
                else
                {
                    Assert::AreEqual(S_OK, textLayout->GetCaretPositionWithDescription(1, true, &textLayoutRegion, &caretLocation));
                    VerifyHitTestDescription(textLayoutRegion);
                }

                Assert::AreEqual(Vector2{ 2, 3 }, caretLocation);
            }
        }               

        TEST_METHOD_EX(CanvasTextLayoutTests_GetCharacterRegions)
        {
            Fixture f;

            int callCount = 0;

            f.Adapter->MockTextLayout->HitTestTextRangeMethod.SetExpectedCalls(2,
                [&](UINT32 textPosition, UINT32 textLength, FLOAT originX, FLOAT originY, DWRITE_HIT_TEST_METRICS* hitTestMetrics, UINT32 maxCount, UINT32* actualCount)
                {
                    Assert::AreEqual(1u, textPosition);
                    Assert::AreEqual(2u, textLength);
                    Assert::AreEqual(0.0f, originX);
                    Assert::AreEqual(0.0f, originY);

                    *actualCount = 3;
                    if (callCount == 0)
                    {
                        Assert::AreEqual(0u, maxCount);
                        callCount++;
                        return E_NOT_SUFFICIENT_BUFFER;
                    }
                    else
                    {
                        Assert::AreEqual(3u, maxCount);

                        for (int i = 0; i < 3; i++)
                            WriteHitTestDescription(&hitTestMetrics[i], i);

                        callCount++;
                        return S_OK;
                    }
                });

            auto textLayout = f.CreateSimpleTextLayout();

            uint32_t descriptionCount;
            CanvasTextLayoutRegion* hitTestDescriptionArray;
            Assert::AreEqual(S_OK, textLayout->GetCharacterRegions(1, 2, &descriptionCount, &hitTestDescriptionArray));
            Assert::AreEqual(3u, descriptionCount);

            for (int i = 0; i < 3; i++)
                VerifyHitTestDescription(hitTestDescriptionArray[i], i);
        }
    };
}