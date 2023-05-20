/*
  The following #define tells DCS-BIOS that this is a RS-485 slave device.
  It also sets the address of this slave device. The slave address should be
  between 1 and 126 and must be unique among all devices on the same bus.
*/
#define DCSBIOS_RS485_SLAVE 26

/*
  The Arduino pin that is connected to the
  /RE and DE pins on the RS-485 transceiver.
*/
#define TXENABLE_PIN 2

#include "DcsBios.h"
#include <timer.h>
Timer tm;

// set pin numbers:
const int Freq1_3 = 57;
const int Freq1_4 = 58;
const int Freq1_5 = 59;
const int Freq1_6 = 60;
const int Freq1_7 = 61;
const int Freq1_8 = 62;
const int Freq1_10 = 63;
const int Freq1_11 = 64;
const int Freq1_12 = 65;
const int Freq1_13 = 66;
const int Freq1_14 = 67;
const int Freq1_15 = 68;

const int Freq2_1 = 35;
const int Freq2_2 = 36;
const int Freq2_3 = 37;
const int Freq2_4 = 38;
const int Freq2_5 = 39;
const int Freq2_6 = 40;
const int Freq2_7 = 41;
const int Freq2_8 = 42;
const int Freq2_9 = 43;

const int Freq3_1 = 12;
const int Freq3_2 = 11;
const int Freq3_3 = 10;
const int Freq3_4 = 9;
const int Freq3_5 = 8;
const int Freq3_6 = 7;
const int Freq3_7 = 6;
const int Freq3_8 = 5;
const int Freq3_9 = 4;

const int Freq4_00 = 53;
const int Freq4_50 = 52;
const int Freq4_75 = 51;

const int Mode_1 = 56;
const int Mode_2 = 55;

//Variables
int Freq1_DCS = 9;  //Initial value set for 12
int Freq2_DCS = 0;  //Initial value set for 0
int Freq3_DCS = 0;  //Initial value set for 0
int Freq4_DCS = 0;  //Initial value set for .00
int Mode_DCS = 0;   //Initial value set for OFF
int Preset_DCS = 0; //Initial value set for 1

