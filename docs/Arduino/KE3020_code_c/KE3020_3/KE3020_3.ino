/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 3
  激光模块
  http://www.keyes-robot.com
*/
int laserPin = 2; //定义激光引脚为D2
void setup() {
  pinMode(laserPin, OUTPUT);//定义激光引脚为输出模式
}

void loop() {
  digitalWrite(laserPin, HIGH); //打开激光
  delay(2000);  //延时2秒
  digitalWrite(laserPin, LOW); //关闭激光
  delay(2000);  //延时2秒

}
