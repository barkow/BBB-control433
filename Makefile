all: test

test: gpio.o RCSwitch.o test.cpp
	g++ test.cpp gpio.o RCSwitch.o -o test

RCSwitch.o: RCSwitch.cpp
	g++ -c RCSwitch.cpp

gpio.o: gpio.cpp
	g++ -c gpio.cpp

clean:
	rm -rf *.o test
