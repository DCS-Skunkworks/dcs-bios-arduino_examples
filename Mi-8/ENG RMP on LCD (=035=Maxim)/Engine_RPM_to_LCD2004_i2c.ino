/* use '#define DCSBIOS_DEFAULT_SERIAL' instead if your Arduino board
 *  does not feature an ATMega328 or ATMega2650 controller.
 */
#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,20,4);  // LCD address, character numbers, row numbers

//обороты винта
void onRotorrpmChange(unsigned int newValue) {
    /* your code here */

    char firstDigit;
    char secondDigit;
    char thirdDigit;

    if (newValue < 595.77){firstDigit=' '; secondDigit=' '; thirdDigit='0';}
else if (newValue >=595.77 && newValue <1191.55){firstDigit=' '; secondDigit=' '; thirdDigit='1';}
else if (newValue >=1191.55 && newValue <1787.32){firstDigit=' '; secondDigit=' '; thirdDigit='2';}
else if (newValue >=1787.32 && newValue <2383.09){firstDigit=' '; secondDigit=' '; thirdDigit='3';}
else if (newValue >=2383.09 && newValue <2978.86){firstDigit=' '; secondDigit=' '; thirdDigit='4';}
else if (newValue >=2978.86 && newValue <3574.64){firstDigit=' '; secondDigit=' '; thirdDigit='5';}
else if (newValue >=3574.64 && newValue <4170.41){firstDigit=' '; secondDigit=' '; thirdDigit='6';}
else if (newValue >=4170.41 && newValue <4766.18){firstDigit=' '; secondDigit=' '; thirdDigit='7';}
else if (newValue >=4766.18 && newValue <5361.95){firstDigit=' '; secondDigit=' '; thirdDigit='8';}
else if (newValue >=5361.95 && newValue <5957.73){firstDigit=' '; secondDigit=' '; thirdDigit='9';}
else if (newValue >=5957.73 && newValue <6553.50){firstDigit=' '; secondDigit='1'; thirdDigit='0';}
else if (newValue >=6553.50 && newValue <7149.27){firstDigit=' '; secondDigit='1'; thirdDigit='1';}
else if (newValue >=7149.27 && newValue <7745.05){firstDigit=' '; secondDigit='1'; thirdDigit='2';}
else if (newValue >=7745.05 && newValue <8340.82){firstDigit=' '; secondDigit='1'; thirdDigit='3';}
else if (newValue >=8340.82 && newValue <8936.59){firstDigit=' '; secondDigit='1'; thirdDigit='4';}
else if (newValue >=8936.59 && newValue <9532.36){firstDigit=' '; secondDigit='1'; thirdDigit='5';}
else if (newValue >=9532.36 && newValue <10128.14){firstDigit=' '; secondDigit='1'; thirdDigit='6';}
else if (newValue >=10128.14 && newValue <10723.91){firstDigit=' '; secondDigit='1'; thirdDigit='7';}
else if (newValue >=10723.91 && newValue <11319.68){firstDigit=' '; secondDigit='1'; thirdDigit='8';}
else if (newValue >=11319.68 && newValue <11915.45){firstDigit=' '; secondDigit='1'; thirdDigit='9';}
else if (newValue >=11915.45 && newValue <12511.23){firstDigit=' '; secondDigit='2'; thirdDigit='0';}
else if (newValue >=12511.23 && newValue <13107.00){firstDigit=' '; secondDigit='2'; thirdDigit='1';}
else if (newValue >=13107.00 && newValue <13702.77){firstDigit=' '; secondDigit='2'; thirdDigit='2';}
else if (newValue >=13702.77 && newValue <14298.55){firstDigit=' '; secondDigit='2'; thirdDigit='3';}
else if (newValue >=14298.55 && newValue <14894.32){firstDigit=' '; secondDigit='2'; thirdDigit='4';}
else if (newValue >=14894.32 && newValue <15490.09){firstDigit=' '; secondDigit='2'; thirdDigit='5';}
else if (newValue >=15490.09 && newValue <16085.86){firstDigit=' '; secondDigit='2'; thirdDigit='6';}
else if (newValue >=16085.86 && newValue <16681.64){firstDigit=' '; secondDigit='2'; thirdDigit='7';}
else if (newValue >=16681.64 && newValue <17277.41){firstDigit=' '; secondDigit='2'; thirdDigit='8';}
else if (newValue >=17277.41 && newValue <17873.18){firstDigit=' '; secondDigit='2'; thirdDigit='9';}
else if (newValue >=17873.18 && newValue <18468.95){firstDigit=' '; secondDigit='3'; thirdDigit='0';}
else if (newValue >=18468.95 && newValue <19064.73){firstDigit=' '; secondDigit='3'; thirdDigit='1';}
else if (newValue >=19064.73 && newValue <19660.50){firstDigit=' '; secondDigit='3'; thirdDigit='2';}
else if (newValue >=19660.50 && newValue <20256.27){firstDigit=' '; secondDigit='3'; thirdDigit='3';}
else if (newValue >=20256.27 && newValue <20852.05){firstDigit=' '; secondDigit='3'; thirdDigit='4';}
else if (newValue >=20852.05 && newValue <21447.82){firstDigit=' '; secondDigit='3'; thirdDigit='5';}
else if (newValue >=21447.82 && newValue <22043.59){firstDigit=' '; secondDigit='3'; thirdDigit='6';}
else if (newValue >=22043.59 && newValue <22639.36){firstDigit=' '; secondDigit='3'; thirdDigit='7';}
else if (newValue >=22639.36 && newValue <23235.14){firstDigit=' '; secondDigit='3'; thirdDigit='8';}
else if (newValue >=23235.14 && newValue <23830.91){firstDigit=' '; secondDigit='3'; thirdDigit='9';}
else if (newValue >=23830.91 && newValue <24426.68){firstDigit=' '; secondDigit='4'; thirdDigit='0';}
else if (newValue >=24426.68 && newValue <25022.45){firstDigit=' '; secondDigit='4'; thirdDigit='1';}
else if (newValue >=25022.45 && newValue <25618.23){firstDigit=' '; secondDigit='4'; thirdDigit='2';}
else if (newValue >=25618.23 && newValue <26214.00){firstDigit=' '; secondDigit='4'; thirdDigit='3';}
else if (newValue >=26214.00 && newValue <26809.77){firstDigit=' '; secondDigit='4'; thirdDigit='4';}
else if (newValue >=26809.77 && newValue <27405.55){firstDigit=' '; secondDigit='4'; thirdDigit='5';}
else if (newValue >=27405.55 && newValue <28001.32){firstDigit=' '; secondDigit='4'; thirdDigit='6';}
else if (newValue >=28001.32 && newValue <28597.09){firstDigit=' '; secondDigit='4'; thirdDigit='7';}
else if (newValue >=28597.09 && newValue <29192.86){firstDigit=' '; secondDigit='4'; thirdDigit='8';}
else if (newValue >=29192.86 && newValue <29788.64){firstDigit=' '; secondDigit='4'; thirdDigit='9';}
else if (newValue >=29788.64 && newValue <30384.41){firstDigit=' '; secondDigit='5'; thirdDigit='0';}
else if (newValue >=30384.41 && newValue <30980.18){firstDigit=' '; secondDigit='5'; thirdDigit='1';}
else if (newValue >=30980.18 && newValue <31575.95){firstDigit=' '; secondDigit='5'; thirdDigit='2';}
else if (newValue >=31575.95 && newValue <32171.73){firstDigit=' '; secondDigit='5'; thirdDigit='3';}
else if (newValue >=32171.73 && newValue <32767.50){firstDigit=' '; secondDigit='5'; thirdDigit='4';}
else if (newValue >=32767.50 && newValue <33363.27){firstDigit=' '; secondDigit='5'; thirdDigit='5';}
else if (newValue >=33363.27 && newValue <33959.05){firstDigit=' '; secondDigit='5'; thirdDigit='6';}
else if (newValue >=33959.05 && newValue <34554.82){firstDigit=' '; secondDigit='5'; thirdDigit='7';}
else if (newValue >=34554.82 && newValue <35150.59){firstDigit=' '; secondDigit='5'; thirdDigit='8';}
else if (newValue >=35150.59 && newValue <35746.36){firstDigit=' '; secondDigit='5'; thirdDigit='9';}
else if (newValue >=35746.36 && newValue <36342.14){firstDigit=' '; secondDigit='6'; thirdDigit='0';}
else if (newValue >=36342.14 && newValue <36937.91){firstDigit=' '; secondDigit='6'; thirdDigit='1';}
else if (newValue >=36937.91 && newValue <37533.68){firstDigit=' '; secondDigit='6'; thirdDigit='2';}
else if (newValue >=37533.68 && newValue <38129.45){firstDigit=' '; secondDigit='6'; thirdDigit='3';}
else if (newValue >=38129.45 && newValue <38725.23){firstDigit=' '; secondDigit='6'; thirdDigit='4';}
else if (newValue >=38725.23 && newValue <39321.00){firstDigit=' '; secondDigit='6'; thirdDigit='5';}
else if (newValue >=39321.00 && newValue <39916.77){firstDigit=' '; secondDigit='6'; thirdDigit='6';}
else if (newValue >=39916.77 && newValue <40512.55){firstDigit=' '; secondDigit='6'; thirdDigit='7';}
else if (newValue >=40512.55 && newValue <41108.32){firstDigit=' '; secondDigit='6'; thirdDigit='8';}
else if (newValue >=41108.32 && newValue <41704.09){firstDigit=' '; secondDigit='6'; thirdDigit='9';}
else if (newValue >=41704.09 && newValue <42299.86){firstDigit=' '; secondDigit='7'; thirdDigit='0';}
else if (newValue >=42299.86 && newValue <42895.64){firstDigit=' '; secondDigit='7'; thirdDigit='1';}
else if (newValue >=42895.64 && newValue <43491.41){firstDigit=' '; secondDigit='7'; thirdDigit='2';}
else if (newValue >=43491.41 && newValue <44087.18){firstDigit=' '; secondDigit='7'; thirdDigit='3';}
else if (newValue >=44087.18 && newValue <44682.95){firstDigit=' '; secondDigit='7'; thirdDigit='4';}
else if (newValue >=44682.95 && newValue <45278.73){firstDigit=' '; secondDigit='7'; thirdDigit='5';}
else if (newValue >=45278.73 && newValue <45874.50){firstDigit=' '; secondDigit='7'; thirdDigit='6';}
else if (newValue >=45874.50 && newValue <46470.27){firstDigit=' '; secondDigit='7'; thirdDigit='7';}
else if (newValue >=46470.27 && newValue <47066.05){firstDigit=' '; secondDigit='7'; thirdDigit='8';}
else if (newValue >=47066.05 && newValue <47661.82){firstDigit=' '; secondDigit='7'; thirdDigit='9';}
else if (newValue >=47661.82 && newValue <48257.59){firstDigit=' '; secondDigit='8'; thirdDigit='0';}
else if (newValue >=48257.59 && newValue <48853.36){firstDigit=' '; secondDigit='8'; thirdDigit='1';}
else if (newValue >=48853.36 && newValue <49449.14){firstDigit=' '; secondDigit='8'; thirdDigit='2';}
else if (newValue >=49449.14 && newValue <50044.91){firstDigit=' '; secondDigit='8'; thirdDigit='3';}
else if (newValue >=50044.91 && newValue <50640.68){firstDigit=' '; secondDigit='8'; thirdDigit='4';}
else if (newValue >=50640.68 && newValue <51236.45){firstDigit=' '; secondDigit='8'; thirdDigit='5';}
else if (newValue >=51236.45 && newValue <51832.23){firstDigit=' '; secondDigit='8'; thirdDigit='6';}
else if (newValue >=51832.23 && newValue <52428.00){firstDigit=' '; secondDigit='8'; thirdDigit='7';}
else if (newValue >=52428.00 && newValue <53023.77){firstDigit=' '; secondDigit='8'; thirdDigit='8';}
else if (newValue >=53023.77 && newValue <53619.55){firstDigit=' '; secondDigit='8'; thirdDigit='9';}
else if (newValue >=53619.55 && newValue <54215.32){firstDigit=' '; secondDigit='9'; thirdDigit='0';}
else if (newValue >=54215.32 && newValue <54811.09){firstDigit=' '; secondDigit='9'; thirdDigit='1';}
else if (newValue >=54811.09 && newValue <55406.86){firstDigit=' '; secondDigit='9'; thirdDigit='2';}
else if (newValue >=55406.86 && newValue <56002.64){firstDigit=' '; secondDigit='9'; thirdDigit='3';}
else if (newValue >=56002.64 && newValue <56598.41){firstDigit=' '; secondDigit='9'; thirdDigit='4';}
else if (newValue >=56598.41 && newValue <57194.18){firstDigit=' '; secondDigit='9'; thirdDigit='5';}
else if (newValue >=57194.18 && newValue <57789.95){firstDigit=' '; secondDigit='9'; thirdDigit='6';}
else if (newValue >=57789.95 && newValue <58385.73){firstDigit=' '; secondDigit='9'; thirdDigit='7';}
else if (newValue >=58385.73 && newValue <58981.50){firstDigit=' '; secondDigit='9'; thirdDigit='8';}
else if (newValue >=58981.50 && newValue <59577.27){firstDigit=' '; secondDigit='9'; thirdDigit='9';}
else if (newValue >=59577.27 && newValue <60173.05){firstDigit='1'; secondDigit='0'; thirdDigit='0';}
else if (newValue >=60173.05 && newValue <60768.82){firstDigit='1'; secondDigit='0'; thirdDigit='1';}
else if (newValue >=60768.82 && newValue <61364.59){firstDigit='1'; secondDigit='0'; thirdDigit='2';}
else if (newValue >=61364.59 && newValue <61960.36){firstDigit='1'; secondDigit='0'; thirdDigit='3';}
else if (newValue >=61960.36 && newValue <62556.14){firstDigit='1'; secondDigit='0'; thirdDigit='4';}
else if (newValue >=62556.14 && newValue <63151.91){firstDigit='1'; secondDigit='0'; thirdDigit='5';}
else if (newValue >=63151.91 && newValue <63747.68){firstDigit='1'; secondDigit='0'; thirdDigit='6';}
else if (newValue >=63747.68 && newValue <64343.45){firstDigit='1'; secondDigit='0'; thirdDigit='7';}
else if (newValue >=64343.45 && newValue <64939.23){firstDigit='1'; secondDigit='0'; thirdDigit='8';}
else if (newValue >=64939.23 && newValue <65535.00){firstDigit='1'; secondDigit='0'; thirdDigit='9';}
else if (newValue >=65535.00){firstDigit='1'; secondDigit='1'; thirdDigit='0';}


lcd.setCursor(14,0);
lcd.print (firstDigit);
lcd.print (secondDigit);
lcd.print (thirdDigit);


}
DcsBios::IntegerBuffer rotorrpmBuffer(0x270e, 0xffff, 0, onRotorrpmChange);


