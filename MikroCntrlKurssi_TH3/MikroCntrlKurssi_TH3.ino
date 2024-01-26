float tulos[10];
float summa=0;
float keskiarvo=0;

void setup() {
 Serial.begin(9600);
 }

void loop() {
 int sensorValue = analogRead(A0);
 float voltage = sensorValue * (5.0 / 1023.0);
  


for (int x = 0; x < 10; x++) {
 Serial.println(voltage);
 tulos[x+1]=voltage;
 summa=voltage + summa;
  delay(500);
}

  keskiarvo= summa / 10;
  Serial.println("tulos on ");
  Serial.println(keskiarvo);
  
 
 while(true){

 }

  
}