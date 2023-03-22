#include <Keypad.h>

#ifndef Keyboard_h
#define Keyboard_h
#define PIN_KEY_1 32
#define PIN_KEY_2 33
#define PIN_KEY_3 34
#define PIN_KEY_4 35
#define PIN_KEY_5 36
#define PIN_KEY_6 37
#define PIN_KEY_7 38

class Keyboard
{
  private:

    const byte ROWS = 4;
    const byte COLS = 3;

    char hexaKeys[4][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};

    byte rowPins[4] = {PIN_KEY_7, PIN_KEY_6, PIN_KEY_5, PIN_KEY_4};
    byte colPins[3] = {PIN_KEY_3, PIN_KEY_2, PIN_KEY_1};

    Keypad customKeypad;

  public:
    Keyboard() : customKeypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS){}

    char getKey()
    {
      return customKeypad.getKey();
    }
};

#endif /*Keyboard_h*/