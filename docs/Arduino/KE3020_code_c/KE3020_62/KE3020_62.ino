/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 62
  综合实验
  http://www.keyes-robot.com
*/
#include <Wire.h>//IIC文件
#include <Adafruit_NeoPixel.h>//6812的库
#include <ADXL345.h>//加速度传感器的库
#include <I2Cdev.h>
#include <IRremote.h>//红外接收的库
#include <dht11.h> //dht11的库

//rgb6812接数字口8
Adafruit_NeoPixel  rgb_display(8);

//红外接收接数字口11
IRrecv irrecv(11);
decode_results results;

//定义DHT11为数子口5
dht11 DHT;
#define DHT11_PIN 5

//摇杆模块接口
int X = A3;
int Y = A2;
int KEY = 7;

//加速度传感器使用IIC接口
ADXL345 accel;

//电位器管脚接模拟口A0
int resPin = A0;

//LED接数字口9
int LED = 9;

//光敏电阻模块接模拟口A1
int light_pin = A1;

//超声波传感器接口
int Trig = 12;
int Echo = 13;

//按键模块接口
int button = 2;

int PushCounter = 0;//存放按键按下的次数
int State = 1;//按键的状态
int LastState = 1;//上一个状态，要么按下，要么松开，两种状态
int PushCounter1 = 0;//对PushCounter取余后的值

void setup() {
  Serial.begin(9600);//设置波特率为9600
  rgb_display.begin();
  rgb_display.setPin(8);
  irrecv.enableIRIn();//使能红外接收
  pinMode(KEY, INPUT);//遥感模块的按钮

  Wire.begin();
  accel.initialize();

  pinMode(button, INPUT);//按键模块

  pinMode(Trig, OUTPUT);//超声波模块
  pinMode(Echo, INPUT);

}

void loop() {
  State = digitalRead(button);//读取按键模块的状态
  if (LastState != State) { //按键的状态改变了
    if (State == 0) { //按下了按键
      PushCounter = PushCounter + 1;  //累计按下次数加1
    }
  }
  LastState = State;//刷新上一次状态
  PushCounter1 = PushCounter % 8; //对按下状态对8取余，也就是按8次就重新开始
  if (PushCounter1 == 0) {  //余数为0
    yushu_0();  //6812显示
  } else if (PushCounter1 == 1) {  //余数为1
    yushu_1();  //显示红外遥控信号
  } else if (PushCounter1 == 2) {  //余数为2
    yushu_2();  //显示温湿度值
  } else if (PushCounter1 == 3) {  //余数为3
    yushu_3();  //显示摇杆值
  } else if (PushCounter1 == 4) {  //余数为4
    yushu_4();  //显示三轴加速度值
  } else if (PushCounter1 == 5) {  //余数为5
    yushu_5();  //显示电位器控制LED
  } else if (PushCounter1 == 6) {  //余数为6
    yushu_6();  //显示光敏模拟值
  } else if (PushCounter1 == 7) {  //余数为7
    yushu_7();  //显示超声波测的距离
  }
}

//6812
void yushu_0() {
  int R = random(0, 255);
  int G = random(0, 255);
  int B = random(0, 255);
  rgb_display.setPixelColor(0, R, G, B);
  rgb_display.show();
  rgb_display.setPixelColor(1, R, G, B);
  rgb_display.show();
  rgb_display.setPixelColor(2, R, G, B);
  rgb_display.show();
  rgb_display.setPixelColor(3, R, G, B);
  rgb_display.show();
  delay(300);
}

//红外接收
void yushu_1() {
  if (irrecv.decode(&results)) {
    long ir_rec = results.value;
    Serial.println(ir_rec, HEX);
    irrecv.resume();
  }
}

void yushu_2() {
  int chk = DHT.read(DHT11_PIN);    // 读取数据
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM: //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT: //超时错误返回
      break;
    default:
      break;
  }
  //打印数据
  Serial.print("Temperature:");
  Serial.print(DHT.temperature);
  Serial.print("C    ");
  Serial.print("Humidity:");
  Serial.print(DHT.humidity);
  Serial.println("%");
  delay(100);
}

void yushu_3() {
  int x = analogRead(A3);
  int y = analogRead(A2);
  int key = digitalRead(KEY);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("    Y:");
  Serial.print(y);
  Serial.print("    KEY:");
  Serial.println(key);
  delay(100);
}

void yushu_4() {
  float ADXL345_X = accel.getAccelerationX();
  float ADXL345_Y = accel.getAccelerationY();
  float ADXL345_Z = accel.getAccelerationZ();
  Serial.print("ADXL345_X:");
  Serial.print(ADXL345_X);
  Serial.print("    ADXL345_Y:");
  Serial.print(ADXL345_Y);
  Serial.print("    ADXL345_Z:");
  Serial.println(ADXL345_Z);
  delay(50);
}

void yushu_5() {
  int RES = analogRead(resPin);
  int res = map(RES, 0, 1023, 0, 255);
  Serial.println(res);
  analogWrite(LED, res);
  delay(100);
}

void yushu_6() {
  int light = analogRead(light_pin);
  Serial.println(light);
  delay(100);
}

void yushu_7() {
  float distance = checkdistance();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}
