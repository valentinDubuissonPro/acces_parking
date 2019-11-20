 /*Programme commande barriere
description:va gérer tous le système
Date : 20/11/2019
Note:
derniere mis a jour:20/11/2019
-integration des bibliotheque boucle et barriere
*/

/*Biliotheque*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
#include "boucle.h"//Permet de gérer les boucles
#include "barriere.h"//Permet de gérer la barriere

void setup() 
{
  Serial.begin(9600);//Vitesse de transmission du moniteur serie
  Wire.begin();//Defini l'arduino en maitre
  initI2C(200);//Cadence la vitesse de transmission
}

void loop() 
{
  bool boucleAm  = boucleAmont();
  bool boucleAv  = boucleAval();

  barriere(0);
  //gestion de la sortie d'un vehicule
  if(boucleAm == 0 && boucleAv == 1)//Arrivee d'une voiture sur le parking
  {
    barriere(1);
    do
    {
      if(boucleAv == 0 && boucleAm == 1)
      {
        while(boucleAm == 1 || boucleAv == 1); 
      }
    }while (boucleAm == 1 || boucleAv == 1);
  }
}
