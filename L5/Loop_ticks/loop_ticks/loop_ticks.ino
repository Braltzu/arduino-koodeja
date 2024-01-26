
void kerran_sekunnissa();
void kolmesssa_sekunnissa();

volatile unsigned long int ticks = 0;
volatile unsigned long int kerran_prev_ticks = 0;
volatile unsigned long int kolmessa_prev_ticks = 0;
int tila = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  TCCR2A = 0; // Normal mode, no output compare signals
  TCCR2B = (1<<CS22)|(1<<CS21)|(1<<CS20); // Prescaler 1024
  TIMSK2 = (1<< TOIE2); // Enable overflow interrupt
  // This should result in approx 61Hz timer2 overflow rate


}

void loop() {
  int incomingByte = 0 ;

  if (ticks > kerran_prev_ticks + 61 )
  {
    kerran_sekunnissa();
    kerran_prev_ticks = ticks;
  }

  if (ticks > kolmessa_prev_ticks + 122  && tila == 1)
  {
    kolmessa_sekunnissa();
    kolmessa_prev_ticks = ticks;
  }

  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte == 'b'){
      Serial.println("Begin!");
      tila = 1;
    }
    else if (incomingByte == 'e'){
      Serial.println("End!");
      tila = 0;
    }      
  }

}

// Interrupt Service Routine = Keskeytyspalvelija
ISR (TIMER2_OVF_vect){
  ticks +=1;
}

void kerran_sekunnissa()
{
  Serial.println("Sekunti!");

}


void kolmessa_sekunnissa()
{
    Serial.println("Ajetaan!");
}