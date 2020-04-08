#pragma once

#include <inttypes.h>
#include <elapsedMillis.h>
#include <Adafruit_MPR121.h>

class KeyEventReceiver;

class Keyboard
{
    uint16_t short_keypress_delay_ms;
    uint16_t double_keypress_delay_ms;
    uint16_t last_touched_flags = 0;
    Adafruit_MPR121 cap;
    elapsedMillis key_repeated_time_elapsed{0};
    elapsedMillis key_double_pressed_time_elapsed{0};

    KeyEventReceiver *key_event_receiver = {nullptr};
 public:

    Keyboard(uint16_t short_keypress_delay_ms = 125, uint16_t double_keypress_delay_ms = 250);

    bool setup(KeyEventReceiver *receiver = nullptr, uint8_t i2c_addr = 0x5B);

    bool process();

    bool setEventReceiver(KeyEventReceiver *receiver);

    bool is_initialized{false};
};
