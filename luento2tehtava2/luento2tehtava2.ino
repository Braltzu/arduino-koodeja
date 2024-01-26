float tulos[10];
float summa=0;
float keskiarvo=0;
int x=0;
float voltage=0;
 
void setup() {
Serial.begin(9600);
}

void loop() {
lue10();
delay(500);

while(true){      //ikuinen looppi että käyttää ohjelman kerran läpi ja jää tähän
}
}

void lue10(){                   

for (x = 0; x < 10; x++) {
int sensorValue = analogRead(A0);
voltage = sensorValue * (5.0 / 1023.0); 
Serial.println(voltage);
tulos[x+1]=voltage;
delay(500);
}

summa=voltage + summa;
keskiarvo= summa / 10;
Serial.println("tulos on ");
Serial.println(keskiarvo);
}


