/*Bibliotheque qui gere la barriere
description:gere la barriere
date de cration:19/11/2019
derniere mis a jour:19/11/2019:
*/
#ifndef BARRIERE_H
#define BARRIERE_H

#include <Arduino.h>
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C
#include "I2C.h"//Permet de paramétrer la vitesse de la liaison I2C

#define MECANISME 0x20//l'addrese de PCF8574 "mecanisme"
#define OUVRIR 125//125 ouvre la bariere et 126 la ferme
#define FEMER 126//125 ouvre la bariere et 126 la ferme

void barriere(bool);


#endif//fin de BARRIERE_H