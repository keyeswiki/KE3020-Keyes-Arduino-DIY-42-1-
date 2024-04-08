/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 10
  碰撞传感器
  http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(4, INPUT);//设置碰撞传感器引脚D4为输入模式
}

void loop() {
  val = digitalRead(4);//读取碰撞传感器的值
  Serial.print(val);//换行打印出来
  if (val == 0) {//碰撞到了val为0
    Serial.print("        ");
    Serial.println("The end of his!");
    delay(100);
  }
  else {//没碰撞val为1
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
