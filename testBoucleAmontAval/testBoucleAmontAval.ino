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
}

void loop()//fonction loop executee en boucle dans le programme principal
{
  char c;
  Wire.begin(MECANISME);//Je mets en esclave le PCF8574 "mecanisme"
  Wire.requestFrom(MECANISME, 2);//demande de recevoir 2 octet a l'adresse de l'esclave
  while(Wire.available())//J'attends mes octets
  {
    c = Wire.read();//Reception des octets, un par un
    Serial.print(c);//Affiche sur le moniteur serie
  }
  Wire.endTransmission();//Je termine la transmission
  delay(500);
}
