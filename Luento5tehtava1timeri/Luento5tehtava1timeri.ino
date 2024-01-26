//x=0;

void setup() {
Serial.begin(9600);

}

void loop() {
int MS=millis();
//Serial.println(MS);

int second= MS/1000;
Serial.println(second);
delay(999);
int runHours=second%3600;
Serial.println(runHours);
delay(999);
}
