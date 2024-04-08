/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 1.1
  点亮LED
  http://www.keyes-robot.com
*/
int ledPin = 3; //定义LED管脚接D3
void setup() {
  pinMode(ledPin, OUTPUT);//设置模式为输出
}

void loop() {
  digitalWrite(3, HIGH); //输出高电平，点亮

}
