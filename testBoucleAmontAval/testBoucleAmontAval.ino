/*Programme teste boucle AMONT AVAL
description:test boucle amont et aval
date de cration:13/11/2019
derniere mis a jour:19/11/2019:
-Comunication avec les 2 boucles
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
  Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave                   
  Wire.write(120);//        P7  p6p5p4p3p2p1p0 
                  //j'envoie 0  1 1 1 1 0 0 0  sachant que les 0 ces des sortie et 1 entré
  Wire.endTransmission();     
  
  Wire.requestFrom(MECANISME, 1);//demande de recevoir 2 octet a l'adresse de l'esclave
  while(Wire.available())//Attend la reponse
  { 
    char a = Wire.read(); //recois octet par octet
    Serial.print(a,BIN);//affiche l'octet recus
    Serial.println();//saut de ligne
  }
  delay(500);
}
