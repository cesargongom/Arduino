int echo = 7;int trig = 6;int t;int d;

int del_d_me=A5;  int del_d_ma=A4;
int det_d_me=A3;  int det_d_ma=A2;
int del_i_me=9;  int del_i_ma=5;
int det_i_me=11; int det_i_ma=10;

int bn_delante=13; int bn_detras=12;
int valor_del; int valor_det;

void setup() {
  // put your setup code here, to run once:
  pinMode(del_d_me,OUTPUT);  pinMode(del_d_ma,OUTPUT);
  pinMode(del_i_me,OUTPUT);  pinMode(del_i_ma,OUTPUT);
  pinMode(det_d_me,OUTPUT);  pinMode(det_d_ma,OUTPUT);
  pinMode(det_i_me,OUTPUT);  pinMode(det_i_ma,OUTPUT);
  
  pinMode(bn_delante,INPUT); pinMode(bn_detras,INPUT);
  
  pinMode(echo,INPUT); pinMode (trig,OUTPUT);

  Serial.begin(9600);
  
}

void delante(){
  digitalWrite (det_d_me,LOW);  digitalWrite (det_d_ma,HIGH);  
  digitalWrite (det_i_me,LOW);  digitalWrite (det_i_ma,HIGH);
  digitalWrite (del_d_me,LOW);  digitalWrite (del_d_ma,HIGH);  
  digitalWrite (del_i_me,LOW);  digitalWrite (del_i_ma,HIGH);
}

void detras(){ 
  digitalWrite (det_d_me,HIGH);  digitalWrite (det_d_ma,LOW);  
  digitalWrite (det_i_me,HIGH);  digitalWrite (det_i_ma,LOW);
  digitalWrite (del_d_me,HIGH);  digitalWrite (del_d_ma,LOW);  
  digitalWrite (del_i_me,HIGH);  digitalWrite (del_i_ma,LOW);
}
void girar(){
  digitalWrite (det_d_me,LOW);  digitalWrite (det_d_ma,HIGH);  
  digitalWrite (del_d_me,LOW);  digitalWrite (del_d_ma,HIGH);  
  digitalWrite (det_i_me,HIGH);  digitalWrite (det_i_ma,LOW);
  digitalWrite (del_i_me,HIGH);  digitalWrite (del_i_ma,LOW);
}

  


void loop() {
  // put your main code here, to run repeatedly:

  valor_del=digitalRead(bn_delante);
  valor_det=digitalRead(bn_detras);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);         
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  Serial.println(valor_det);

  if (valor_det==0){
    if (d<25){
      delante();
      if (valor_del==1){
        delay(400);
        detras();
        delay(500);
      }
    }
    else{
      girar();
    }
  }
  else if (valor_det==1){
      delante();
    }
  
}
