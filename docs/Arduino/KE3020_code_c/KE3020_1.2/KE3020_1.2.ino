/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 1.2
  LED闪烁
  http://www.keyes-robot.com
*/
int ledPin = 3; //定义LED管脚接D3
void setup() {
  pinMode(ledPin, OUTPUT);//设置模式为输出
}

void loop() {
  digitalWrite(ledPin, HIGH); //输出高电平，点亮
  delay(1000);//延迟1000毫秒
  digitalWrite(ledPin, LOW); //输出低电平，熄灭
  delay(1000);

}
