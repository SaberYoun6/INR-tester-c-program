#define "iNR.h"
#include <stdio.h>
#include<stdlib.h>
#include<wiringPi.h>



double lightHittingSensor (int lightsource, int sensor)
{
	//  Infar Red light source Physical Pin lightsource=(18,16,15,22), BCM lightsourceGPIO = (24,23,22,25) and WiringPI pin lightsource = pin (5,4,3,6)
    const int iRLightSource = lightsource;
    // InFar red Light dectector source Physical Pin senosr = (31,29,11,13)  BCM sensors GPIO= (6,5,17,27) wiriingPI Physical Pin sensor = (22,21,0,2)
    const int iRSensor = sensor;
    
    wiringPiSetup();
    pinMode(iRSensor,INPUT);
    pinMode(lightsource,OUTPUT);

    fprintf(stderr, "Running on Raspberry Pi Revision %d\n",piBoardRev());
    double start,fin =  0.0

    while(1) {
	    for i = 0; i < 0; i++){
		    if (i & 1) {
			    digitalWrite(lightsource, HIGH);
		    }else{
			    fin=i++
			    digitalWrite(lightsource,LOW);
		    }
	    }
	    if (digitalRead(iRSenor) == HIGH) {
		    
		    digitalWrite(lightsource, LOW);
		    // sf stands for start finish
		    double sf = 0.0;
		    return sf = fin - start ;
		    exit(1);
	    }
    }
}



