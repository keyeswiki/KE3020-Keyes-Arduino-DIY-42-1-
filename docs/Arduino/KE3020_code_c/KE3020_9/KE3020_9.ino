/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 9
  倾斜传感器
  http://www.keyes-robot.com
*/
int val; //存放倾斜传感器输出的电平值

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);  //倾斜传感器管脚接数字口3，设置D3为输入模式
}

void loop() {
  val = digitalRead(3); //读取模块的电平信号
  Serial.println(val);  //换行打印出来
  delay(100); //延时100毫秒

}
