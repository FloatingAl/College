#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "Interface.h"

#define WIDTH 1000
#define LENGTH 800

void drawCircle(sfRenderWindow* window, sfCircleShape* circle,float rad, int n)//passing the window,circle, radius, and n
{
  if(n != 0)
  {
	
	//position
	sfVector2f cook;//sfVector is a struct with x and y in it
	cook.x = WIDTH/2;
	cook.y = LENGTH/2 ;

	//origin
	sfVector2f weird_al;
	weird_al.x = rad;
	weird_al.y = rad;

	//This is the position
	sfCircleShape_setPosition(circle,cook);
	sfCircleShape_setOrigin(circle, weird_al);//Origin
	sfCircleShape_setRadius(circle, rad);	//Radius 
	sfRenderWindow_drawCircleShape(window, circle, NULL); //This function actully draws the circles  	
	drawCircle(window,circle,rad *0.75, n-1);//Im calling the function until it hits 0 
  }

}

//This creates the color and shape of the circles 
sfCircleShape* createCircle()
{
  sfCircleShape* circle = sfCircleShape_create();
  if(!circle)
    return NULL;
  sfCircleShape_setFillColor(circle, sfBlack);
  sfCircleShape_setOutlineColor(circle, sfWhite);
  sfCircleShape_setOutlineThickness(circle, 5.0f);

  return circle;
}

int gameEngine()
{
  sfVideoMode mode = {WIDTH, LENGTH, 32};
  sfRenderWindow* window;
  sfCircleShape* circle;
  sfEvent event;
  int flag = 0;
  int noLevels = 20;
  float circleRad = 500;
	printf("How many levels do you want for your circle? ");
	scanf("%d",&noLevels);  
	printf("What the radius do you want for your circle? ");
	scanf("%f",&circleRad);


  /* Create the main window */
  window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

  if (!window)
    return 1;

  circle = createCircle();
  if(!circle)
    return 1;

  /* Start the game loop */
  while (sfRenderWindow_isOpen(window))
    {
      checkEvent(window, event);

      if(flag == 0)
	{

	  flag = 1;                                                           
	  sfRenderWindow_clear(window, sfBlack);
	  drawCircle(window, circle,circleRad, noLevels);
	  sfRenderWindow_display(window);
	}

    }

  /* Cleanup resources */
  sfRenderWindow_destroy(window);
  return 0;
}

void checkEvent(sfRenderWindow * window, sfEvent event)
{
  /* Process events */
  while (sfRenderWindow_pollEvent(window, &event))
    {
      /* Close window : exit */
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(window);
    }

}