//обороты левого двигателя
void onLeftenginerpmChange(unsigned int newValue) {
    /* your code here */
    char firstDigit;
    char secondDigit;
    char thirdDigit;

    if (newValue < 595.77){firstDigit=' '; secondDigit=' '; thirdDigit='0';}
else if (newValue >=595.77 && newValue <1191.55){firstDigit=' '; secondDigit=' '; thirdDigit='1';}
else if (newValue >=1191.55 && newValue <1787.32){firstDigit=' '; secondDigit=' '; thirdDigit='2';}
else if (newValue >=1787.32 && newValue <2383.09){firstDigit=' '; secondDigit=' '; thirdDigit='3';}
else if (newValue >=2383.09 && newValue <2978.86){firstDigit=' '; secondDigit=' '; thirdDigit='4';}
else if (newValue >=2978.86 && newValue <3574.64){firstDigit=' '; secondDigit=' '; thirdDigit='5';}
else if (newValue >=3574.64 && newValue <4170.41){firstDigit=' '; secondDigit=' '; thirdDigit='6';}
else if (newValue >=4170.41 && newValue <4766.18){firstDigit=' '; secondDigit=' '; thirdDigit='7';}
else if (newValue >=4766.18 && newValue <5361.95){firstDigit=' '; secondDigit=' '; thirdDigit='8';}
else if (newValue >=5361.95 && newValue <5957.73){firstDigit=' '; secondDigit=' '; thirdDigit='9';}
else if (newValue >=5957.73 && newValue <6553.50){firstDigit=' '; secondDigit='1'; thirdDigit='0';}
else if (newValue >=6553.50 && newValue <7149.27){firstDigit=' '; secondDigit='1'; thirdDigit='1';}
else if (newValue >=7149.27 && newValue <7745.05){firstDigit=' '; secondDigit='1'; thirdDigit='2';}
else if (newValue >=7745.05 && newValue <8340.82){firstDigit=' '; secondDigit='1'; thirdDigit='3';}
else if (newValue >=8340.82 && newValue <8936.59){firstDigit=' '; secondDigit='1'; thirdDigit='4';}
else if (newValue >=8936.59 && newValue <9532.36){firstDigit=' '; secondDigit='1'; thirdDigit='5';}
else if (newValue >=9532.36 && newValue <10128.14){firstDigit=' '; secondDigit='1'; thirdDigit='6';}
else if (newValue >=10128.14 && newValue <10723.91){firstDigit=' '; secondDigit='1'; thirdDigit='7';}
else if (newValue >=10723.91 && newValue <11319.68){firstDigit=' '; secondDigit='1'; thirdDigit='8';}
else if (newValue >=11319.68 && newValue <11915.45){firstDigit=' '; secondDigit='1'; thirdDigit='9';}
else if (newValue >=11915.45 && newValue <12511.23){firstDigit=' '; secondDigit='2'; thirdDigit='0';}
else if (newValue >=12511.23 && newValue <13107.00){firstDigit=' '; secondDigit='2'; thirdDigit='1';}
else if (newValue >=13107.00 && newValue <13702.77){firstDigit=' '; secondDigit='2'; thirdDigit='2';}
else if (newValue >=13702.77 && newValue <14298.55){firstDigit=' '; secondDigit='2'; thirdDigit='3';}
else if (newValue >=14298.55 && newValue <14894.32){firstDigit=' '; secondDigit='2'; thirdDigit='4';}
else if (newValue >=14894.32 && newValue <15490.09){firstDigit=' '; secondDigit='2'; thirdDigit='5';}
else if (newValue >=15490.09 && newValue <16085.86){firstDigit=' '; secondDigit='2'; thirdDigit='6';}
else if (newValue >=16085.86 && newValue <16681.64){firstDigit=' '; secondDigit='2'; thirdDigit='7';}
else if (newValue >=16681.64 && newValue <17277.41){firstDigit=' '; secondDigit='2'; thirdDigit='8';}
else if (newValue >=17277.41 && newValue <17873.18){firstDigit=' '; secondDigit='2'; thirdDigit='9';}
else if (newValue >=17873.18 && newValue <18468.95){firstDigit=' '; secondDigit='3'; thirdDigit='0';}
else if (newValue >=18468.95 && newValue <19064.73){firstDigit=' '; secondDigit='3'; thirdDigit='1';}
else if (newValue >=19064.73 && newValue <19660.50){firstDigit=' '; secondDigit='3'; thirdDigit='2';}
else if (newValue >=19660.50 && newValue <20256.27){firstDigit=' '; secondDigit='3'; thirdDigit='3';}
else if (newValue >=20256.27 && newValue <20852.05){firstDigit=' '; secondDigit='3'; thirdDigit='4';}
else if (newValue >=20852.05 && newValue <21447.82){firstDigit=' '; secondDigit='3'; thirdDigit='5';}
else if (newValue >=21447.82 && newValue <22043.59){firstDigit=' '; secondDigit='3'; thirdDigit='6';}
else if (newValue >=22043.59 && newValue <22639.36){firstDigit=' '; secondDigit='3'; thirdDigit='7';}
else if (newValue >=22639.36 && newValue <23235.14){firstDigit=' '; secondDigit='3'; thirdDigit='8';}
else if (newValue >=23235.14 && newValue <23830.91){firstDigit=' '; secondDigit='3'; thirdDigit='9';}
else if (newValue >=23830.91 && newValue <24426.68){firstDigit=' '; secondDigit='4'; thirdDigit='0';}
else if (newValue >=24426.68 && newValue <25022.45){firstDigit=' '; secondDigit='4'; thirdDigit='1';}
else if (newValue >=25022.45 && newValue <25618.23){firstDigit=' '; secondDigit='4'; thirdDigit='2';}
else if (newValue >=25618.23 && newValue <26214.00){firstDigit=' '; secondDigit='4'; thirdDigit='3';}
else if (newValue >=26214.00 && newValue <26809.77){firstDigit=' '; secondDigit='4'; thirdDigit='4';}
else if (newValue >=26809.77 && newValue <27405.55){firstDigit=' '; secondDigit='4'; thirdDigit='5';}
else if (newValue >=27405.55 && newValue <28001.32){firstDigit=' '; secondDigit='4'; thirdDigit='6';}
else if (newValue >=28001.32 && newValue <28597.09){firstDigit=' '; secondDigit='4'; thirdDigit='7';}
else if (newValue >=28597.09 && newValue <29192.86){firstDigit=' '; secondDigit='4'; thirdDigit='8';}
else if (newValue >=29192.86 && newValue <29788.64){firstDigit=' '; secondDigit='4'; thirdDigit='9';}
else if (newValue >=29788.64 && newValue <30384.41){firstDigit=' '; secondDigit='5'; thirdDigit='0';}
else if (newValue >=30384.41 && newValue <30980.18){firstDigit=' '; secondDigit='5'; thirdDigit='1';}
else if (newValue >=30980.18 && newValue <31575.95){firstDigit=' '; secondDigit='5'; thirdDigit='2';}
else if (newValue >=31575.95 && newValue <32171.73){firstDigit=' '; secondDigit='5'; thirdDigit='3';}
else if (newValue >=32171.73 && newValue <32767.50){firstDigit=' '; secondDigit='5'; thirdDigit='4';}
else if (newValue >=32767.50 && newValue <33363.27){firstDigit=' '; secondDigit='5'; thirdDigit='5';}
else if (newValue >=33363.27 && newValue <33959.05){firstDigit=' '; secondDigit='5'; thirdDigit='6';}
else if (newValue >=33959.05 && newValue <34554.82){firstDigit=' '; secondDigit='5'; thirdDigit='7';}
else if (newValue >=34554.82 && newValue <35150.59){firstDigit=' '; secondDigit='5'; thirdDigit='8';}
else if (newValue >=35150.59 && newValue <35746.36){firstDigit=' '; secondDigit='5'; thirdDigit='9';}
else if (newValue >=35746.36 && newValue <36342.14){firstDigit=' '; secondDigit='6'; thirdDigit='0';}
else if (newValue >=36342.14 && newValue <36937.91){firstDigit=' '; secondDigit='6'; thirdDigit='1';}
else if (newValue >=36937.91 && newValue <37533.68){firstDigit=' '; secondDigit='6'; thirdDigit='2';}
else if (newValue >=37533.68 && newValue <38129.45){firstDigit=' '; secondDigit='6'; thirdDigit='3';}
else if (newValue >=38129.45 && newValue <38725.23){firstDigit=' '; secondDigit='6'; thirdDigit='4';}
else if (newValue >=38725.23 && newValue <39321.00){firstDigit=' '; secondDigit='6'; thirdDigit='5';}
else if (newValue >=39321.00 && newValue <39916.77){firstDigit=' '; secondDigit='6'; thirdDigit='6';}
else if (newValue >=39916.77 && newValue <40512.55){firstDigit=' '; secondDigit='6'; thirdDigit='7';}
else if (newValue >=40512.55 && newValue <41108.32){firstDigit=' '; secondDigit='6'; thirdDigit='8';}
else if (newValue >=41108.32 && newValue <41704.09){firstDigit=' '; secondDigit='6'; thirdDigit='9';}
else if (newValue >=41704.09 && newValue <42299.86){firstDigit=' '; secondDigit='7'; thirdDigit='0';}
else if (newValue >=42299.86 && newValue <42895.64){firstDigit=' '; secondDigit='7'; thirdDigit='1';}
else if (newValue >=42895.64 && newValue <43491.41){firstDigit=' '; secondDigit='7'; thirdDigit='2';}
else if (newValue >=43491.41 && newValue <44087.18){firstDigit=' '; secondDigit='7'; thirdDigit='3';}
else if (newValue >=44087.18 && newValue <44682.95){firstDigit=' '; secondDigit='7'; thirdDigit='4';}
else if (newValue >=44682.95 && newValue <45278.73){firstDigit=' '; secondDigit='7'; thirdDigit='5';}
else if (newValue >=45278.73 && newValue <45874.50){firstDigit=' '; secondDigit='7'; thirdDigit='6';}
else if (newValue >=45874.50 && newValue <46470.27){firstDigit=' '; secondDigit='7'; thirdDigit='7';}
else if (newValue >=46470.27 && newValue <47066.05){firstDigit=' '; secondDigit='7'; thirdDigit='8';}
else if (newValue >=47066.05 && newValue <47661.82){firstDigit=' '; secondDigit='7'; thirdDigit='9';}
else if (newValue >=47661.82 && newValue <48257.59){firstDigit=' '; secondDigit='8'; thirdDigit='0';}
else if (newValue >=48257.59 && newValue <48853.36){firstDigit=' '; secondDigit='8'; thirdDigit='1';}
else if (newValue >=48853.36 && newValue <49449.14){firstDigit=' '; secondDigit='8'; thirdDigit='2';}
else if (newValue >=49449.14 && newValue <50044.91){firstDigit=' '; secondDigit='8'; thirdDigit='3';}
else if (newValue >=50044.91 && newValue <50640.68){firstDigit=' '; secondDigit='8'; thirdDigit='4';}
else if (newValue >=50640.68 && newValue <51236.45){firstDigit=' '; secondDigit='8'; thirdDigit='5';}
else if (newValue >=51236.45 && newValue <51832.23){firstDigit=' '; secondDigit='8'; thirdDigit='6';}
else if (newValue >=51832.23 && newValue <52428.00){firstDigit=' '; secondDigit='8'; thirdDigit='7';}
else if (newValue >=52428.00 && newValue <53023.77){firstDigit=' '; secondDigit='8'; thirdDigit='8';}
else if (newValue >=53023.77 && newValue <53619.55){firstDigit=' '; secondDigit='8'; thirdDigit='9';}
else if (newValue >=53619.55 && newValue <54215.32){firstDigit=' '; secondDigit='9'; thirdDigit='0';}
else if (newValue >=54215.32 && newValue <54811.09){firstDigit=' '; secondDigit='9'; thirdDigit='1';}
else if (newValue >=54811.09 && newValue <55406.86){firstDigit=' '; secondDigit='9'; thirdDigit='2';}
else if (newValue >=55406.86 && newValue <56002.64){firstDigit=' '; secondDigit='9'; thirdDigit='3';}
else if (newValue >=56002.64 && newValue <56598.41){firstDigit=' '; secondDigit='9'; thirdDigit='4';}
else if (newValue >=56598.41 && newValue <57194.18){firstDigit=' '; secondDigit='9'; thirdDigit='5';}
else if (newValue >=57194.18 && newValue <57789.95){firstDigit=' '; secondDigit='9'; thirdDigit='6';}
else if (newValue >=57789.95 && newValue <58385.73){firstDigit=' '; secondDigit='9'; thirdDigit='7';}
else if (newValue >=58385.73 && newValue <58981.50){firstDigit=' '; secondDigit='9'; thirdDigit='8';}
else if (newValue >=58981.50 && newValue <59577.27){firstDigit=' '; secondDigit='9'; thirdDigit='9';}
else if (newValue >=59577.27 && newValue <60173.05){firstDigit='1'; secondDigit='0'; thirdDigit='0';}
else if (newValue >=60173.05 && newValue <60768.82){firstDigit='1'; secondDigit='0'; thirdDigit='1';}
else if (newValue >=60768.82 && newValue <61364.59){firstDigit='1'; secondDigit='0'; thirdDigit='2';}
else if (newValue >=61364.59 && newValue <61960.36){firstDigit='1'; secondDigit='0'; thirdDigit='3';}
else if (newValue >=61960.36 && newValue <62556.14){firstDigit='1'; secondDigit='0'; thirdDigit='4';}
else if (newValue >=62556.14 && newValue <63151.91){firstDigit='1'; secondDigit='0'; thirdDigit='5';}
else if (newValue >=63151.91 && newValue <63747.68){firstDigit='1'; secondDigit='0'; thirdDigit='6';}
else if (newValue >=63747.68 && newValue <64343.45){firstDigit='1'; secondDigit='0'; thirdDigit='7';}
else if (newValue >=64343.45 && newValue <64939.23){firstDigit='1'; secondDigit='0'; thirdDigit='8';}
else if (newValue >=64939.23 && newValue <65535.00){firstDigit='1'; secondDigit='0'; thirdDigit='9';}
else if (newValue >=65535.00){firstDigit='1'; secondDigit='1'; thirdDigit='0';}


lcd.setCursor(14,1);
lcd.print (firstDigit);
lcd.print (secondDigit);
lcd.print (thirdDigit);

}
DcsBios::IntegerBuffer leftenginerpmBuffer(0x271c, 0xffff, 0, onLeftenginerpmChange);

