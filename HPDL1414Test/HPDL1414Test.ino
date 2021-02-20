//引脚定义; WR1 WR2分别对应第一和第二块屏的WR引脚
#define HPDLD0 D0
#define HPDLD1 D1
#define HPDLD2 D2
#define HPDLD3 D3
#define HPDLD4 D4
#define HPDLD5 D5
#define HPDLD6 D6
#define HPDLA0 D7
#define HPDLA1 D8
#define HPDLWR1 TX
#define HPDLWR2 RX

void dispchar1(int add,char data){    //add即是A0，A1，用来控制字符显示的位置，data即是D0~D6，用来控制对应位显示的字符
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
  
  digitalWrite(HPDLD0, (data>>0) & 1);    //获取char的各个bit，即ASCii的后7个bits，将其分配至各自的引脚
  digitalWrite(HPDLD1, (data>>1) & 1);
  digitalWrite(HPDLD2, (data>>2) & 1);
  digitalWrite(HPDLD3, (data>>3) & 1);
  digitalWrite(HPDLD4, (data>>4) & 1);
  digitalWrite(HPDLD5, (data>>5) & 1);
  digitalWrite(HPDLD6, (data>>6) & 1);
    
  digitalWrite(HPDLWR1,0);                  //拉低WR引脚，改变状态
  delayMicroseconds(1);
  //delay(1);                         //holdtime，使得触发器能够正确的采样各个引脚的电平（并不用这么久，实际只用200ns）
  digitalWrite(HPDLWR1,1);                  //拉高WR引脚，防止已经成功保存的状态再次改变 
}

void dispchar2(int add,char data){    //add即是A0，A1，用来控制字符显示的位置，data即是D0~D6，用来控制对应位显示的字符
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
  
  digitalWrite(HPDLD0, (data>>0) & 1);    //获取char的各个bit，即ASCii的后7个bits，将其分配至各自的引脚
  digitalWrite(HPDLD1, (data>>1) & 1);
  digitalWrite(HPDLD2, (data>>2) & 1);
  digitalWrite(HPDLD3, (data>>3) & 1);
  digitalWrite(HPDLD4, (data>>4) & 1);
  digitalWrite(HPDLD5, (data>>5) & 1);
  digitalWrite(HPDLD6, (data>>6) & 1);
    
  digitalWrite(HPDLWR2,0);                  //拉低WR引脚，改变状态
  delayMicroseconds(1);
  //delay(1);                         //holdtime，使得触发器能够正确的采样各个引脚的电平（并不用这么久，实际只用200ns）
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
  digitalWrite(HPDLA0, 0);
  digitalWrite(HPDLA1, 0);

  dispchar1(3,'*'); 
  dispchar1(2,'*');
  dispchar1(1,'*');
  dispchar1(0,'*');
  dispchar2(3,'*');
  dispchar2(2,'*');
  dispchar2(1,'*');
  dispchar2(0,'*');
  delay(1000);
}
 
void loop() {
//  dispchar1(3,'H');  
//  delay(100);
//  dispchar1(2,'P');
//  delay(100);
//  dispchar1(1,'D');
//  delay(100);
//  dispchar1(0,'L');
//  delay(100);
//  dispchar2(3,'1');
//  delay(100);
//  dispchar2(2,'4');
//  delay(100);
//  dispchar2(1,'1');
//  delay(100);
//  dispchar2(0,'4');
//  delay(200);
//
//  dispchar1(3,'O');
//  delay(100);
//  dispchar1(2,'O');
//  delay(100);
//  dispchar1(1,'O');
//  delay(100);
//  dispchar1(0,'O');
//  delay(100);
//  dispchar2(3,'O');
//  delay(100);
//  dispchar2(2,'O');
//  delay(100);
//  dispchar2(1,'O');
//  delay(100);
//  dispchar2(0,'O');
//  delay(200);
//  
//  dispchar1(3,'*'); 
//  delay(100);
//  dispchar1(2,'*');
//  delay(100);
//  dispchar1(1,'*');
//  delay(100);
//  dispchar1(0,'*');
//  delay(100);
//  dispchar2(3,'*');
//  delay(100);
//  dispchar2(2,'*');
//  delay(100);
//  dispchar2(1,'*');
//  delay(100);
//  dispchar2(0,'*');
//  delay(200);

//  dispchar1(3,'O');
//  dispchar1(2,'O');
//  dispchar1(1,'O');
//  dispchar1(0,'O');
//  dispchar2(3,'O');
//  dispchar2(2,'O');
//  dispchar2(1,'O');
//  dispchar2(0,'O'); 
//  delay(200);
  
  dispchar1(3,'*'); 
  dispchar1(2,'*');
  dispchar1(1,'*');
  dispchar1(0,'*');
  dispchar2(3,'*');
  dispchar2(2,'*');
  dispchar2(1,'*');
  dispchar2(0,'*');
  delay(1);
  dispchar1(3,' '); 
  dispchar1(2,' ');
  dispchar1(1,' ');
  dispchar1(0,' ');
  dispchar2(3,' ');
  dispchar2(2,' ');
  dispchar2(1,' ');
  dispchar2(0,' ');
  delay(2);
}
