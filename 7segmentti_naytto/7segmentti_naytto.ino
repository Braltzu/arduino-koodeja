void setup() {
  //serialBegin(9600);
 pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {
 
// S kirjain
digitalWrite(8, HIGH);
digitalWrite(2, HIGH);
//digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
//digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(1000);

digitalWrite(8, LOW);
digitalWrite(2, LOW);
//digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
//digitalWrite(6, LOW);
digitalWrite(7, LOW);


// A kirjain
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
//digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(1000);


digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);

// K=C kirjain
digitalWrite(2, HIGH);
//digitalWrite(3, HIGH);
//digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
//digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(1000);

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);

// U kirjain
//digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
//digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(1000);

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);

}
