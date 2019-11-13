/*Programme teste boucle AMONT AVAL
description:test boucle amont et aval
derniere mis a jour:13/11/2019
*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
/*On defini ici les constantes qui vont servir à l'ensemble du programme plutot qu de creer
des variables globales il est ainsi beaucoup plus facile de maintenir le code(seule une sourve a changer)*/
#define MECANISME 0x20//l'addrese de PCF8574 "mecanisme"

void setup()//fonction setup executee une fois lors du demarrage de la carte 
{
  Wire.begin();//Ma carte Arduino devient le maitre du bus I2C
  Serial.begin(9600);//Definit la vitesse d'affichage de mon moniteur série USB 
  initI2C(122);//Cadence la vitesse de transmission
 
}

void loop()//fonction loop executee en boucle dans le programme principal
{ 
  Wire.beginTransmission(MECANISME);//Je commence la transmission vers esclave le PCF8574 "mecanisme"
  Wire.requestFrom(MECANISME, 2);//demande de recevoir 2 octet a l'adresse de l'esclave
  while(Wire.available())    // slave may send less than requested
  { 
    int a = Wire.read(); // receive a byte as character
    Serial.print(a);// print the character
    Serial.println("");
    
    int b = Wire.read();// receive a byte as character
    Serial.print(b);// print the character
    Serial.println("");
    
    int c = Wire.read();// receive a byte as character
    Serial.print(c);// print the character
    Serial.println("");
    
    int d = Wire.read();// receive a byte as character
    Serial.print(d);// print the character
    Serial.println("");
    delay(1000);
  }
}
