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

