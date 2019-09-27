/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ehu
 *
 * Created on 17 de septiembre de 2019, 18:37
 */

#include <stdio.h>
#include <cstdlib>
#include <wiringPi.h>

#define LEDR 9
#define BPIN 8

static volatile int pulso = 0;

using namespace std;

/*
 * 
 */
void esperaInterrupcion(void)
{
	if(pulso == 0) {
		pulso = 1;
	} else {
		pulso = 0;
	}
	printf("Botón pulsado. \n");
}
 
int main(int argc, char *argv[]) {
    wiringPiSetup();
    pinMode(LEDR, OUTPUT);
    
    wiringPiISR(BPIN, INT_EDGE_BOTH, &esperaInterrupcion);
	
    for(;;) {
	digitalWrite(LEDR, pulso);
	delay(500); 
    }
    return 0;
}