//обороты правого двигателя
void onRightenginerpmChange(unsigned int newValue) {
    /* your code here */
char firstDigit;
    char secondDigit;
    char thirdDigit;

    if (newValue < 595.77){firstDigit=' '; secondDigit=' '; thirdDigit='0';}
else if (newValue >=595.77 && newValue <1191.55){firstDigit=' '; secondDigit=' '; thirdDigit='1';}
else if (newValue >=1191.55 && newValue <1787.32){firstDigit=' '; secondDigit=' '; thirdDigit='2';}
else if (newValue >=1787.32 && newValue <2383.09){firstDigit=' '; secondDigit=' '; thirdDigit='3';}
else if (newValue >=2383.09 && newValue <2978.86){firstDigit=' '; secondDigit=' '; thirdDigit='4';}
else if (newValue >=2978.86 && newValue <3574.64){firstDigit=' '; secondDigit=' '; thirdDigit='5';}
else if (newValue >=3574.64 && newValue <4170.41){firstDigit=' '; secondDigit=' '; thirdDigit='6';}
else if (newValue >=4170.41 && newValue <4766.18){firstDigit=' '; secondDigit=' '; thirdDigit='7';}
else if (newValue >=4766.18 && newValue <5361.95){firstDigit=' '; secondDigit=' '; thirdDigit='8';}
else if (newValue >=5361.95 && newValue <5957.73){firstDigit=' '; secondDigit=' '; thirdDigit='9';}
else if (newValue >=5957.73 && newValue <6553.50){firstDigit=' '; secondDigit='1'; thirdDigit='0';}
else if (newValue >=6553.50 && newValue <7149.27){firstDigit=' '; secondDigit='1'; thirdDigit='1';}
else if (newValue >=7149.27 && newValue <7745.05){firstDigit=' '; secondDigit='1'; thirdDigit='2';}
else if (newValue >=7745.05 && newValue <8340.82){firstDigit=' '; secondDigit='1'; thirdDigit='3';}
else if (newValue >=8340.82 && newValue <8936.59){firstDigit=' '; secondDigit='1'; thirdDigit='4';}
else if (newValue >=8936.59 && newValue <9532.36){firstDigit=' '; secondDigit='1'; thirdDigit='5';}
else if (newValue >=9532.36 && newValue <10128.14){firstDigit=' '; secondDigit='1'; thirdDigit='6';}
else if (newValue >=10128.14 && newValue <10723.91){firstDigit=' '; secondDigit='1'; thirdDigit='7';}
else if (newValue >=10723.91 && newValue <11319.68){firstDigit=' '; secondDigit='1'; thirdDigit='8';}
else if (newValue >=11319.68 && newValue <11915.45){firstDigit=' '; secondDigit='1'; thirdDigit='9';}
else if (newValue >=11915.45 && newValue <12511.23){firstDigit=' '; secondDigit='2'; thirdDigit='0';}
else if (newValue >=12511.23 && newValue <13107.00){firstDigit=' '; secondDigit='2'; thirdDigit='1';}
else if (newValue >=13107.00 && newValue <13702.77){firstDigit=' '; secondDigit='2'; thirdDigit='2';}
else if (newValue >=13702.77 && newValue <14298.55){firstDigit=' '; secondDigit='2'; thirdDigit='3';}
else if (newValue >=14298.55 && newValue <14894.32){firstDigit=' '; secondDigit='2'; thirdDigit='4';}
else if (newValue >=14894.32 && newValue <15490.09){firstDigit=' '; secondDigit='2'; thirdDigit='5';}
else if (newValue >=15490.09 && newValue <16085.86){firstDigit=' '; secondDigit='2'; thirdDigit='6';}
else if (newValue >=16085.86 && newValue <16681.64){firstDigit=' '; secondDigit='2'; thirdDigit='7';}
else if (newValue >=16681.64 && newValue <17277.41){firstDigit=' '; secondDigit='2'; thirdDigit='8';}
else if (newValue >=17277.41 && newValue <17873.18){firstDigit=' '; secondDigit='2'; thirdDigit='9';}
else if (newValue >=17873.18 && newValue <18468.95){firstDigit=' '; secondDigit='3'; thirdDigit='0';}
else if (newValue >=18468.95 && newValue <19064.73){firstDigit=' '; secondDigit='3'; thirdDigit='1';}
else if (newValue >=19064.73 && newValue <19660.50){firstDigit=' '; secondDigit='3'; thirdDigit='2';}
else if (newValue >=19660.50 && newValue <20256.27){firstDigit=' '; secondDigit='3'; thirdDigit='3';}
else if (newValue >=20256.27 && newValue <20852.05){firstDigit=' '; secondDigit='3'; thirdDigit='4';}
else if (newValue >=20852.05 && newValue <21447.82){firstDigit=' '; secondDigit='3'; thirdDigit='5';}
else if (newValue >=21447.82 && newValue <22043.59){firstDigit=' '; secondDigit='3'; thirdDigit='6';}
else if (newValue >=22043.59 && newValue <22639.36){firstDigit=' '; secondDigit='3'; thirdDigit='7';}
else if (newValue >=22639.36 && newValue <23235.14){firstDigit=' '; secondDigit='3'; thirdDigit='8';}
else if (newValue >=23235.14 && newValue <23830.91){firstDigit=' '; secondDigit='3'; thirdDigit='9';}
else if (newValue >=23830.91 && newValue <24426.68){firstDigit=' '; secondDigit='4'; thirdDigit='0';}
else if (newValue >=24426.68 && newValue <25022.45){firstDigit=' '; secondDigit='4'; thirdDigit='1';}
else if (newValue >=25022.45 && newValue <25618.23){firstDigit=' '; secondDigit='4'; thirdDigit='2';}
else if (newValue >=25618.23 && newValue <26214.00){firstDigit=' '; secondDigit='4'; thirdDigit='3';}
else if (newValue >=26214.00 && newValue <26809.77){firstDigit=' '; secondDigit='4'; thirdDigit='4';}
else if (newValue >=26809.77 && newValue <27405.55){firstDigit=' '; secondDigit='4'; thirdDigit='5';}
else if (newValue >=27405.55 && newValue <28001.32){firstDigit=' '; secondDigit='4'; thirdDigit='6';}
else if (newValue >=28001.32 && newValue <28597.09){firstDigit=' '; secondDigit='4'; thirdDigit='7';}
else if (newValue >=28597.09 && newValue <29192.86){firstDigit=' '; secondDigit='4'; thirdDigit='8';}
else if (newValue >=29192.86 && newValue <29788.64){firstDigit=' '; secondDigit='4'; thirdDigit='9';}
else if (newValue >=29788.64 && newValue <30384.41){firstDigit=' '; secondDigit='5'; thirdDigit='0';}
else if (newValue >=30384.41 && newValue <30980.18){firstDigit=' '; secondDigit='5'; thirdDigit='1';}
else if (newValue >=30980.18 && newValue <31575.95){firstDigit=' '; secondDigit='5'; thirdDigit='2';}
else if (newValue >=31575.95 && newValue <32171.73){firstDigit=' '; secondDigit='5'; thirdDigit='3';}
else if (newValue >=32171.73 && newValue <32767.50){firstDigit=' '; secondDigit='5'; thirdDigit='4';}
else if (newValue >=32767.50 && newValue <33363.27){firstDigit=' '; secondDigit='5'; thirdDigit='5';}
else if (newValue >=33363.27 && newValue <33959.05){firstDigit=' '; secondDigit='5'; thirdDigit='6';}
else if (newValue >=33959.05 && newValue <34554.82){firstDigit=' '; secondDigit='5'; thirdDigit='7';}
else if (newValue >=34554.82 && newValue <35150.59){firstDigit=' '; secondDigit='5'; thirdDigit='8';}
else if (newValue >=35150.59 && newValue <35746.36){firstDigit=' '; secondDigit='5'; thirdDigit='9';}
else if (newValue >=35746.36 && newValue <36342.14){firstDigit=' '; secondDigit='6'; thirdDigit='0';}
else if (newValue >=36342.14 && newValue <36937.91){firstDigit=' '; secondDigit='6'; thirdDigit='1';}
else if (newValue >=36937.91 && newValue <37533.68){firstDigit=' '; secondDigit='6'; thirdDigit='2';}
else if (newValue >=37533.68 && newValue <38129.45){firstDigit=' '; secondDigit='6'; thirdDigit='3';}
else if (newValue >=38129.45 && newValue <38725.23){firstDigit=' '; secondDigit='6'; thirdDigit='4';}
else if (newValue >=38725.23 && newValue <39321.00){firstDigit=' '; secondDigit='6'; thirdDigit='5';}
else if (newValue >=39321.00 && newValue <39916.77){firstDigit=' '; secondDigit='6'; thirdDigit='6';}
else if (newValue >=39916.77 && newValue <40512.55){firstDigit=' '; secondDigit='6'; thirdDigit='7';}
else if (newValue >=40512.55 && newValue <41108.32){firstDigit=' '; secondDigit='6'; thirdDigit='8';}
else if (newValue >=41108.32 && newValue <41704.09){firstDigit=' '; secondDigit='6'; thirdDigit='9';}
else if (newValue >=41704.09 && newValue <42299.86){firstDigit=' '; secondDigit='7'; thirdDigit='0';}
else if (newValue >=42299.86 && newValue <42895.64){firstDigit=' '; secondDigit='7'; thirdDigit='1';}
else if (newValue >=42895.64 && newValue <43491.41){firstDigit=' '; secondDigit='7'; thirdDigit='2';}
else if (newValue >=43491.41 && newValue <44087.18){firstDigit=' '; secondDigit='7'; thirdDigit='3';}
else if (newValue >=44087.18 && newValue <44682.95){firstDigit=' '; secondDigit='7'; thirdDigit='4';}
else if (newValue >=44682.95 && newValue <45278.73){firstDigit=' '; secondDigit='7'; thirdDigit='5';}
else if (newValue >=45278.73 && newValue <45874.50){firstDigit=' '; secondDigit='7'; thirdDigit='6';}
else if (newValue >=45874.50 && newValue <46470.27){firstDigit=' '; secondDigit='7'; thirdDigit='7';}
else if (newValue >=46470.27 && newValue <47066.05){firstDigit=' '; secondDigit='7'; thirdDigit='8';}
else if (newValue >=47066.05 && newValue <47661.82){firstDigit=' '; secondDigit='7'; thirdDigit='9';}
else if (newValue >=47661.82 && newValue <48257.59){firstDigit=' '; secondDigit='8'; thirdDigit='0';}
else if (newValue >=48257.59 && newValue <48853.36){firstDigit=' '; secondDigit='8'; thirdDigit='1';}
else if (newValue >=48853.36 && newValue <49449.14){firstDigit=' '; secondDigit='8'; thirdDigit='2';}
else if (newValue >=49449.14 && newValue <50044.91){firstDigit=' '; secondDigit='8'; thirdDigit='3';}
else if (newValue >=50044.91 && newValue <50640.68){firstDigit=' '; secondDigit='8'; thirdDigit='4';}
else if (newValue >=50640.68 && newValue <51236.45){firstDigit=' '; secondDigit='8'; thirdDigit='5';}
else if (newValue >=51236.45 && newValue <51832.23){firstDigit=' '; secondDigit='8'; thirdDigit='6';}
else if (newValue >=51832.23 && newValue <52428.00){firstDigit=' '; secondDigit='8'; thirdDigit='7';}
else if (newValue >=52428.00 && newValue <53023.77){firstDigit=' '; secondDigit='8'; thirdDigit='8';}
else if (newValue >=53023.77 && newValue <53619.55){firstDigit=' '; secondDigit='8'; thirdDigit='9';}
else if (newValue >=53619.55 && newValue <54215.32){firstDigit=' '; secondDigit='9'; thirdDigit='0';}
else if (newValue >=54215.32 && newValue <54811.09){firstDigit=' '; secondDigit='9'; thirdDigit='1';}
else if (newValue >=54811.09 && newValue <55406.86){firstDigit=' '; secondDigit='9'; thirdDigit='2';}
else if (newValue >=55406.86 && newValue <56002.64){firstDigit=' '; secondDigit='9'; thirdDigit='3';}
else if (newValue >=56002.64 && newValue <56598.41){firstDigit=' '; secondDigit='9'; thirdDigit='4';}
else if (newValue >=56598.41 && newValue <57194.18){firstDigit=' '; secondDigit='9'; thirdDigit='5';}
else if (newValue >=57194.18 && newValue <57789.95){firstDigit=' '; secondDigit='9'; thirdDigit='6';}
else if (newValue >=57789.95 && newValue <58385.73){firstDigit=' '; secondDigit='9'; thirdDigit='7';}
else if (newValue >=58385.73 && newValue <58981.50){firstDigit=' '; secondDigit='9'; thirdDigit='8';}
else if (newValue >=58981.50 && newValue <59577.27){firstDigit=' '; secondDigit='9'; thirdDigit='9';}
else if (newValue >=59577.27 && newValue <60173.05){firstDigit='1'; secondDigit='0'; thirdDigit='0';}
else if (newValue >=60173.05 && newValue <60768.82){firstDigit='1'; secondDigit='0'; thirdDigit='1';}
else if (newValue >=60768.82 && newValue <61364.59){firstDigit='1'; secondDigit='0'; thirdDigit='2';}
else if (newValue >=61364.59 && newValue <61960.36){firstDigit='1'; secondDigit='0'; thirdDigit='3';}
else if (newValue >=61960.36 && newValue <62556.14){firstDigit='1'; secondDigit='0'; thirdDigit='4';}
else if (newValue >=62556.14 && newValue <63151.91){firstDigit='1'; secondDigit='0'; thirdDigit='5';}
else if (newValue >=63151.91 && newValue <63747.68){firstDigit='1'; secondDigit='0'; thirdDigit='6';}
else if (newValue >=63747.68 && newValue <64343.45){firstDigit='1'; secondDigit='0'; thirdDigit='7';}
else if (newValue >=64343.45 && newValue <64939.23){firstDigit='1'; secondDigit='0'; thirdDigit='8';}
else if (newValue >=64939.23 && newValue <65535.00){firstDigit='1'; secondDigit='0'; thirdDigit='9';}
else if (newValue >=65535.00){firstDigit='1'; secondDigit='1'; thirdDigit='0';}


lcd.setCursor(14,2);
lcd.print (firstDigit);
lcd.print (secondDigit);
lcd.print (thirdDigit);

}
DcsBios::IntegerBuffer rightenginerpmBuffer(0x271e, 0xffff, 0, onRightenginerpmChange);


