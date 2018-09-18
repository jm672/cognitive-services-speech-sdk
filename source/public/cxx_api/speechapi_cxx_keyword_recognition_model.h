//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
// speechapi_cxx_keyword_recognition_model.h: Public API declarations for KeywordRecognitionModel C++ class
//

#pragma once
#include <speechapi_cxx_common.h>
#include <speechapi_cxx_string_helpers.h>
#include <speechapi_c_keyword_recognition_model.h>


namespace Microsoft {
namespace CognitiveServices {
namespace Speech {

/// <summary>
/// Represents keyword recognition model used w/ StartKeywordRecognitionAsync methods.
/// </summary>
class KeywordRecognitionModel
{
public:

    /// <summary>
    /// Creates a keyword recognition model using the specified file.
    /// </summary>
    /// <param name="fileName">The file name of the keyword recognition model.</param>
    /// <returns>A shared pointer to keyword recognition model.</returns>
    static std::shared_ptr<KeywordRecognitionModel> FromFile(const SPXSTRING& fileName)
    {
        SPXKEYWORDHANDLE hkeyword = SPXHANDLE_INVALID;
        SPX_THROW_ON_FAIL(keyword_recognition_model_create_from_file(Utils::ToUTF8(fileName).c_str(), &hkeyword));
        return std::make_shared<KeywordRecognitionModel>(hkeyword);
    }

    /// <summary>
    /// Internal constructor. Creates a new instance using the provided handle.
    /// </summary>
    explicit KeywordRecognitionModel(SPXKEYWORDHANDLE hkeyword = SPXHANDLE_INVALID) : m_hkwmodel(hkeyword) { }

    /// <summary>
    /// Virtual destructor.
    /// </summary>
    virtual ~KeywordRecognitionModel() { keyword_recognition_model_handle_release(m_hkwmodel); }

    /// <summary>
    /// Internal. Explicit conversion operator.
    /// </summary>
    explicit operator SPXKEYWORDHANDLE() { return m_hkwmodel; }

private:

    DISABLE_COPY_AND_MOVE(KeywordRecognitionModel);

    SPXKEYWORDHANDLE m_hkwmodel;
};


} } } // Microsoft::CognitiveServices::Speech
