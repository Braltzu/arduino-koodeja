char incomingByte = 0;
int choice = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
     incomingByte = Serial.read();
     choice = incomingByte - '0';
    Serial.print("numero==");
    Serial.println(choice);

  }
}