#pragma once

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HIGH 1
#define LOW 0

#define OUTPUT 1

extern void delay(int x);
extern void gpio_setstate(char g,char state); //digitalWrite(int x, int y);
extern void setup_io(); //wiringPiSetup();
extern void gpio_setoutput(char x); //pinMode(int x, int y);
//extern unsigned int millis();

