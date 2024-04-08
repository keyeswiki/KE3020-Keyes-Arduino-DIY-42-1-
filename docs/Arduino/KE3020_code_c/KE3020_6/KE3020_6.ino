/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 6
  红外避障传感器
  http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置引脚3为输入模式
}

void loop() {
  val = digitalRead(3);//读取数字电平
  Serial.print(val);//打印读取的电平信号
  if (val == 0) {//检测到障碍物
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else {//没检测到障碍物
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
