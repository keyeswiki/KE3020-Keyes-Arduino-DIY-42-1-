/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 47
  人体红外报警
  http://www.keyes-robot.com
*/
int item = 0;
void setup() {
  pinMode(9, INPUT);  //人体红外传感器接数字口9并设置为为输入模式
  pinMode(3, OUTPUT);//有缘蜂鸣器接数字口3并设置为为输出模式
}

void loop() {
  item = digitalRead(9);//读取红外热释传感器输出的数字电平信号
  if (item == 1) {  //检测到有人运动
    digitalWrite(3, HIGH); //打开蜂鸣器
  } else {  //没有检测到
    digitalWrite(3, LOW); //关闭蜂鸣器
  }
}
