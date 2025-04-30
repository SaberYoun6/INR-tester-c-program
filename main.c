#include <stdio.h>
#include <wiringPI.h>
#include "iNR.h"
//#include <thread.h>
int main(int argc, char *argv[])
{
    int ligSrc,irSnr;
    double irLigHitSnr0;


    ligSrc=5;
    irSnr=22;
    
    irLigHitSnr0=lightHittingSensor(ligSrc,irSnr);

    printf("%f is the amount of time it took for the sensors to detect the light,the pins are located in  which are dectecting the light %u, %u \n",irLigHitSnr0,ligSrc,irSnr);

    return 0;
}

