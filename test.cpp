/*
  Example for Intertechno outlets
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include "RCSwitch.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Use Pin GPIO1_28 = 1*32 + 28 = PIN60
#define PIN_NO 60

RCSwitch mySwitch = RCSwitch();

int main(int argc, const char* argv[]){
  char family;
  int group;
  int device;
  int command;

  if (argc != 5) {
    std::cout << "Parameter fehlen" << std::endl;
    std::cout << argv[0] << " Family Group Device OnOff" << std::endl;
    std::cout << "Family: a-p" << std::endl;
    std::cout << "Group: 1-4" << std::endl;
    std::cout << "Device: 1-4" << std::endl;
    std::cout << "OnOff: 0 -> Off; 1 -> On" << std::endl;
    return -1;
  }
  family = (char)*argv[1];
  group = atoi(argv[2]);
  device = atoi(argv[3]);
  command = atoi(argv[4]);
  
  std::cout << "Family: " << family << std::endl;
  std::cout << "Group: " << group << std::endl;
  std::cout << "Device: " << device << std::endl;

  mySwitch.enableTransmit(PIN_NO);

  if (command) {
    mySwitch.switchOn(family, group, device);
    std::cout << "Command: ON" << std::endl;
  } else {
    mySwitch.switchOff(family, group, device);
    std::cout << "Command: OFF" << std::endl;
  }
}
