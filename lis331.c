#include <wiringPiI2C.h>

#include "lis331.h"

void setPowerMode(int fd, int pmode) {
   int data = wiringPiI2CReadReg8 (fd, CTRL_REG1);

  // The power mode is the high three bits of CTRL_REG1. The mode
  //  constants are the appropriate bit values left shifted by five, so we
  //  need to right shift them to make them work. We also want to mask off the
  //  top three bits to zero, and leave the others untouched, so we *only*
  //  affect the power mode bits.
  data &= ~0xe0; // Clear the top three bits
  data |= pmode<<5; // set the top three bits to our pmode value
  wiringPiI2CWriteReg8(fd, CTRL_REG1, data);
}

void axesEnable(int fd, int enable) {

  int data = wiringPiI2CReadReg8 (fd, CTRL_REG1);
  if (enable) {
    data |= 0x07;
  } else {
    data &= ~0x07;
  }

  wiringPiI2CWriteReg8(fd, CTRL_REG1, data);

}

void zeroAxes(int fd) {

  int data = 0;
  for (int i = 0x21; i < 0x25; i++) wiringPiI2CWriteReg8(fd, i, data);
  for (int i = 0x30; i < 0x37; i++) wiringPiI2CWriteReg8(fd, i, data);

}

void readAxes(int fd, int16_t *x, int16_t *y, int16_t *z) {


  uint8_t data[6];
  data[0] = wiringPiI2CReadReg8 (fd, OUT_X_L);
  data[1] = wiringPiI2CReadReg8 (fd, OUT_X_H);
  data[2] = wiringPiI2CReadReg8 (fd, OUT_Y_L);
  data[3] = wiringPiI2CReadReg8 (fd, OUT_Y_H);
  data[4] = wiringPiI2CReadReg8 (fd, OUT_Z_L);
  data[5] = wiringPiI2CReadReg8 (fd, OUT_Z_H);

  // The data that comes out is 12-bit data, left justified, so the lower
  //  four bits of the data are always zero. We need to right shift by four,
  //  then typecase the upper data to an integer type so it does a signed
  //  right shift.
  *x = data[0] | data[1] << 8;
  *y = data[2] | data[3] << 8;
  *z = data[4] | data[5] << 8;
  *x = *x >> 4;
  *y = *y >> 4;
  *z = *z >> 4;

}
