/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 20
  声音传感器
  http://www.keyes-robot.com
*/
int val = 0;
int Microphone = A0;  //麦克风传感器接A0
void setup() {
  Serial.begin(9600);//设置波特率9600
}

void loop() {
  val = analogRead(Microphone); //读取传感器的值赋给变量val
  Serial.println(val);  //换行打印传感器输出的模拟值
  delay(100); //加延时100MS

}
