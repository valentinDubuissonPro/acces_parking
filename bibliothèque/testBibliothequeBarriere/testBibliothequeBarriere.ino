/*teste de la bibliotheque qui gere la barriere
description:gere la barriere
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
-teste effectuer
*/
#include "barriere.h"
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C

void setup() 
{
  Wire.begin();//Ma carte Arduino devient le maitre du bus I2C
  Serial.begin(9600);//Definit la vitesse d'affichage de mon moniteur série USB 
  initI2C(122);//Cadence la vitesse de transmission
}
void loop() 
{
  barriere(1);//appel de ma fonctio qui gere ma barriere et qui accpete un boolean
}
