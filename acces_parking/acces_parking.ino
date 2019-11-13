/*Programme commande barriere
description:va gérer tous le système
derniere mis a jour:13/11/2019
-recopie du programme correction TP5
*/
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C
#include "affiche.h"//Permet de géerer l'afficheur
#include "malib.h"//Permet l'accèes au fonction du système

void setup()//fonction setup executee une fois lors du demarrage de la carte 
{
  Serial.begin(9600);
  
}

void loop()//fonction loop executee en boucle dans le programme principal
{
  int tempo = 0, testTempo; //tempo pemettra d'attendre les 30 secondes en entree
  static int nombreVoiture = 0;//variable static permettant de compter le nombre de véhicules dans le parking

  //gestion de l'entré d'un vehicule
  if(digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0)//Arrivee d'une voiture sur le parking
  {
    //Afficher le message d'accueil sur l'afficheur
    if(digitalRead(VALIDATION) == 1)//Voir si le code est valide
    {
      testTempo = 1;//Initialisation de ma varaible de test de la tempo
      commandeBarriere(OUVRIR, 2);//Ouverture de la bariere
      while(digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0 && testTempo == 1)
      {
        delay(30);
        tempo++;//Incrementation toute les 30ms pour simuler l'attente de 30 secondes
        if(tempo == 1000)
        {
          testTempo = 0;//le delay de 30 secondes est atteint
        }
      }
      delay(20);//evite une mauvaise lecture du if suivant si jamais il y a rebond de l'inter bav
      if(digitalRead(BOUCLEAMONT) = 0 || digitalRead(BOUCLEAVAL) == 1)
      {
        if(digitalRead(BOUCLEAMONT) == 1)
        {
          while(digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1);//On attend que le vehicule quitte les boucles
          nombreVoiture++;
          //Affichage sur l'acran du gardian du nombre de voiture
          Serial.print("il y a dans le parking :");
          Serial.print(nombreVoiture);
          Serial.print("voiture(s)");
        }
      }
      commandeBarriere(FERMER, 2);
    }
  }
  //gestion de la sortie d'un vehicule
  if(digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0)//Arrivee d'une voiture sur le parking
  {
    commandeBarriere(OUVRIR);
    do
    {
      if(digitalRead(BOUCLEAVAL) == 0 && digitalRead(BOUCLEAMONT) == 0)
      {
        while(digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1);
        nombreVoiture--; 
      }
    }while(digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1);
  }
} 
