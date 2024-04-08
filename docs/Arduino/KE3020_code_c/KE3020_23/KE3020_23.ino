/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 23
  薄膜压力传感器
  http://www.keyes-robot.com
*/
int val = 0;
int Film = A0; //薄膜压力传感器接A0
void setup() {
  Serial.begin(9600);//设置波特率为9600
}
void loop() {
  val = analogRead(Film);//读取模拟值
  Serial.println(val);//打印模拟值
  delay(100);//延时100MS

}
