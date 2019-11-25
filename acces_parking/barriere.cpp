/*definition de la bibliotheque qui gere la barriere
description:gere la barriere
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
-teste effectuer
*/

#include "barriere.h"

void barriere(bool choix)
{
  //J'ouvre ma barriere
	if(choix == 1)
	{
		//j'envoie ma commande
		Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave         
		Wire.write(OUVRIR);//        P7  p6 p5 p4 p3 p2 p1 p0 
						   //j'envoie 0  1  1  1  1  1  0  1  
		Wire.endTransmission();//Je termine la transmission
	}
 //Je ferme ma barriere
	else
	{
		//j'envoie ma commande
		Wire.beginTransmission(MECANISME);//Je commence la transmission vers l'esclave         
		Wire.write(FERMER);//        P7  p6 p5 p4 p3 p2 p1 p0 
						   //j'envoie 0  1  1  1  1  1  0  1  
		Wire.endTransmission();//Je termine la transmission
	}
}
