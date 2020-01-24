#pragma once

#include <type_traits>
#include <inttypes.h>

struct KeyEvent
{
    enum class Key : uint8_t
    {
        Key0, Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9, Key10, Key11, None, LastEnumeration
    };

    enum class Type : uint8_t
    {
        Pressed, Released, Repeated, DoublePressed, None, LastEnumeration
    };

    using UnterlyingTypeofKey = std::underlying_type<Key>::type;
    using UnterlyingTypeofType = std::underlying_type<Type>::type;

    constexpr static uint8_t keyEnumerationsCount();

    constexpr static uint8_t keyTypeEnumerationsCount();

    constexpr static uint8_t keysCount();

    constexpr static uint8_t typesCount();

    static uint8_t uint8FromKey(Key ke);

    constexpr static uint8_t uint8FromKeyType(Type kt);

    static Key keyFromUint8(uint8_t ke);

    static Type keyTypeFromUint8(uint8_t kt);

    Key key{Key::None};
    Type type{Type::None};
    uint16_t repeated{0};
};

constexpr uint8_t KeyEvent::keyEnumerationsCount()
{
    return static_cast<UnterlyingTypeofKey>(Key::LastEnumeration);
}

constexpr uint8_t KeyEvent::keysCount()
{
    return keyEnumerationsCount() - 1;
}

constexpr uint8_t KeyEvent::keyTypeEnumerationsCount()
{
    return static_cast<UnterlyingTypeofType>(Type::LastEnumeration);
}

constexpr uint8_t KeyEvent::uint8FromKeyType(Type kt)
{
    return static_cast<UnterlyingTypeofType>(kt);
}
