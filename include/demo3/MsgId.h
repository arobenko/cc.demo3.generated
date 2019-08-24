/// @file
/// @brief Contains definition of message ids enumeration.

#pragma once

#include <cstdint>
#include "demo3/Version.h"

namespace demo3
{

/// @brief Message ids enumeration.
enum MsgId : std::uint8_t
{
    MsgId_Connect = 1, ///< message id of @b Connect message.
    MsgId_Msg1 = 2, ///< message id of @b Msg1 message.
    
    // --- Extra values generated for convenience ---
    MsgId_FirstValue = 1, ///< First defined value.
    MsgId_LastValue = 2, ///< Last defined value.
    MsgId_ValuesLimit = 3, ///< Upper limit for defined values.
    
};

} // namespace demo3


