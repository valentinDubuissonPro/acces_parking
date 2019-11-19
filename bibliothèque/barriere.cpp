#include "barriere.h"

void barriere(bool)
{
	if(bool == 1)
	{
		//j'envoie ma commande
		Wire.beginTransmission(0x20);//Je commence la transmission vers l'esclave         
		Wire.write(OUVRIR);//        P7  p6 p5 p4 p3 p2 p1 p0 
						   //j'envoie 0  1  1  1  1  1  0  1  
		delay(1000);
		Wire.endTransmission();//Je termine la transmission
	}
	else
	{
		//j'envoie ma commande
		Wire.beginTransmission(0x20);//Je commence la transmission vers l'esclave         
		Wire.write(FERMER);//        P7  p6 p5 p4 p3 p2 p1 p0 
						   //j'envoie 0  1  1  1  1  1  0  1  
		delay(1000);
		Wire.endTransmission();//Je termine la transmission
	}
}