#include <stdio.h>
#include <pigpio.h>
#include "iNR.h"
//#include <thread.h>
int main(int argc, char *argv[])
{
    unsigned ligSrc,irSnr;
    double irLigSnr0;

    ligSrc=24;
    irSnr=18;
    
    irLigSnr0=lightSensor(ligSrc,irSnr);

    printf("%f is the amount of time it took for the sensors to detect the light,the pins are located in  which are dectecting the light %u, %u \n",irLigSnr0,ligSrc,irSnr);
    gpioTerminate();

    return 0;
}

