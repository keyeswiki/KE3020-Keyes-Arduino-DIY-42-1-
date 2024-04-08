/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 59
  红外遥控灯
  http://www.keyes-robot.com
*/
#include <IRremote.h> //导入红外接收库文件
boolean flag = true;//LED标志位
long ir_rec;

IRrecv irrecv(8);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//LED管脚接PWM口5
  irrecv.enableIRIn();//使能红外接收
}

void loop() {
  if (irrecv.decode(&results)) {//接收到信号
    ir_rec = results.value; //信号赋给变量ir_rec
    Serial.print(ir_rec, HEX); //以十六进制打印变量ir_rec
    if (ir_rec == 0xFF02FD && flag == true) { //按下OK键并且flag为true
      digitalWrite(5, HIGH); //点亮LED
      Serial.print("   LED on");  //打印"   LED on"
      flag = false;//flag改为false，以便下次熄灭
    } else if (ir_rec == 0xFF02FD && flag == false) { //按下OK键并且flag为false
      digitalWrite(5, LOW); //关闭LED
      Serial.print("   LED Off");  //打印"   LED Off"
      flag = true;//flag改为true，以便下次点亮
    } else if (ir_rec == 0xFF6897) {  //按下1
      analogWrite(5, 80);
    } else if (ir_rec == 0xFF9867) {  //按下1
      analogWrite(5, 160);
    } else if (ir_rec == 0xFFB04F) {  //按下1
      analogWrite(5, 240);
    }
    Serial.println();//换行
    irrecv.resume();//下次接收
  }

}
