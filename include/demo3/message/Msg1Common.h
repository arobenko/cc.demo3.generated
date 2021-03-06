// Generated by commsdsl2comms v3.6.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo3::message::Msg1 message and its fields.

#pragma once

#include <cstdint>

namespace demo3
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo3::message::Msg1 message.
/// @see demo3::message::Msg1Fields
struct Msg1FieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo3::message::Msg1Fields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::message::Msg1Fields::F1 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::message::Msg1Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo3::message::Msg1Fields::F2 field.
    struct F2Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::message::Msg1Fields::F2 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::message::Msg1Fields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo3::message::Msg1Fields::F3 field.
    struct F3Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::message::Msg1Fields::F3 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::message::Msg1Fields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo3::message::Msg1Fields::F4 field.
    struct F4Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo3::message::Msg1Fields::F4 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo3::message::Msg1Fields::F4 field.
        static const char* name()
        {
            return "F4";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref demo3::message::Msg1 message.
/// @see demo3::message::Msg1
struct Msg1Common
{
    /// @brief Name of the @ref demo3::message::Msg1 message.
    static const char* name()
    {
        return "Msg1";
    }
    
};

} // namespace message

} // namespace demo3


