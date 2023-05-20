
#define DCSBIOS_IRQ_SERIAL
#include <DcsBios.h>

int LEDBrightness = 30;

void onPltLightIntentConsoleChange(unsigned int newValue) {
    LEDBrightness = newValue * 31;
}
DcsBios::IntegerBuffer pltLightIntentConsoleBuffer(0x121e, 0xf000, 12, onPltLightIntentConsoleChange);

 DcsBios::Switch3Pos pltIcsFuncSel("PLT_ICS_FUNC_SEL", 4, 2);
 DcsBios::Switch3Pos pltIcsAmpSel("PLT_ICS_AMP_SEL", 7, 8);
 DcsBios::Potentiometer pltIcsVol("PLT_ICS_VOL", A7);
 DcsBios::Switch2Pos pltParkBrake("PLT_PARK_BRAKE", 12, true);
 DcsBios::SwitchWithCover2Pos pltLaunchbarAbort("PLT_LAUNCHBAR_ABORT", "PLT_LAUNCHBAR_ABORT_COVER", 6);

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  analogWrite(3, LEDBrightness);
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
