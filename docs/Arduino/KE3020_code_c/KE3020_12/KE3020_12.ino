/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 12
  干簧管模块
  http://www.keyes-robot.com
*/
int val = 0;
int reedPin = 5; //定义干簧管模块信号管脚接数字口D5
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(reedPin, INPUT);//设置模式为输入
}

void loop() {
  val = digitalRead(reedPin);//读取数字电平
  Serial.print(val);//串口显示出来

  if (val == 0) {//附近存在磁场
    Serial.print("        ");
    Serial.println("A magnetic  field");
    delay(100);
  }
  else {//无磁场
    Serial.print("        ");
    Serial.println("There is no magnetic field");
    delay(100);
  }
}
