/*
  Example for Intertechno outlets
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include "RCSwitch.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>

RCSwitch *mySwitch;// = RCSwitch();

void setup() {
  mySwitch = new RCSwitch();

  // Transmitter is connected to Arduino Pin #10  
  mySwitch->enableTransmit(10);
  
  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
}

void loop() {

  // Switch on:
  // The first parameter represents the familycode (a, b, c, ... f)
  // The second parameter represents the group number
  // The third parameter represents the device number
  // 
  // In this example it's family 'b', group #3, device #2 
  mySwitch->switchOn('g', 1, 2);
  std::cout << "Switch On"  << std::endl;

  // Wait a second
  //delay(1000);
  usleep(1000000);
  
  // Switch off
  mySwitch->switchOff('g', 1, 2);
  std::cout << "Switch Off" << std::endl;
  
  // Wait another second
  //delay(1000);
  usleep(1000000);
  
}

int main(){
  std::cout << "Starte Setup" << std::endl;
  setup();
  std::cout << "Starte Loop" << std::endl;
  while(1){
    loop();
  }
}
