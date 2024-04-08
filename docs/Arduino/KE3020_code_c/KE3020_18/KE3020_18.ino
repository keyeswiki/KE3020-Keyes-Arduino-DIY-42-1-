/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 18
  旋转电位器
  http://www.keyes-robot.com
*/
int analogVal = 0;
int resPin = A0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  analogVal = analogRead(resPin);//读取电位器的值
  Serial.println(analogVal);//打印模拟值
  delay(100);//延时100毫秒

}
