/*
 * Copyright (c) 2023, Andrew Kaster <akaster@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "JNIHelpers.h"
#include <AK/Utf16StringData.h>

namespace Ladybird {

jstring JavaEnvironment::jstring_from_ak_string(String const& str)
{
    auto as_utf16 = AK::Detail::Utf16StringData::from_utf8(str.bytes_as_string_view(), AK::Detail::Utf16StringData::AllowASCIIStorage::No)->utf16_view();
    return m_env->NewString(reinterpret_cast<jchar const*>(as_utf16.utf16_span().data()), as_utf16.utf16_span().size());
}

}
