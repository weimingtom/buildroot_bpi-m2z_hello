#OBJS := hellocpp.o

#OBJS := strobe.o

#OBJS := Arduino.o arduino_test.o

OBJS := wiringPi_test.o
OBJS += wiringPi/wiringPi.o 
OBJS += wiringPi/wiringSerial.o 
OBJS += wiringPi/wiringShift.o 
OBJS += wiringPi/piHiPri.o 
OBJS += wiringPi/wiringPiSPI.o 
OBJS += wiringPi/wiringPiI2C.o 
OBJS += wiringPi/wiringPi_bpi.o 
OBJS += wiringPi/readall.o 

BIN := hellocpp

CFLAGS :=
LDFLAGS :=

all: $(BIN)

# build hellocpp executable when user executes "make"
$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# remove object files and executable when user executes "make clean"
clean:
	rm -rf *.o *.a $(BIN) $(OBJS)


