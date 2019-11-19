/*Programme teste la carte
description:test si ma carte est inserer
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
-
*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
/*On defini ici les constantes qui vont servir à l'ensemble du programme plutot qu de creer
des variables globales il est ainsi beaucoup plus facile de maintenir le code(seule une sourve a changer)*/
#define CARTE 0x50//l'addrese de PCF8574 "mecanisme"

void setup()//fonction setup executee une fois lors du demarrage de la carte 
{
  Wire.begin();//Ma carte Arduino devient le maitre du bus I2C
  Serial.begin(9600);//Definit la vitesse d'affichage de mon moniteur série USB 
  initI2C(122);//Cadence la vitesse de transmission
 
}

void loop()//fonction loop executee en boucle dans le programme principal
{ 
  Wire.beginTransmission(CARTE);//Je commence la transmission vers l'esclave                   
  Wire.write(255);//        P7  p6p5p4p3p2p1p0 
                  //j'envoie 1  1 1 1 1 1 1 1  sachant que les 0 ces des sortie et 1 entré
  Wire.endTransmission();     
  
  Wire.requestFrom(CARTE, 1);//demande de recevoir 2 octet a l'adresse de l'esclave
  while(Wire.available())//Attend la reponse
  { 
    int a = Wire.read(); //recois octet par octet
    Serial.print(a,BIN);//affiche l'octet recus
    Serial.println();//saut de ligne
  }
  delay(500);
}