/* paste code snippets from the reference documentation here */
//Frequency selecto1 1  
void onVhfamFreq1Change(unsigned int newValue) {
   Freq1_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamFreq1Buffer(0x118e, 0x000f, 0, onVhfamFreq1Change);

//Frequency selector 2
void onVhfamFreq2Change(unsigned int newValue) {
   Freq2_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamFreq2Buffer(0x118e, 0x00f0, 4, onVhfamFreq2Change);

//Frequency selector 3
void onVhfamFreq3Change(unsigned int newValue) {
   Freq3_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamFreq3Buffer(0x118e, 0x0f00, 8, onVhfamFreq3Change);

//Frequency selector 4
void onVhfamFreq4Change(unsigned int newValue) {
   Freq4_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamFreq4Buffer(0x118e, 0x7000, 12, onVhfamFreq4Change);

//Frequency Selection Dial FM/AM/MAN/PRE
const byte vhfamFreqemerPins[4] = {50, 49, 48, 47};
DcsBios::SwitchMultiPos vhfamFreqemer("VHFAM_FREQEMER", vhfamFreqemerPins, 4);

//Mode dial
void onVhfamModeChange(unsigned int newValue) {
 Mode_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamModeBuffer(0x1186, 0x0300, 8, onVhfamModeChange);

//Load Button
DcsBios::Switch2Pos vhfamLoad("VHFAM_LOAD", 46);

//Squelch
DcsBios::Switch3Pos vhfamSquelch("VHFAM_SQUELCH", 45, 44);

//VHF FM Volume Control
DcsBios::Potentiometer vhfamVol("VHFAM_VOL", A0);

//VHF FM Preset
void onVhfamPresetChange(unsigned int newValue) {
 Preset_DCS = newValue;
}
DcsBios::IntegerBuffer vhfamPresetBuffer(0x117c, 0xf800, 11, onVhfamPresetChange);

//Master caution lamp - coms test
DcsBios::LED masterCaution(0x1012, 0x0800, 13);

void setup() {
  DcsBios::setup();
  //Preset inputs
  DDRA = B00000000; // set PINA (digital 29-22) as inputs
  PORTA = B11111111; // Sets (digital 29-22) with internal pull up


  //Inputs
  pinMode(Freq1_3, INPUT_PULLUP);
  pinMode(Freq1_4, INPUT_PULLUP);
  pinMode(Freq1_4, INPUT_PULLUP);
  pinMode(Freq1_6, INPUT_PULLUP);
  pinMode(Freq1_7, INPUT_PULLUP);
  pinMode(Freq1_8, INPUT_PULLUP);
  pinMode(Freq1_10, INPUT_PULLUP);
  pinMode(Freq1_11, INPUT_PULLUP);
  pinMode(Freq1_12, INPUT_PULLUP);
  pinMode(Freq1_13, INPUT_PULLUP);
  pinMode(Freq1_14, INPUT_PULLUP);
  pinMode(Freq1_15, INPUT_PULLUP);

  pinMode(Freq2_1, INPUT_PULLUP);
  pinMode(Freq2_2, INPUT_PULLUP);
  pinMode(Freq2_3, INPUT_PULLUP);
  pinMode(Freq2_4, INPUT_PULLUP);
  pinMode(Freq2_5, INPUT_PULLUP);
  pinMode(Freq2_6, INPUT_PULLUP);
  pinMode(Freq2_7, INPUT_PULLUP);
  pinMode(Freq2_8, INPUT_PULLUP);
  pinMode(Freq2_9, INPUT_PULLUP);

  pinMode(Freq3_1, INPUT_PULLUP);
  pinMode(Freq3_2, INPUT_PULLUP);
  pinMode(Freq3_3, INPUT_PULLUP);
  pinMode(Freq3_4, INPUT_PULLUP);
  pinMode(Freq3_5, INPUT_PULLUP);
  pinMode(Freq3_6, INPUT_PULLUP);
  pinMode(Freq3_7, INPUT_PULLUP);
  pinMode(Freq3_8, INPUT_PULLUP);
  pinMode(Freq3_9, INPUT_PULLUP);

  pinMode(Freq4_00, INPUT_PULLUP);
  pinMode(Freq4_50, INPUT_PULLUP);
  pinMode(Freq4_75, INPUT_PULLUP);

  pinMode(Mode_1, INPUT_PULLUP);
  pinMode(Mode_2, INPUT_PULLUP);

  tm.startTimer(200, setVHF);
}

int inputFreq1()
{
  int valueFreq1;
  if (digitalRead(Freq1_3) == LOW) {  ///OBS!
    valueFreq1 = 0;
  }
  else if (digitalRead(Freq1_4) == LOW) { //OBS!
    valueFreq1 = 1;
  }
  else if (digitalRead(Freq1_5) == LOW) {  //OBS!
    valueFreq1 = 2;
  }
  if (digitalRead(Freq1_6) == LOW) {
    valueFreq1 = 3;
  }
  if (digitalRead(Freq1_7) == LOW) {
    valueFreq1 = 4;
  }
  if (digitalRead(Freq1_8) == LOW) {
    valueFreq1 = 5;
  }
  if (digitalRead(Freq1_10) == LOW) {
    valueFreq1 = 7;
  }
  if (digitalRead(Freq1_11) == LOW) {
    valueFreq1 = 8;
  }
  if (digitalRead(Freq1_12) == LOW) {
    valueFreq1 = 9;
  }
  if (digitalRead(Freq1_13) == LOW) {
    valueFreq1 = 10;
  }
  if (digitalRead(Freq1_14) == LOW) {
    valueFreq1 = 11;
  }
  if (digitalRead(Freq1_15) == LOW) {
    valueFreq1 = 12;
  }
  return valueFreq1;
}


int inputFreq2()
{
  int valueFreq2;
  if (digitalRead(Freq2_1) == LOW) {
    valueFreq2 = 1;
  }
  else if (digitalRead(Freq2_2) == LOW) {
    valueFreq2 = 2;
  }
  else if (digitalRead(Freq2_3) == LOW) {
    valueFreq2 = 3;
  }
  else if (digitalRead(Freq2_4) == LOW) {
    valueFreq2 = 4;
  }
  else if (digitalRead(Freq2_5) == LOW) {
    valueFreq2 = 5;
  }
  else if (digitalRead(Freq2_6) == LOW) {
    valueFreq2 = 6;
  }
  else if (digitalRead(Freq2_7) == LOW) {
    valueFreq2 = 7;
  }
  else if (digitalRead(Freq2_8) == LOW) {
    valueFreq2 = 8;
  }
  else if (digitalRead(Freq2_9) == LOW) {
    valueFreq2 = 9;
  }
  else {
    valueFreq2 = 0;
  }
  return valueFreq2;
}

int inputFreq3()
{
  int valueFreq3;
  if (digitalRead(Freq3_1) == LOW) {
    valueFreq3 = 1;
  }
  else if (digitalRead(Freq3_2) == LOW) {
    valueFreq3 = 2;
  }
  else if (digitalRead(Freq3_3) == LOW) {
    valueFreq3 = 3;
  }
  else if (digitalRead(Freq3_4) == LOW) {
    valueFreq3 = 4;
  }
  else if (digitalRead(Freq3_5) == LOW) {
    valueFreq3 = 5;
  }
  else if (digitalRead(Freq3_6) == LOW) {
    valueFreq3 = 6;
  }
  else if (digitalRead(Freq3_7) == LOW) {
    valueFreq3 = 7;
  }
  else if (digitalRead(Freq3_8) == LOW) {
    valueFreq3 = 8;
  }
  else if (digitalRead(Freq3_9) == LOW) {
    valueFreq3 = 9;
  }
  else {
    valueFreq3 = 0;
  }
  return valueFreq3;
}

int inputFreq4()
{
  int valueFreq4;
  if (digitalRead(Freq4_00) == LOW) {
    valueFreq4 = 0;
  }
  else if (digitalRead(Freq4_50) == LOW) {
    valueFreq4 = 2;
  }
  else if (digitalRead(Freq4_75) == LOW) {
    valueFreq4 = 3;
  }
  else {
    valueFreq4 = 1;
  }
  return valueFreq4;
}

int inputMode()
{
  int valueMode;
  if (digitalRead(Mode_1) == HIGH && digitalRead(Mode_2) == HIGH) {
    valueMode = 0;
  }
  else if (digitalRead(Mode_1) == LOW && digitalRead(Mode_2) == HIGH) {
    valueMode = 1;
  }
  else if (digitalRead(Mode_1) == LOW && digitalRead(Mode_2) == LOW){
    valueMode = 2;
  }
  return valueMode;
}

int inputPreset()
{
  int valuePreset;
  if (PINA == B11111110) {
    valuePreset = 0;
  }
  if (PINA == B11111101) {
    valuePreset = 1;
  }
  if (PINA == B11111100) {
    valuePreset = 2;
  }
  if (PINA == B11101111) {
    valuePreset = 3;
  }
  if (PINA == B11101110) {
    valuePreset = 4;
  }
  if (PINA == B11101101) {
    valuePreset = 5;
  }
  if (PINA == B11101100) {
    valuePreset = 6;
  }
  if (PINA == B11011111) {
    valuePreset = 7;
  }
  if (PINA == B11011110) {
    valuePreset = 8;
  }
  if (PINA == B11111011) {
    valuePreset = 9;
  }
  if (PINA == B11111010) {
    valuePreset = 10;
  }
  if (PINA == B11111001) {
    valuePreset = 11;
  }
  if (PINA == B11111000) {
    valuePreset = 12;
  }
  if (PINA == B11101011) {
    valuePreset = 13;
  }
  if (PINA == B11101010) {
    valuePreset = 14;
  }
  if (PINA == B11101001) {
    valuePreset = 15;
  }
  if (PINA == B11101000) {
    valuePreset = 16;
  }
  if (PINA == B11011011) {
    valuePreset = 17;
  }
  if (PINA == B11011010) {
    valuePreset = 18;
  }
  if (PINA == B11110111) {
    valuePreset = 19;
  }
  return valuePreset;
}

void loop() {
  DcsBios::loop();
  tm.runTimers();

}

void setVHF(int timer){
//Adjust frequency selector #1
    if (Freq1_DCS < inputFreq1()) {
    sendDcsBiosMessage("VHFAM_FREQ1", "INC");
  }

  if (Freq1_DCS > inputFreq1()) {
    sendDcsBiosMessage("VHFAM_FREQ1", "DEC");
 }

//Adjust frequency selector #2
  if (Freq2_DCS < inputFreq2()) {
    sendDcsBiosMessage("VHFAM_FREQ2", "INC");
  }

  if (Freq2_DCS > inputFreq2()) {
    sendDcsBiosMessage("VHFAM_FREQ2", "DEC");
  }

//Adjust frequency selector #3
  if (Freq3_DCS < inputFreq3()) {
    sendDcsBiosMessage("VHFAM_FREQ3", "INC");
  }

  if (Freq3_DCS > inputFreq3()) {
    sendDcsBiosMessage("VHFAM_FREQ3", "DEC");
  }

//Adjust frequency selector #4
  if (Freq4_DCS < inputFreq4()) {
    sendDcsBiosMessage("VHFAM_FREQ4", "INC");
  }

  if (Freq4_DCS > inputFreq4()) {
    sendDcsBiosMessage("VHFAM_FREQ4", "DEC");
  }

//Adjust Mode
  if (Mode_DCS < inputMode()) {
    sendDcsBiosMessage("VHFAM_MODE", "INC");
  }

  if (Mode_DCS > inputMode()) {
    sendDcsBiosMessage("VHFAM_MODE", "DEC");
  }

//Adjust Prestes
  if (Preset_DCS < inputPreset()) {
    sendDcsBiosMessage("VHFAM_PRESET", "INC");
  }

  if (Preset_DCS > inputPreset()) {
    sendDcsBiosMessage("VHFAM_PRESET", "DEC");
  }

}


