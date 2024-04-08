/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 26
  MQ-3酒精传感器
  http://www.keyes-robot.com
*/
//酒精传感器两个管脚，分别接A0、A1，这里A0作为数字口用
int digitalPin =  A0;
int analogPin = A1;
//以下两个变量分别存放数字信号与模拟信号
int analogVal = 0;
int digitalVal = 0;

void setup() {
  Serial.begin(9600); //设置波特率为9600
  pinMode(digitalPin, INPUT); //数字引脚A0设置为输入模式
}

void loop() {
  analogVal = analogRead(analogPin);  //读取模拟信号
  digitalVal = digitalRead(digitalPin);  //读取数字信号
  Serial.print(analogVal);
  if (digitalVal == 1) {
    Serial.println("    Normal");
  }
  else {
    Serial.println("    Exceeding");
  }
  delay(100); //延时100毫秒

}
