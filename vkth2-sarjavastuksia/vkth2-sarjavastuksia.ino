void setup() {
  Serial.begin(9600);
 }

void loop() {
  int sensorValue = analogRead(A0);
  //int sensorValue1 = analogRead(A1);
 // int sensorValue2 = analogRead(A2);

    //analog to voltage
  float voltage = sensorValue  * (5.0 / 1023.0);
 // float voltage1= sensorValue1 * (5.0 / 1023.0);
 // float voltage2= sensorValue2 * (5.0 / 1023.0);

  Serial.println(voltage);
 // Serial.println(voltage1);
 // Serial.println(voltage2);
  Serial.println("");
 // delay('500');

  }