//шаг винта
void onRotorpitchChange(unsigned int newValue) {
    /* your code here */
    char firstDigit;
    char secondDigit;


    if (newValue < 4681.07){firstDigit=' '; secondDigit='1';}
else if (newValue >=4681.07 && newValue <9362.14){firstDigit=' '; secondDigit='2';}
else if (newValue >=9362.14 && newValue <14043.21){firstDigit=' '; secondDigit='3';}
else if (newValue >=14043.21 && newValue <18724.29){firstDigit=' '; secondDigit='4';}
else if (newValue >=18724.29 && newValue <23405.36){firstDigit=' '; secondDigit='5';}
else if (newValue >=23405.36 && newValue <28086.43){firstDigit=' '; secondDigit='6';}
else if (newValue >=28086.43 && newValue <32767.50){firstDigit=' '; secondDigit='7';}
else if (newValue >=32767.50 && newValue <37448.57){firstDigit=' '; secondDigit='8';}
else if (newValue >=37448.57 && newValue <42129.64){firstDigit=' '; secondDigit='9';}
else if (newValue >=42129.64 && newValue <46810.71){firstDigit='1'; secondDigit='0';}
else if (newValue >=46810.71 && newValue <51491.79){firstDigit='1'; secondDigit='1';}
else if (newValue >=51491.79 && newValue <56172.86){firstDigit='1'; secondDigit='2';}
else if (newValue >=56172.86 && newValue <60853.93){firstDigit='1'; secondDigit='3';}
else if (newValue >=60853.93 && newValue <65535.00){firstDigit='1'; secondDigit='4';}
else if (newValue >=65535.00 && newValue <0.00){firstDigit='1'; secondDigit='5';}



lcd.setCursor(15,3);
lcd.print (firstDigit);
lcd.print (secondDigit);


}
DcsBios::IntegerBuffer rotorpitchBuffer(0x2710, 0xffff, 0, onRotorpitchChange);


void setup() {
  DcsBios::setup();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Rotor rev,%:");
  lcd.setCursor(0,1);
  lcd.print("L.Eng.rev,%:");
  lcd.setCursor(0,2);
  lcd.print("R.Eng.rev,%:");
  lcd.setCursor(0,3);
  lcd.print("Rotor angle,\xDF:");
}

void loop() {
  DcsBios::loop();
}
