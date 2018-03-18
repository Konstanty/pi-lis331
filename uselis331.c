/******************************************************************************
i2ctest.cpp

******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <wiringPiI2C.h>


#include "lis331.h"


int main()
{
   int fd, result;

   // Initialize the LIS331, it has a default address of 0x19
   fd = wiringPiI2CSetup(0x19);

   setPowerMode(fd, NORMAL);
   int data = wiringPiI2CReadReg8 (fd, CTRL_REG1);
   printf("OUT: %d\n", data);

   axesEnable(fd, 1);
   zeroAxes(fd);

   int16_t x, y, z;

   int times = 1000;
   while (times--) {
     readAxes(fd, &x, &y, &z);

     printf("X: %d, Y: %d, Z: %d\n", x, y, z);
  }

  setPowerMode(fd, POWER_DOWN);
  data = wiringPiI2CReadReg8 (fd, CTRL_REG1);
  printf("OUT: %d\n", data);




}
