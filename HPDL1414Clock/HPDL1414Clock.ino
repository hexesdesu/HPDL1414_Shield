//引脚定义; WR1 WR2分别对应第一和第二块屏的WR引脚
#define HPDLD0 D0
#define HPDLD1 D1
#define HPDLD2 D2
#define HPDLD3 D3
#define HPDLD4 D4
#define HPDLD5 D5
#define HPDLD6 D6
#define HPDLA1 D7
#define HPDLA0 D8
#define HPDLWR1 TX
#define HPDLWR2 RX
#define LDRPIN A0

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
#include <NTPClient.h>               // Include NTPClient library
#include <TimeLib.h>                 // Include Arduino time library
 
const char* ssid  = "DynamicOP";
const char* password = "DynamicOP";
int ldrValue = 0;
 
WiFiUDP ntpUDP;
 
// 'time.nist.gov' is used (default server) with +1 hour offset (3600 seconds) 60 seconds (60000 milliseconds) update interval
NTPClient timeClient(ntpUDP, "cn.pool.ntp.org", 8*3600, 60000);
 
char Time[] = "00:00:00";
char Date[] = "20/00/00";
byte last_second, second_, minute_, hour_, day_, month_;
int year_;

void dispchar1(int add,char data1){    //add即是A0，A1，用来控制字符显示的位置，data即是D0~D6，用来控制对应位显示的字符
  switch (add) {                   //字符显示的位置
      case 0:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 0);
        break;
      case 1:
        digitalWrite(HPDLA0, 1);
        digitalWrite(HPDLA1, 0);
        break;
    case 2:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 1);
      break;
    case 3:
        digitalWrite(HPDLA0, 1);
        digitalWrite(HPDLA1, 1);
      break;
      default:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 0);
        break;
  }
  
  digitalWrite(HPDLD0, (data1>>0) & 1);    //获取char的各个bit，即ASCii的后7个bits，将其分配至各自的引脚
  digitalWrite(HPDLD1, (data1>>1) & 1);
  digitalWrite(HPDLD2, (data1>>2) & 1);
  digitalWrite(HPDLD3, (data1>>3) & 1);
  digitalWrite(HPDLD4, (data1>>4) & 1);
  digitalWrite(HPDLD5, (data1>>5) & 1);
  digitalWrite(HPDLD6, (data1>>6) & 1);
    
  digitalWrite(HPDLWR1,0);                  //拉低WR引脚，改变状态
  delayMicroseconds(1);
  //delay(1);                           //holdtime，使得触发器能够正确的采样各个引脚的电平（并不用这么久，实际只用200ns）
  digitalWrite(HPDLWR1,1);                  //拉高WR引脚，防止已经成功保存的状态再次改变 
}

void dispchar2(int add,char data2){    //add即是A0，A1，用来控制字符显示的位置，data即是D0~D6，用来控制对应位显示的字符
  switch (add) {                   //字符显示的位置
      case 0:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 0);
        break;
      case 1:
        digitalWrite(HPDLA0, 1);
        digitalWrite(HPDLA1, 0);
        break;
    case 2:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 1);
      break;
    case 3:
        digitalWrite(HPDLA0, 1);
        digitalWrite(HPDLA1, 1);
      break;
      default:
        digitalWrite(HPDLA0, 0);
        digitalWrite(HPDLA1, 0);
        break;
  }
  
  digitalWrite(HPDLD0, (data2>>0) & 1);    //获取char的各个bit，即ASCii的后7个bits，将其分配至各自的引脚
  digitalWrite(HPDLD1, (data2>>1) & 1);
  digitalWrite(HPDLD2, (data2>>2) & 1);
  digitalWrite(HPDLD3, (data2>>3) & 1);
  digitalWrite(HPDLD4, (data2>>4) & 1);
  digitalWrite(HPDLD5, (data2>>5) & 1);
  digitalWrite(HPDLD6, (data2>>6) & 1);
    
  digitalWrite(HPDLWR2,0);                  //拉低WR引脚，改变状态
  delayMicroseconds(1);
  //delay(1);                          //holdtime，使得触发器能够正确的采样各个引脚的电平（并不用这么久，实际只用200ns）
  digitalWrite(HPDLWR2,1);                  //拉高WR引脚，防止已经成功保存的状态再次改变 
}
 
void setup() {
  pinMode(HPDLD0,OUTPUT);
  pinMode(HPDLD1,OUTPUT);
  pinMode(HPDLD2,OUTPUT);
  pinMode(HPDLD3,OUTPUT); 
  pinMode(HPDLD4,OUTPUT);
  pinMode(HPDLD5,OUTPUT);
  pinMode(HPDLD6,OUTPUT);
  pinMode(HPDLA0,OUTPUT);
  pinMode(HPDLA1,OUTPUT); 
  pinMode(HPDLWR1,OUTPUT);
  pinMode(HPDLWR2,OUTPUT); 
  WiFi.begin(ssid, password);
  
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(200);
    dispchar1(3,'?'); 
    dispchar2(3,'?'); 
    delay(200);
    dispchar1(3,' '); 
    dispchar2(3,' '); 
  }
  dispchar2(0,'!'); 
  timeClient.begin();
  delay(1000);
}
 
void loop() {
  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();    // Get Unix epoch time from the NTP server

  second_ = second(unix_epoch);
  if (last_second != second_) {
    minute_ = minute(unix_epoch);
    hour_   = hour(unix_epoch);

    dispchar2(0,char(second_ % 10 + 48)); 
    dispchar2(1,char(second_ / 10 + 48)); 
    dispchar2(2,':'); 
    dispchar2(3,char(minute_ % 10 + 48)); 
    dispchar1(0,char(minute_ / 10 + 48)); 
    dispchar1(1,':'); 
    dispchar1(2,char(hour_   % 10 + 48)); 
    dispchar1(3,char(hour_   / 10 + 48)); 
 
    last_second = second_;
  }
  
  delay(200);

  ldrValue = analogRead(LDRPIN);
  if (ldrValue < 512) {
    delay(800);
    }
  else {
    delay(300);
    dispchar2(2,'-'); 
    dispchar1(1,'-'); 
    delay(500);
  }
  
  


  //delay(500);

}
