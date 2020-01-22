#include "KeyEventReceiver.h"
#include "Keyboard.h"

class KeyEventHandler;

KeyEventHandler event_handler;
Keyboard keyboard;

void setup()
{
    keyboard.setup(&event_handler);
}

void loop()
{
    keyboard.process();
}

class KeyEventHandler : public KeyEventReceiver {
public:


    bool take(KeyEvent e) override {
        serial.print("KeyEventHandler::take: key=");
        Serial.print(std::underlying_type<KeyEvent::Key>::type(e.key));
        Serial.print(" type=");
        Serial.print(std::underlying_type<KeyEvent::Type>::type(e.type));
        Serial.print(" repeated=");
        Serial.println(e.repeated);*/

        bool consumed = false;

        if (!consumed && e.type == KeyEvent::Type::Pressed) {
            switch (e.key) {
                case KeyEvent::Key::Key0:
                        consumed = true;
                        Serial.println("KeyEventHandler::take: Key0 pressed");
                    break;
                case KeyEvent::Key::Key1:
                case KeyEvent::Key::Key2:
                case KeyEvent::Key::Key3:
                case KeyEvent::Key::Key4:
                case KeyEvent::Key::Key5:
                case KeyEvent::Key::Key6:
                case KeyEvent::Key::Key7:
                case KeyEvent::Key::Key8:
                case KeyEvent::Key::Key9:
                case KeyEvent::Key::Key10:
                case KeyEvent::Key::Key11:
                    break;
                case KeyEvent::Key::None:
                case KeyEvent::Key::LastEnumeration:
                    break;
            }
        }

        else if (!consumed && e.type == KeyEvent::Type::Repeated) {
            const uint8_t long_press = 8;
            const uint8_t extra_long_press = 2 * long_press;
            
            switch (e.key) {
                case KeyEvent::Key::Key0:
                    if (e.repeated >= extra_long_press) {
                        consumed = true;
                        Serial.println("KeyEventHandler::take: Key0 long pressed");
                    }
                    break;
                case KeyEvent::Key::Key1:
                case KeyEvent::Key::Key2:
                case KeyEvent::Key::Key3:
                case KeyEvent::Key::Key4:
                case KeyEvent::Key::Key5:
                case KeyEvent::Key::Key6:
                case KeyEvent::Key::Key7:
                case KeyEvent::Key::Key8:
                case KeyEvent::Key::Key9:
                case KeyEvent::Key::Key10:
                case KeyEvent::Key::Key11:
                    break;
                case KeyEvent::Key::None:
                case KeyEvent::Key::LastEnumeration:
                    break;
        }
        else if (!consumed && e.type == KeyEvent::Type::Released) {
          // ...
        }

        return consumed;
    }
};
