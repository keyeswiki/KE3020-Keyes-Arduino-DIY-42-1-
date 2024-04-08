/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 21
  光敏电阻传感器
  http://www.keyes-robot.com
*/
int val = 0;
int photoPin = A0;  //光敏电阻传感器接模拟口A0
void setup() {
  Serial.begin(9600);//设置波特率9600
}

void loop() {
  val = analogRead(photoPin);//读取传感器器的值
  Serial.println(val);//打印值
  delay(100);//延时100MS

}
