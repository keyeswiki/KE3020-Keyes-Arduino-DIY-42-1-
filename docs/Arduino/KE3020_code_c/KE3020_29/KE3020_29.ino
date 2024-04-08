/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 29
  太阳紫外线传感器
  http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(A3, INPUT);//设置传感器的PIN输入模式
}

void loop() {
  val = analogRead(A3);//读取电平
  Serial.println(val);//打印模拟电平
  delay(100);

}
