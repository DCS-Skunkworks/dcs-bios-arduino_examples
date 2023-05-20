#include <Keyboard.h>

unsigned int ctrlKey = KEY_LEFT_CTRL;
unsigned int shiftKey = KEY_LEFT_SHIFT;
unsigned int altKey = KEY_LEFT_ALT;

#define NUM_BTNS 9

int _keyStates[NUM_BTNS];

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(LED_BUILTIN_TX,INPUT);
  pinMode(LED_BUILTIN_RX,INPUT);

  memset(_keyStates, HIGH, NUM_BTNS);
}

bool IsRisingEdgePressed(int pin)
{
  bool result = false;
  
  int pinState = digitalRead(pin);
  if( pinState != _keyStates[pin] )
  {
    // State changed
    if( !pinState )
    {
      // Falling edge, i.e. key pressed
        result = true;
    }

    _keyStates[pin] = pinState;
  }

  return result;
}

void loop() {
  
 Keyboard.begin();
  
  if (IsRisingEdgePressed(2))// Back = Hardware Switch but need only 1 signal
  {
    Keyboard.press(ctrlKey);
    Keyboard.press('n');  
  }
  else if (IsRisingEdgePressed(3))   //FWD = Hardware Switch but need only 1 signal
  {
    Keyboard.press(ctrlKey);
    Keyboard.press('m');  
  }
  else if (IsRisingEdgePressed(4))   //Play = Hardware Switch but need only 1 signal
  {
    Keyboard.press(shiftKey);
    Keyboard.press('n');  
  }
  else if (IsRisingEdgePressed(5))   //Stop = button
  {
    Keyboard.press(shiftKey);
    Keyboard.press('m');
  }
  else if (IsRisingEdgePressed(6))   //BSide = Hardware Switch but need only 1 signal
  {
    Keyboard.press(altKey);
    Keyboard.press('n');
  }
  else if (IsRisingEdgePressed(7))   //VOL+ = button
  {
    Keyboard.press(ctrlKey);
    Keyboard.press('\337');
  }
  else if (IsRisingEdgePressed(8))   //VOL- = button
  {
    Keyboard.press(ctrlKey);
    Keyboard.press('\336');
  }

  delay(200);
  Keyboard.releaseAll();  
  Keyboard.end();                 //stops keybord
}
