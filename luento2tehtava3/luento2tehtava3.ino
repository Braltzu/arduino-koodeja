float tulos[10];
float voltage =0;
float summa=0;
float keskiarvo=0;
int x=0;
float maxVal = tulos[10];
float minVal = tulos[10];

void setup() {
Serial.begin(9600);
}

void loop() {
delay(1000);
aliohjelma(); 

while(true){      //ikuinen looppi että käyttää ohjelman kerran läpi ja jää tähän
}
}



void aliohjelma(){

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
//Serial.print("Size of myArray is: "); Serial.println(sizeof(tulos));

for (int i = 0; i < (sizeof(tulos) / sizeof(tulos[10])); i++) {
maxVal = max(tulos[i],maxVal);
minVal = min(tulos[i],minVal);
}

Serial.print("isoin luku: ");
Serial.println(maxVal);
Serial.print("pienin luku: ");
Serial.println(minVal);
}




   
/*
  Tee aliohjelma, joka lukee 10 A/D-näytettä taulukkoon ADnaytteet.
  Tämän jälkeen aliohjelma etsii näytteistä suurimman ja pienimmän alkion
  sekä laskee 10 näytteen keskiarvon. Lopuksi aliohjelma palauttaa
  laskemansa 3 arvoa kutsujalle.

  Vinkki: Koska C-aliohjelmasta voi return käskyllä palauttaa vain
          yhden paluuarvon voit tehdä tuosta paluuarvosta structin,
          joka sisältää nuo kolme arvoa. Tai voit välittää aliohjelmalle
          kolme pointteria, joiden avulla aliohjelma voi tallentaa tulokset
          pointtereiden osoittamiin muistipaikkoihin, jotka aliohjelman
          kutsuja on allokoinut.

  Vinkki2: Tehtävässä ei ole nyt annettu aliohjelman prototyyppiä = esittelyä
           eikä aliohjelman runkoa valmiina, mutta voit katsoa mallia edellisestä
           tehtävästä.
*/

/* 
  toteuta tähän tekemäsi aliohjelman kutsu
  ja kolmen arvon tulostus sarjaväylän kautta PC:lle
  */
