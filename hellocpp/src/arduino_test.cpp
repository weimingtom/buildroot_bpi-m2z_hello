//blinky wiringpi.7, BCM.4, GPIO.7, #7

#include <iostream>
#include <string>
#include <vector>
#include "Arduino.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec;
    vec.push_back(10);

    string s = "Hell! O' world, why won't my c++ code run?\n\n";
    cout << s;

    cout << vec[0];

//------------------------

  setup_io();
  gpio_setoutput(4);
  
  while(1) {
    gpio_setstate(4, HIGH);
    delay(1000);
    gpio_setstate(4, LOW);
    delay(1000);
  }

  return 0;
}



