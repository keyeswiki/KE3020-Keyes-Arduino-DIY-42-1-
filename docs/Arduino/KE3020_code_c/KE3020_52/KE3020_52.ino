/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 52
  智能窗户
  http://www.keyes-robot.com
*/
#include <Servo.h>//导入舵机的库文件
int item = 0;//存放水滴传感器输出的模拟值的变量
Servo myservo;//定义一个舵机类实例

void setup(){
  myservo.attach(9);//舵机接数字口9
}

void loop(){
  item = analogRead(A0);//水滴传感器接模拟口A0
  if (item > 200) {//模拟值大于200
    myservo.write(0);//关窗
    delay(500);//给舵机一定的时间转动
  } else {//没下雨
    myservo.write(180);//开窗
    delay(500);//延时500ms
  }

}
