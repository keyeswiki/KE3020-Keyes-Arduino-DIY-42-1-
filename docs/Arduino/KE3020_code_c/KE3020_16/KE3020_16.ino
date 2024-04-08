/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 16
  130电机模块
  http://www.keyes-robot.com
*/
//定义电机的两个管脚接口，分别为A0, A1
int INA = A0;
int INB = A1;
void setup() {
  //设置电机引脚为输出
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void loop() {
  //逆时针转
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  delay(2000);
  //停止
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(1000);
  //顺时针转
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(2000);
  //停止
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(1000);

}
