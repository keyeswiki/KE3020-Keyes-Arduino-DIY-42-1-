/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 5
  电容触摸传感器
  http://www.keyes-robot.com
*/
int val = 0;
int button = 3; //按键的PIN
void setup() {
  Serial.begin(9600);//波特率为9600
  pinMode(button, INPUT);//设置输入模式
}

void loop() {
  val = digitalRead(button);//读取按键的值
  Serial.print(val);//打印出来按键值
  if (val == 1) {//按下为高电平
    Serial.print("        ");
    Serial.println("Press the button");
    delay(100);
  }
  else {//松开为低电平
    Serial.print("        ");
    Serial.println("Loosen the button");
    delay(100);
  }
}
