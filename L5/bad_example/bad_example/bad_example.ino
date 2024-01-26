
// Huono esimerkki!

int number = 0;

void add1();
void add5();
void dec1();

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2)==0)
    add1();
  if (digitalRead(3)==0)
    add5();
  delay(1000);
  dec1(); 
  Serial.println(number);
}

void add1(){
  number +=1;
}

void add5(){
    number +=5;
}

void dec1(){
    number -=1;
}