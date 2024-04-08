/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 22
  模拟温度传感器
  http://www.keyes-robot.com
*/
int val;
int ntcPin = A0;  //设置NTC-MF52AT模拟温度传感器接模拟口A0
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  val = analogRead(ntcPin); //读取温度模拟值
  Serial.println(val); //读取并打印热敏电阻模拟值
  delay(100);//延时100毫秒

}
