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

#define LEDR 8

static volatile int pulso = 0;

using namespace std;

/*
 * 
 */
int main(int argc, char *argv[]) {
    wiringPiSetup();
    pinMode(LEDR, OUTPUT);
    

	
    for(;;) {
	digitalWrite(LEDR, HIGH);
	delay(500); 
        digitalWrite(LEDR, LOW);
    }
    return 0;
}

