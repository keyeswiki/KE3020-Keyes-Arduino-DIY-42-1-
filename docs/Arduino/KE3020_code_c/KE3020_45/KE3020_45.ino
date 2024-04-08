/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 45
  障碍物报警
  http://www.keyes-robot.com
*/
int item = 0;
void setup() {
  pinMode(8, INPUT);  //避障传感器接数字口8并设置为输入模式
  pinMode(3, OUTPUT); //蜂鸣器接数字口3并设置为输出模式
}

void loop() {
  item = digitalRead(8);//读取避障传感器输出的电平值
  if (item == 0) {//检测到障碍物
    digitalWrite(3, HIGH);//蜂鸣器响起
  } else {//没有检测到障碍物
    digitalWrite(3, LOW);//蜂鸣器关闭
  }
  delay(100);//延时100ms

}
