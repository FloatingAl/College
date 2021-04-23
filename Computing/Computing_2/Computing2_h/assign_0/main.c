/*******************************************************
	91.102 Assignment0
	Program: main.c
	Author: Albara Mehene
	Date: 9/5/2015
	Time spent: 2 hours
	Purpose: The purpose of this program is to draw a circle
********************************************************/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

int main(void){
	
	sfVideoMode mode = {200, 300, 32};
    sfRenderWindow* window;
	sfCircleShape* circle;
    sfEvent event;
   
    window = sfRenderWindow_create(mode, "Albara Mehene", sfResize | sfClose, NULL);
    if (!window)
        return 1;

	circle = sfCircleShape_create();//this is the code that is responsible for creating the circle.
	if(!circle)
		return 1;
	
	sfCircleShape_setRadius(circle, 100);//this draws it
	sfCircleShape_setFillColor(circle, sfRed);
    
    while (sfRenderWindow_isOpen(window))//This while loop creates a window to put the circle in. Basically the interface.
    {
      
        while (sfRenderWindow_pollEvent(window, &event))
        {
            
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        
        sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawCircleShape(window, circle, NULL);
			
       
        sfRenderWindow_display(window);
    }
	
	sfCircleShape_destroy(circle);
    sfRenderWindow_destroy(window);
   
	 return 0;
}

