#include <SoftwareSerial.h>

SoftwareSerial BLU(7,6); // Brancher Rx 6 Tx 7

#define redPin 9 // Brancher le Rouge en 9
#define greenPin 10 // Brancher le Vert en 10
#define bluePin 11 // Brancher le Bleu en 11

void setup()
{
  //Serial setup
  Serial.begin(38400); // vitesse de transmition // Baud Rate


  BLU.begin(38400);

  
  pinMode(4, OUTPUT);
 
  digitalWrite(4,HIGH);


  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


 
}

void loop()
{
  while (BLU.available() > 0)
  {
    int redInt = BLU.parseInt();
    int greenInt = BLU.parseInt();
    int blueInt = BLU.parseInt();

    redInt = constrain(redInt, 0, 255);
    greenInt = constrain(greenInt, 0, 255);
    blueInt = constrain(blueInt, 0, 255);

    if (BLU.available() > 0)
    {
      setColor(redInt, greenInt, blueInt);

      Serial.print("Red: ");
      Serial.print(redInt);
      Serial.print(" Green: ");
      Serial.print(greenInt);
      Serial.print(" Blue: ");
      Serial.print(blueInt);
      Serial.println();

      BLU.flush();
    }
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
