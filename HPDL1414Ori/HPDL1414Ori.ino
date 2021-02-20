void dispchar(int add,char data){    //add即是A0，A1，用来控制字符显示的位置，data即是D0~D6，用来控制对应位显示的字符
  switch (add) {                   //字符显示的位置
      case 0:
        digitalWrite(A0, 0);
        digitalWrite(D2, 0);
        break;
      case 1:
        digitalWrite(A0, 1);
        digitalWrite(D2, 0);
        break;
    case 2:
      digitalWrite(A0, 0);
        digitalWrite(D2, 1);
      break;
    case 3:
      digitalWrite(A0, 1);
        digitalWrite(D2, 1);
      break;
      default:
        digitalWrite(A0, 0);
        digitalWrite(D2, 0);
        break;
  }
  
  digitalWrite(D0, (data>>0) & 1);    //获取char的各个bit，即ASCii的后7个bits，将其分配至各自的引脚
  digitalWrite(D5, (data>>1) & 1);
  digitalWrite(D6, (data>>2) & 1);
  digitalWrite(D7, (data>>3) & 1);
  digitalWrite(D3, (data>>4) & 1);
  digitalWrite(D4, (data>>5) & 1);
  digitalWrite(D8, (data>>6) & 1);
 
  digitalWrite(D1,0);                  //拉低WR引脚，改变状态
  delay(1);                           //holdtime，使得触发器能够正确的采样各个引脚的电平（并不用这么久，实际只用200ns）
  digitalWrite(D1,1);                  //拉高WR引脚，防止已经成功保存的状态再次改变
}
 
void setup() {
  pinMode(D0,OUTPUT);  //D0 8 HPDL_1414的管脚功能 HPDL_1414的管脚编号
  pinMode(D1,OUTPUT);  //D1 9
  pinMode(D2,OUTPUT);  //D2 10
  pinMode(D3,OUTPUT);  //D3 11
  pinMode(D4,OUTPUT);  //D4 2
  pinMode(D5,OUTPUT);  //D5 1
  pinMode(D6,OUTPUT);  //D6 12
  
  pinMode(D7,OUTPUT);  //WR 3
  pinMode(D8,OUTPUT); //A0 5
  pinMode(A0,OUTPUT); //A1 4
}
 
void loop() {
  dispchar(3,'H');    //写入你需要让它显示的字符和位置即可，这里显示的是“HPDL”，大约一秒后显示“1414”
  dispchar(2,'P');
  dispchar(1,'D');
  dispchar(0,'L');
  delay(1000);
  dispchar(3,'1');
  dispchar(2,'4');
  dispchar(1,'1');
  dispchar(0,'4');
  delay(1000);
}
