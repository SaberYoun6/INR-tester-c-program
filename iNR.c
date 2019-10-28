#define "iNR.h"

double lightSensor(unsigned lightSource, unsigned irSenor)
{
    double start,init,final;
    int value = 0;

  if (gpioInitialise() < 0)
  {
      fprintf(stderr, "pigpio initialisation failed\n");
      return 1;
  }
 
  gpioSetMode(lightSource, PI_OUTPUT);
  gpioSetMode(irSensor,PI_INPUT);

  start = time_time();
  while ((time_time() -start ) < 30.00)
  {
      printf("Light turns on\n");
      gpioWrite(lightSource,1);
      
      time_sleep(10.0);

      printf("Light Turnned off\n");
      gpioWrite(lightSource,0);
      time_sleep(10.0);
  }
  init=time_time();
  final= 0.0;
  while ((time_time()/3600 - init) < 60.0 || value == 0 )
  {
      gpioWrite(lightSource,1);
      final=time_time();

      if (gpioRead(irSensor)==1)
      {
          gpioWrite(lightSource,0);
          final=time_time() - init;
          value = 1;
      } else {
          gpioWrite(lightSource,0);
          final=time_time() - init;
      }
  }
  return final;
}



