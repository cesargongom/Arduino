int r1 = 8;
int r2 = 9;
int r3 = 10;
int r4 = 11;
int r = 6;
int l = 7;

void setup() {
  // put your setup code here, to run once:

  pinMode (r1, OUTPUT);
  pinMode (r2, OUTPUT);
  pinMode (r3, OUTPUT);
  pinMode (r4, OUTPUT);
  pinMode (l,INPUT);
  pinMode (r, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int r_value = digitalRead (r);
  int l_value = digitalRead (l);
  
  if (l_value == 0 && r_value == 1){
    digitalWrite (r1, HIGH);
    digitalWrite (r2, HIGH);
    digitalWrite (r3, LOW);
    digitalWrite (r4, HIGH);
  }
  else if (l_value == 1 && r_value == 0){
    digitalWrite (r1, HIGH);
    digitalWrite (r2, HIGH);
    digitalWrite (r3, HIGH);
    digitalWrite (r4, LOW);
  }
  else{
    digitalWrite (r1, HIGH);
    digitalWrite (r2, HIGH);
    digitalWrite (r3, LOW);
    digitalWrite (r4, LOW);  
  }

  


}
