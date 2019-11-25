/*Programme teste Du moteur de ma barriere
description:test du moteur de ma barriere 
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
-faire tourner dans un sens et faire tourner dans l'autre
*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
/*On defini ici les constantes qui vont servir à l'ensemble du programme plutot qu de creer
des variables globales il est ainsi beaucoup plus facile de maintenir le code(seule une sourve a changer)*/
#define MECANISME 0x20//l'addrese de PCF8574 "mecanisme"
#define MOTEUR 126//125 ouvre la bariere et 126 la ferme

void setup()//fonction setup executee une fois lors du demarrage de la carte 
{
  Wire.begin();//Ma carte Arduino devient le maitre du bus I2C
  Serial.begin(9600);//Definit la vitesse d'affichage de mon moniteur série USB 
  initI2C(122);//Cadence la vitesse de transmission
}

void loop()//fonction loop executee en boucle dans le programme principal
{
  //j'envoie ma commande
  Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave         
  Wire.write(MOTEUR);//        P7  p6p5p4p3p2p1p0 
                  //j'envoie 0  1 1 1 1 1 0 1  
  Wire.endTransmission();//Je termine la transmission
}
