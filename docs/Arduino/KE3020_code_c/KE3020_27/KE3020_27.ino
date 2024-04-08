/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 27
  五路按键模块
  http://www.keyes-robot.com
*/
int val = 0;
int ADkey = A2; //定义五路AD按键接模拟口A2
void setup() {
  Serial.begin(9600); //设置波特率为9600
}

void loop() {
  val = analogRead(ADkey);  //读取AD按键的模拟值并赋给变量val
  Serial.print(val);  //换行打印变量val
  if (val <= 100) { //没有按键按下时，val小于等于100
    Serial.println("   no key  is pressed");

  } else if (val <= 300) { //按键5按下时，val在100到300之间
    Serial.println("   SW5 is pressed");
  } else if (val <= 500) { //按键4按下时，val在300到500之间
    Serial.println("   SW4 is pressed");
  } else if (val <= 700) { //按键3按下时，val在500到700之间
    Serial.println("   SW3 is pressed");
  } else if (val <= 900) { //按键2按下时，val在700到900之间
    Serial.println("   SW2 is pressed");
  } else {  //按键1按下时，val大于900
    Serial.println("   SW1 is pressed");
  }

}
