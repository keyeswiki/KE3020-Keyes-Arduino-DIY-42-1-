/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 28
  摇杆模块
  http://www.keyes-robot.com
*/
int X = 0;
int Y = 0;
int Button = 0;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);  //定义遥感按钮的PIN为数字口7
}

void loop() {
  X = analogRead(A3); //遥感的X轴引脚接模拟值A3
  Y = analogRead(A2); //遥感的Y轴引脚接模拟值A2
  Button = digitalRead(7);  //读取按钮的状态，并在下方打印出来
  Serial.write("X:");
  Serial.print(X);
  Serial.write("     Y:");
  Serial.print(Y);
  Serial.write("     B:");
  Serial.println(Button);
  delay(100);

}
