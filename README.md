# buildroot_bpi-m2z_hello
Buildroot for Banana Pi M2 Zero (BPI-M2Z) hello project

## Patch  
* It is based on buildroot-2019.02.3, see buildroot-2019.02.3_bpi-m2z_patch/  
$ make bananapi_m2_plus_defconfig && make  

## Ref  
* http://wiki.banana-pi.org/Getting_Started_with_M2_Zero  

## How to Build  
* For buildroot-2019.02.3, Ubuntu 14.04 32bit     
$ sudo apt-get update  
$ sudo apt-get install g++ git libncurses5-dev    
$ cd buildroot-2019.02.3   
(Please patch first, see uppon, see buildroot-2019.02.3_bpi-m2z_patch/)   
$ make help  
$ make list-defconfigs    
$ make bananapi_m2_plus_defconfig  
$ make menuconfig  
(Enable Toolchain->Enable C++ support)  
$ make  
(Get sdcard.img under output/images/)  
(Put hellocpp and helloworld to package/)  
(Modify package/Config.in)  
...  
menu "Miscellaneous"  
...  
source "package/helloworld/Config.in"  
source "package/hellocpp/Config.in"  
$ make menuconfig  
(Enable Package->Misc->helloworld, hellocpp)  
$ make  
(After modify hellocpp source)  
$ make hellocpp-dirclean && make  
(Get new sdcard.img under output/image/)  
(Flash sdcard.img to tf card using Win32DiskImager, over)  

## Pinout, gpio readall  
```  
 +-----+-----+---------+------+---+---Pi ?---+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |  12 |   8 |   SDA.1 | ALT3 | 0 |  3 || 4  |   |      | 5v      |     |     |
 |  11 |   9 |   SCL.1 | ALT3 | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   6 |   7 | GPIO. 7 | ALT3 | 0 |  7 || 8  | 0 | ALT3 | TxD     | 15  | 13  |
 |     |     |      0v |      |   |  9 || 10 | 0 | ALT3 | RxD     | 16  | 14  |
 |   1 |   0 | GPIO. 0 | ALT3 | 0 | 11 || 12 | 0 | ALT3 | GPIO. 1 | 1   | 16  |
 |   0 |   2 | GPIO. 2 | ALT3 | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   3 |   3 | GPIO. 3 | ALT3 | 0 | 15 || 16 | 0 | ALT3 | GPIO. 4 | 4   | 15  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | ALT3 | GPIO. 5 | 5   | 68  |
 |  64 |  12 |    MOSI | ALT3 | 0 | 19 || 20 |   |      | 0v      |     |     |
 |  65 |  13 |    MISO | ALT3 | 0 | 21 || 22 | 0 | ALT3 | GPIO. 6 | 6   | 2   |
 |  66 |  14 |    SCLK | ALT3 | 0 | 23 || 24 | 0 | ALT3 | CE0     | 10  | 67  |
 |     |     |      0v |      |   | 25 || 26 | 0 | ALT3 | CE1     | 11  | 71  |
 |  19 |  30 |   SDA.0 | ALT3 | 0 | 27 || 28 | 0 | ALT3 | SCL.0   | 31  | 18  |
 |   7 |  21 | GPIO.21 | ALT3 | 0 | 29 || 30 |   |      | 0v      |     |     |
 |   8 |  22 | GPIO.22 | ALT3 | 0 | 31 || 32 | 0 | ALT3 | GPIO.26 | 26  | 354 |
 |   9 |  23 | GPIO.23 | ALT3 | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  10 |  24 | GPIO.24 | ALT3 | 0 | 35 || 36 | 0 | ALT3 | GPIO.27 | 27  | 356 |
 |  17 |  25 | GPIO.25 | ALT3 | 0 | 37 || 38 | 0 | ALT3 | GPIO.28 | 28  | 21  |
 |     |     |      0v |      |   | 39 || 40 | 0 | ALT3 | GPIO.29 | 29  | 20  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi ?---+---+------+---------+-----+-----+
```  

## BPI-M2 Zero Pin define  
Banana Pi BPI-M2 Zero 40-pin GPIO define is same as BPI-M2+  
https://bananapi.gitbook.io/bpi-m2-/en/bpi-m2-zero-hardware/bpi-m2-zero-pin-define  
https://bananapi.gitbook.io/bpi-m2-/en/bpi-m2-zero-hardware-1  
BPi-M2-Zero-schematic V1_0-R.pdf  
```
GPIO Pin Name, Default Function, Function2：GPIO, Function3  
CON2-P01 (3.3V1),VCC-3V3 || CON2-P02 (5.0V1),VCC-5V  
CON2-P03 (SDA),TWI0-SDA,PA12-EINT12 || CON2-P04 (5.0V2),VCC-5V  
CON2-P05 (SCL),TWI0-SCK,PA11-EINT11 || CON2-P06 (GND3),GND  
CON2-P07 (IO-GCLK),PWM1, PA6-EINT6 || CON2-P08 (TXD0), UART3-TX, PA13-EINT13, SPI1-CS  
CON2-P09 (GND1), GND || CON2-P10 (RXD0), UART3-RX, PA14-EINT14, SPI1-CLK  
CON2-P11 (IO-0), UART2-RX, PA1-EINT1 || CON2-P12 (IO-1), UART3-CTS, PA16-EINT16, SPI1-MISO  
CON2-P13 (IO-2), UART2-TX || PA0-EINT0, CON2-P14 (GND4), GND  
CON2-P15 (IO-3), UART2-CTS, PA3-EINT3 || CON2-P16 (IO-4), UART3-RTS, PA15-EINT15, SPI1-MOSI  
CON2-P17 (3.3V2), VCC-3V3 || CON2-P18 (IO-5), PC4, PC4  
CON2-P19 (SPI-MOSI), SPI0-MOSI, PC0 || CON2-P20 (GND5), GND  
CON2-P21 (SPI-MISO), SPI0-MISO, PC1 || CON2-P22 (IO-6), UART2-RTS, PA2-EINT2  
CON2-P23 (SPI-CLK), SPI0-CLK, PC2 || CON2-P24 (SPI-CE0), SPI0-CS, PC3  
CON2-P25 (GND2), GND || CON2-P26 (SPI-CE1), PC7, PC7  
CON2-P27 (ID-SD), TWI1-SDA, PA19-EINT19 || CON2-P28 (ID-SC), TWI1-SCK, PA18-EINT18  
CON2-P29 (IO-7), PA7-EINT7, PA7-EINT7 || CON2-P30 (GND6), GND  
CON2-P31 (IO-8), PA8-EINT8, PA8-EINT8 || CON2-P32 (IO-9), PL2-S-EINT2, PL2-S-EINT2  
CON2-P33 (IO-10), PA9-EINT9, PA9-EINT9 || CON2-P34 (GND8), GND  
CON2-P35 (IO-12), PA10-EINT10, PA10-EINT10 || CON2-P36 (IO-13), PL4-S-EINT4, PL4-S-EINT4  
CON2-P37 (IO-14), PA17-EINT17, PA17-EINT17, SPDIF-OUT || CON2-P38 (IO-15), PA21-EINT21, PA21-EINT21  
CON2-P39 (GND7), GND || CON2-P40 (IO-16), PA20-EINT20, PA20-EINT20  

CON3-P03, UART0-TXD, PA4  
CON3-P02, UART0-RXD, PA5  
CON3-P01, GND  
```  

## bpi fel  
search baidupan, bpi-fel-mass-storage-gui4win-v1.002.zip  
https://github.com/OtakuNekoP/bpi-fel-mass-storage-gui4win/releases  
https://linux-sunxi.org/FEL  
