/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 30
  6812RGB
  http://www.keyes-robot.com
*/
//添加RGB6812库文件
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel  rgb_display(8);  //定义一个像素的类

void setup() {
  rgb_display.begin();  //启动6812RGB
  rgb_display.setPin(8);  //设置6812管脚接数字口8
  rgb_display.setBrightness(100); //设置亮度为100，范围为0~255
}

void loop() {
  rgb_display.setPixelColor(0, 255, 0, 0); //第一颗灯珠亮红色
  rgb_display.setPixelColor(1, 0, 255, 0); //第二颗灯珠亮绿色
  rgb_display.setPixelColor(2, 0, 0, 255); //第三颗灯珠亮蓝色
  rgb_display.setPixelColor(3, 255, 255, 255); //第四颗灯珠亮白色
  rgb_display.show(); //显示灯珠颜色

}
