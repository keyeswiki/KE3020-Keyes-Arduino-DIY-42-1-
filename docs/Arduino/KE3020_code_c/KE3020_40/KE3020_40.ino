/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 40
  HT16K33_8X8点阵
  http://www.keyes-robot.com
*/
#include <Matrix.h>//点阵的库

Matrix myMatrix(SDA, SCL);
uint8_t  LEDArray[8];

const uint8_t LedArray1[8] PROGMEM = {0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0x66, 0x00};//心形图案

void setup() {
  myMatrix.begin(0x70);//iic地址
  myMatrix.clear();//清除显示
  myMatrix.setBrightness(5);//亮度5,范围0~15
}

void loop() {
  memcpy_P(&LEDArray, &LedArray1, 8);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if ((LEDArray[i] & 0x01))
        myMatrix.drawPixel(j, i, 1);
      else
        myMatrix.drawPixel(j, i, 0);
      LEDArray[i] = LEDArray[i] >> 1;
    }
  }
  myMatrix.write(); //显示

}
