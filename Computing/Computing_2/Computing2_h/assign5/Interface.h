//This function draws the circle
void drawCircle(sfRenderWindow* window, sfCircleShape* circle, float rad, int n);
//This function creates the shape
sfCircleShape* createCircle(); 
//This the body of the whole program that calls everyother functuion
int gameEngine();
//This checks if it 0 or not.
void checkEvent(sfRenderWindow * window, sfEvent event);

