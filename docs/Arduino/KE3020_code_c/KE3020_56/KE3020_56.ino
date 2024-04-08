/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 56
  酒精检测仪
  http://www.keyes-robot.com
*/
#include "KETM1650.h"
int val = 0;
KETM1650 tm_4display(A5, A4);
void setup() {
  tm_4display.init();//TM1650初始化
  pinMode(3, OUTPUT);//有缘蜂鸣器接D3
}

void loop() {
  val = analogRead(A1);//读取酒精模拟值
  tm_4display.displayString(val);//四位数码管显示模拟值
  if (val > 600) {//模拟值大于600
    digitalWrite(3, HIGH); //蜂鸣器报警
  } else {//否则
    digitalWrite(3, LOW); //关闭蜂鸣器
  }
  delay(100);//延时100ms

}
