/*Bibliotheque qui gere les boucles
description:gere les boucles
date de cration:20/11/2019
Note:
si la voiture est que sur la boucle Amont =64
si la voitire n'est pas sur la boucle Amont et la boucle Aval = 96
si la voiture est que sur la boucle Aval = 32
si la voitire est sur la boucle Amont et la boucle Aval = 0
derniere mis a jour:20/11/2019:
*/

#ifndef BOUCLE_H
#define BOUCLE_H

#include <Arduino.h>
#include <Wire.h>//Bibliothèque arduino qui permet de gerer un bus de terrain I2C

#define MECANISME 0x20//l'addrese de PCF8574 "mecanisme"
#define ES 120//sert a definir en decimal mes entrees sorties

bool boucleAmont();

bool boucleAval();

#endif//fin de BOUCLE_H
