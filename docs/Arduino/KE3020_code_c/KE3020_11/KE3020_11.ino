/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 11
  霍尔传感器
  http://www.keyes-robot.com
*/
int val = 0;
int hallPin = 5;  //霍尔传感器管脚接数字口5
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(hallPin, INPUT);//设置管脚模式为输入模式
}

void loop() {
  val = digitalRead(hallPin);//读取霍尔传感器的电平值
  Serial.print(val);//打印val
  if (val == 0) {//存在南极磁场
    Serial.println("      The magnetic field at the South Pole!");
  }
  else {//否则
    Serial.println("      Just be all normal!");
  }
}
