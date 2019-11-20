 /*Programme commande barriere
description:va gérer tous le système
Date : 13/11/2019
Note:
derniere mis a jour:20/11/2019
-integration des bibliotheque boucle et barriere
*/

/*Biliotheques*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
#include "affiche.h"//Permet de gérer l'afficheur
#include "boucle.h"//Permet de gérer les boucles
#include "barriere.h"//Permet de gérer barriere

/*Constantes*/
#define OUVRIR 1
#define FERMER 0

void setup()//fonction setup executee une fois lors du demarrage de la carte 
{
  Serial.begin(9600);//Vitesse de transmission du moniteur serie
  Wire.begin();//Defini l'arduino en maitre
  initI2C(200);//Cadence la vitesse de transmission
}

void loop()//fonction loop executee en boucle dans le programme principal
{
  //Variables
  int nombreVoiture = 0;//variable static permettant de compter le nombre de véhicules dans le parking
 
  //gestion de l'entré d'un vehicule
  if(boucleAmont() == 1 && boucleAval() == 0)//Arrivee d'une voiture sur le parking
  {
    barriere(OUVRIR);//Ouverture de la bariere
    while(boucleAmont() == 1 && boucleAval() == 0);
    delay(20);//evite une mauvaise lecture du if suivant si jamais que le vehicule quitte les boucles
    if(boucleAmont() == 0 || boucleAval() == 1)
    { 
      if(boucleAmont() == 1)
      {
        while(boucleAmont == 1 || boucleAval == 1);
        //On attend que le vehicule quitte les boucles
        nombreVoiture++;
        //Affichage sur l'ecran du gardian du nombre de voiture
        Serial.print("il y a dans le parking :");
        Serial.print(nombreVoiture);
        Serial.print("voiture(s)");
      }
    }
    barriere(FERMER);
   }
  //gestion de la sortie d'un vehicule
  if(boucleAval() == 1 && boucleAmont() == 0)//Arrivee d'une voiture sur le parking
  {
    barriere(OUVRIR);//Barriere s'ouvre
    do
    {
      if(boucleAval() == 0 && boucleAmont() == 1)
      {
        while(boucleAmont() == 1 || boucleAval() == 1);
        nombreVoiture--; 
      }
    }while (boucleAmont() == 1 || boucleAval() == 1); 
    barriere(FERMER);
  }
} 
