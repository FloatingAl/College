#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "mainhead.h"

int windowcreation(sfRenderWindow** window)
{
	/*The reason we used two astricks is because when we created the 
	value for window, it was temporary. You see after the function
	was called, what was inside of window was erased. So to have to change 
	the value we need to make a pointer to. We are basically just 
	changing the the copy of the orginal function. Because it was 
	a *window we needed to put **window to acsesse the orginal value.*/
	sfVideoMode mode = {200, 300, 32};
	*window = sfRenderWindow_create(mode, "Albara Mehene", sfResize | sfClose, NULL);
    if (!*window)
        return 1;
}


int circlecreation(sfCircleShape** circle)
{
	*circle = sfCircleShape_create();
	if(!*circle)
		return 1;
	
	sfCircleShape_setRadius(*circle, 100);
	sfCircleShape_setFillColor(*circle, sfRed);
}

void checkopen(sfCircleShape* circle , sfRenderWindow* window)
{
	sfEvent event;
	 while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
        }
        
        sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawCircleShape(window, circle, NULL);
        sfRenderWindow_display(window);
    }
}
void destroy(sfCircleShape* circle, sfRenderWindow* window)
{
	sfCircleShape_destroy(circle);
    sfRenderWindow_destroy(window);
}