/*teste de la bibliotheque qui gere les boucles
description:gere les boucles
date de cration:20/11/2019
Note:
si la voiture est que sur la boucle Amont =64
si la voitire n'est pas sur la boucle Amont et la boucle Aval = 96
si la voiture est que sur la boucle Aval = 32
si la voitire est sur la boucle Amont et la boucle Aval = 0
derniere mis a jour:20/11/2019:
-
*/
#include "boucle.h"

bool boucleAmont()
{
  char a;
	//Je définis mes entrees sorties
	Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave                   
	Wire.write(ES);//        P7  p6 p5 p4 p3 p2 p1 p0 
					        //j'envoie 0  1  1  1  1  0  0  0  sachant que les 0 ces des sortie et 1 entré
	Wire.endTransmission();  
	//Je lis mes ports
	Wire.requestFrom(MECANISME, 1);//demande de recevoir 2 octet a l'adresse de l'esclave
	while(Wire.available())//Attend la reponse
	{ 
	  a = Wire.read(); //recois octet par octet
	} 
	//Serial.println(a,DEC);//affiche l'octet recus
  if(a == 64) return 1;//si la voiture est sur la boucle Amont je retourne 1
  else return 0;//sinon je retourne 0
}

bool boucleAval()
{
  char a;
  //Je définis mes entrees sorties
  Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave                   
  Wire.write(ES);//        P7  p6 p5 p4 p3 p2 p1 p0 
                  //j'envoie 0  1  1  1  1  0  0  0  sachant que les 0 ces des sortie et 1 entré
  Wire.endTransmission();  
  //Je lis mes ports
  Wire.requestFrom(MECANISME, 1);//demande de recevoir 2 octet a l'adresse de l'esclave
  while(Wire.available())//Attend la reponse
  { 
    a = Wire.read(); //recois octet par octet
  } 
  //Serial.println(a,DEC);//affiche l'octet recus
  if(a == 32) return 1;//si la voiture est sur la boucle Aval je retourne 1
  else return 0;//sinon je retourne 0
}
