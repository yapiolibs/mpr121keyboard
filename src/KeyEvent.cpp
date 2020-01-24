#include "KeyEvent.h"

uint8_t KeyEvent::uint8FromKey(Key ke)
{
    return static_cast<UnterlyingTypeofKey>(ke);
}

KeyEvent::Type KeyEvent::keyTypeFromUint8(uint8_t kt)
{
    return static_cast<Type>(kt);
}

KeyEvent::Key KeyEvent::keyFromUint8(uint8_t ke)
{
    return static_cast<Key>(ke);
}