//blinky wiringpi.7, BCM.4, GPIO.7, #7

#include <iostream>
#include <string>
#include <vector>
extern "C" {
#include "wiringPi/wiringPi.h"
}

using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec;
    vec.push_back(10);

    string s = "Hell! O' world, why won't my c++ code run?\n\n";
    cout << s;

    //millis();
    //delay(1000);
    cout << vec[0] << endl;

//------------------------

  doReadall();

//------------------------
//cout << "doReadall done" << endl;

  piHiPri(1);

//cout << "piHiPri done" << endl;

  wiringPiSetup();

//cout << "wiringPiSetup done" << endl;

  const int LED_BUILTIN = 7;
  pinMode(LED_BUILTIN, OUTPUT);
  
//cout << "pinMode done" << endl;
  while(1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    cout << "blink" << endl;
  }

  return 0;
}

