/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 7
  黑白巡线传感器
  http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置传感器引脚为输入模式
}

void loop() {
  val = digitalRead(3);//读取巡线传感器输出的数字电平
  Serial.print(val);//串口打印值
  if (val == 0) {//检测到白色val为0
    Serial.print("        ");
    Serial.println("White");
    delay(100);
  }
  else {//检测到黑色val为1
    Serial.print("        ");
    Serial.println("Black");
    delay(100);
  }
}
