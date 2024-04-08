/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 31
  旋转编码器
  http://www.keyes-robot.com
*/
#include <Encoder.h>//导入编码器的库
int SW = 4; //编码器按钮就数字口4
int DT = 3;
int CLK = 2;
Encoder encoder(CLK, DT);
int val = 0;
int old = 0;

void setup() {
  Serial.begin(9600);//设置波特率
  pinMode(SW, INPUT);//按键为输入模式
}
void loop() {
  val = encoder.read();//读取编码器的值赋给val
  if (digitalRead(SW) == 0) {//如果按键按下
    Serial.println(digitalRead(SW));//打印按键值
    delay(100);
  }
  if (old != val) {//与之前读取的值不一样
    Serial.println(val);//打印编码器的值
    old = val;
  }
}
