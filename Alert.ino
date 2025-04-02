int greenPin = 2;
int yellowPin = 3;
int redPin = 4;
int piezoBuzzer = 5;
int delayTime=1000;
float MoistureLevel; //Values between 0-1023
  
void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode (A0, INPUT); //A0   is the pin used for the Soil Moisture Sensor
  }

void   loop() {
 MoistureLevel = analogRead(A0);//Keep renewing the readings   for the current moisture level
 MoistureLevel = MoistureLevel/1023*100;
 Serial.print(MoistureLevel);
 Serial.println("%");
 delay(delayTime);
    
 if(MoistureLevel < 20 ){ //If the moisture is below 20%
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH); //Switch   on red light, and sound the buzzer
    tone(piezoBuzzer, 5000, 500);
    delay(2000);
   }
   if (MoistureLevel >= 20 && MoistureLevel <= 30)
  {//if the moisture level is in between 20% and 30%
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);   //Switch red light on, but don't sound the buzzer
  }
  if (MoistureLevel <= 70 && MoistureLevel > 30)
  {//if the moisture level is in between 30% and 70%
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,HIGH);//Just switch yellow light on
    digitalWrite(redPin,LOW);
  } 
  if(MoistureLevel > 70)
   //Otherwise the moisture level is above 70%, and therefore it's good enough
   {
   digitalWrite(greenPin, HIGH);//Switch green light on
   digitalWrite(yellowPin, LOW);
   digitalWrite(redPin, LOW);
  }
}
