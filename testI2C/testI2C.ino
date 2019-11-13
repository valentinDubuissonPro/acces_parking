/*Programme teste la communication I2C
description:test la communication I2C et me permet de comprendre la bilbiothèque Wire
derniere mis a jour:13/11/2019
*/
#include <Wire.h>
#include "I2C.h"

void setup()
{
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
  initI2C(122);//Cadence la vitesse de transmission
} 

void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.print("Sacnne");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    // La valeur de retour de Wire.endTransmission() 
    // est false (0) si le peripherique existe a cette adresse
    Serial.print(".");
 
    if (error == 0)
    {
      Serial.println("");// retour à la ligne
      Serial.print("I2C l'adresse trouver est 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !"); 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.println(""); 
      Serial.print("Unknow error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }  
    delay(50);
  }
  if (nDevices == 0)
  {
    Serial.println(""); 
    Serial.println("No I2C devices found\n");
  }
  else
    Serial.println("done\n");
 
  delay(3000);           // on attend 3 secondes et on recommence
}
