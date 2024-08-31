// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  int a=analogRead(A0);
 if(a>=750)
 {
   digitalWrite(3,LOW);
   digitalWrite(2,LOW);
 }
  else
  {
    digitalWrite(3,HIGH);
   digitalWrite(2,HIGH);
  }
}