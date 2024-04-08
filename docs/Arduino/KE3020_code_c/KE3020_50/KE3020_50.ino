/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 50
  旋转编码器控制RGB模块
  http://www.keyes-robot.com
*/
#include <Encoder.h>
Encoder encoder(2, 3);
int redPin = 9; //定义红色接D9
int greenPin = 10; //定义绿色接D10
int bluePin = 11; //定义蓝色接D11
int i;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  i = encoder.read();
  val = i % 3;
  Serial.println(val);
  if (val == 0) {
    //红色(255, 0, 0)
    analogWrite(9, 255);
    analogWrite(10, 0);
    analogWrite(11, 0);
  } else if (val == 1) {
    //绿色(255, 0, 0)
    analogWrite(9, 0);
    analogWrite(10, 255);
    analogWrite(11, 0);
  } else {
    //蓝色(255, 0, 0)
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 255);
  }
  delay(100);

}
