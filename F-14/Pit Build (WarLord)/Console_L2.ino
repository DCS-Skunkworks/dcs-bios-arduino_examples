
#define DCSBIOS_IRQ_SERIAL
#include <DcsBios.h>

int LEDBrightness = 10;

void onPltLightIntentConsoleChange(unsigned int newValue) {
    LEDBrightness = newValue * 31;
}
DcsBios::IntegerBuffer pltLightIntentConsoleBuffer(0x121e, 0xf000, 12, onPltLightIntentConsoleChange);

unsigned int FloodMap(unsigned int dcsValue)
{
    if( dcsValue == 0 )
        return 0;
    else if((dcsValue > 13000) & (dcsValue < 17000))
        return 128;
    else // if( dcsValue > 18000)
        return 255;
}
DcsBios::Dimmer internalFloodWhtL(0x14c0, 11, FloodMap);
DcsBios::Dimmer internalFloodRedL(0x14be, 6, FloodMap);
DcsBios::Switch2Pos pltEmergStoreJett("PLT_EMERG_STORE_JETT", 12);   
DcsBios::Potentiometer pltTacanVolume("PLT_TACAN_VOLUME", A7);

const byte pltTacanDialTensPins[13] = {2, 3, 4, 7, 8, 9, 10, 14, 15, 16, 17, 18, 19};
DcsBios::SwitchMultiPos pltTacanDialTens("PLT_TACAN_DIAL_TENS", pltTacanDialTensPins, 13);

void setup() {
  pinMode(5, OUTPUT);
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  analogWrite(5, LEDBrightness);
}

unsigned long uLastModelTimeS = 0xFFFFFFFF; // Start big, to ensure the first step triggers a resync

void onModTimeChange(char* newValue) {
  unsigned long currentModelTimeS = atol(newValue);

  if( currentModelTimeS < uLastModelTimeS )
  {
    if( currentModelTimeS > 20 )// Delay to give time for DCS to finish loading and become stable and responsive
    {
      DcsBios::resetAllStates();
      uLastModelTimeS = currentModelTimeS;
    }
  }
  else
  {
    uLastModelTimeS = currentModelTimeS;
  }
}
DcsBios::StringBuffer<5> modTimeBuffer(0x043e, onModTimeChange);
