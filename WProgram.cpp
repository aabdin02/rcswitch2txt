#include "WProgram.h"

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <fstream> // readfile
#include <string> // readfile
#include <iostream>
//#include <thread>  
#include <cstring>
//#include <sys/inotify.h>
//#include <unistd.h> // usleep

using namespace std;

void delayMicroseconds (unsigned int howLong)
{
    cout << "delayMicroseconds " << howLong << endl;
}

void pinMode(int pin, int mode)
{
    cout << "pinMode " << mode << endl;
}

void digitalWrite(int pin, int value)
{
    cout << "digitalWrite " << value << endl;
}
/*
// not used
int digitalRead(int pin)
{
  return 0;
}

// not used
void attachInterrupt(int pin, voidFuncPtr handler, int mode)
{
    cout << "attachInterrupt" << endl;
}

// not used
void detachInterrupt(int pin)
{
  cout << "detachInterrupt" << endl;
}

// not used
unsigned long micros(void)
{
    cout << "micros" << endl;
    struct timeval t;
    long micros;
    gettimeofday(&t, NULL);
    micros = t.tv_sec * 1000000L + t.tv_usec;
    
    return micros; // should be the time in microsecond
}
*/