
void t1();
void t2();
void parse_serial();

volatile unsigned long int ticks = 0;
volatile unsigned long int prev_ticks = 0;

void (*fpointer[2])();

// {osoite 1, osoite 2}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  TCCR2A = 0; // Normal mode, no output compare signals
  TCCR2B = (1<<CS22)|(1<<CS21)|(1<<CS20); // Prescaler 1024
  TIMSK2 = (1<< TOIE2); // Enable overflow interrupt
  // This should result in approx 61Hz timer2 overflow rate
  fpointer[0] = NULL;
  fpointer[1] = NULL;


}

void loop() {
  parse_serial();
  if (ticks > prev_ticks + 61 ){
    prev_ticks = ticks;
    for (int n = 0; n < 2; n++)
    {
      if (fpointer[n] != NULL)
        (*fpointer[n])();
    }
  }
}



ISR (TIMER2_OVF_vect){
  ticks +=1;
}

void parse_serial()
{
  int incomingByte = 0 ;
  while (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte == '1')
      if (fpointer[0] == NULL){
        fpointer[0] = &t1;
        Serial.println("Start T1.");
      }
      else{
        fpointer[0] = NULL;  
        Serial.println("Stop T1.");
      }
    if (incomingByte == '2'){

      if (fpointer[1] == NULL){
        fpointer[1] = &t2;
        Serial.println("Start T2.");
      }
      else{
        fpointer[1] = NULL;  
        Serial.println("Stop T2.");
      }
    }
  }
}

void t1()
{
  Serial.println("Running task 1.");
  delay(100);

}


void t2()
{
    Serial.println("Running task 2.");
    delay(100);
}