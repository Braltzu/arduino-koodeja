void setup() {
PinMode(12, INPUT_PULLUP);
PinMode(13, INPUT_PULLUP);
Serial.begin(9600);

}

void loop() {
if(12==LOW);

}
timeri(); {
unsigned long runMillis= millis();
unsigned long allSeconds=millis()/1000;
int runHours= allSeconds/3600;
int secsRemaining=allSeconds%3600;
int runMinutes=secsRemaining/60;
int runSeconds=secsRemaining%60;

char buf[21];
sprintf(buf,"Runtime%02d:%02d:%02d",runHours,runMinutes,runSeconds);
Serial.println(buf);
delay(999);
}
