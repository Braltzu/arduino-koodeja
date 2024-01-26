`#include "PinChangeInterrupt.h"

#define BTN_PIN2  2
#define BTN_PIN3  3
void BTN_ISR2(void);
void BTN_ISR3(void);

void setup() {
  Serial.begin(9600);

  pinMode(BTN_PIN2, INPUT_PULLUP);
  pinMode(BTN_PIN3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN2), BTN_ISR2, FALLING);
  attachPCINT(digitalPinToPCINT(BTN_PIN3), BTN_ISR3, FALLING);
}
// keskeytykset etc ^^ ----------------------------------------

//      sekuntikello --------------
int stopwatch_running = 0;
const long interval = 1000;

unsigned long mainTime = 0;
unsigned long previousMillis = 0;

unsigned long current_Time = 0;

int processed_min = 0;
int processed_s = 0;
int sek_kym = 0;

void loop() {

  while(stopwatch_running == 1) {
    mainTime = millis();
    unsigned long elapsed_Time = mainTime - current_Time;

    if (mainTime - previousMillis >= interval) {
      previousMillis = mainTime;

      processed_min = (elapsed_Time/60000) % 60;
      processed_s = (elapsed_Time/1000) % 60;

      Serial.println(" ");
      Serial.print("Time: ");
      Serial.print(processed_min); Serial.print(" min(s) ");
      Serial.print(processed_s); Serial.println(" s");
    }
  }
}

void BTN_ISR2(void)
{
  stopwatch_running = 1; // on interrupt, set 1 = run
}

void BTN_ISR3(void)
{
  stopwatch_running = 0; // on interrupt, set 1 = stop
  sek_kym = (mainTime%1000)/100;

  // tulosta aika sekunnin kymmenyksen tarkkuudella ja nollaa kello
  Serial.println("**STOPPED AND RESETTED**"); 
  Serial.print("* Time elapsed: ");

  Serial.print(processed_min); Serial.print(" min(s) ");
  Serial.print(processed_s); Serial.print(".");
  Serial.print(sek_kym); Serial.println(" sec(s) *");

  current_Time = millis();
  // käynnistä uusi ajanotto reset-hetkestä
}`