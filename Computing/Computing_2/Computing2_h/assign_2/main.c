./*******************************************************
	91.102 Assignment2
	Program: main.c
	Author: Albara Mehene
	Date: 9/19/2015
	Time spent: 3 hours	
	Purpose: Purpose of this program was the seperate as many 
	of the code that was in the main in the header file and a 
	implementation file.
********************************************************/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "mainhead.h"

int main(void){

    sfRenderWindow* window;
	sfCircleShape* circle;
    sfSprite* sprite;
	
	windowcreation(&window);
	circlecreation(&circle);
	checkopen(circle,window);
	destroy(circle, window);
   
	 return 0;
}

