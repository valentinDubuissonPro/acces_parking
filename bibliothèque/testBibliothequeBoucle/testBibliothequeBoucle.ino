/*teste de la bibliotheque qui gere les boucles
description:gere la barriere
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
-teste effectuer
*/
#include "boucle.h"
#include "barriere.h"
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C

void setup() 
{
  Wire.begin();//Ma carte Arduino devient le maitre du bus I2C
  Serial.begin(9600);//Definit la vitesse d'affichage de mon moniteur série USB 
  initI2C(200);//Cadence la vitesse de transmission
}

void loop() 
{
  barriere(0);
  //test boucle Amont
  bool a = boucleAmont();//Appel de ma fonction qui gère la boucle amont
  if( a==1)barriere(1);
  
  //teste boucle Aval
  bool b= boucleAval();//Appel de ma fonction qui gère la boucle amont
  if(b==1)barriere(0);
}
