/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 57
  6812花样彩灯
  http://www.keyes-robot.com
*/
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
//用来储存RGB颜色的变量
int R = 0;
int G = 0;
int B = 0;
int num = 0;//存放灯号
Adafruit_NeoPixel  rgb_display(8);//创建一个6812类实例

void setup() {
  rgb_display.begin();
  rgb_display.setPin(8);//6812管脚接数字口8
}

void loop() {
  //取0~255之间的随机整数
  R = random(0, 255);
  G = random(0, 255);
  B = random(0, 255);
  if (num < 4) {  //num在1~4之间
    num = num + 1;
  } else {
    num = 1;
  }
  rgb_display.setPixelColor(num - 1, R, G, B); //设置num-1灯号颜色
  rgb_display.show();//显示
  delay(150);//150ms刷新颜色
  rgb_display.setPixelColor(num - 1, 0, 0, 0); //关闭num-1灯号颜色
  rgb_display.show();//显示

}
