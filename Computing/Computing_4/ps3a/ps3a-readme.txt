/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Albara Mehene
OS: Linux
Machine (e.g., Dell Latitude, MacBook Pro): Acer
Text editor: Sublime
Hours to complete assignment (optional):
8
/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Used cin to store the lines of the each string until it hits a space. We learned that if we keep storing the string in cin, the next string in the file would be stored. We then stored the first two string and made a for loop for the rest of strings. The codition was until the numberofplanets. Before we tried just cin every string and pushing it into the vector of objects. Though we needed to use overloading, so we created a function of overloading << that took the input and stored it into the member functions of the body. Then we returned the input. After creating window and look. We created a for loop to go through all the bodies and would draw all them out. Thats when the draw function comes in. We created a image, texture, and sprite for each body. After loading in the file, we needed to set the position. The position was tricky part. We know we needed the radius of the universe in inverse. But we could get what we wanted. So we figured we would make a really small number for the scale and just multiply the position. Also adding the size of the position. Lastly, we would then draw the sprite of each planet and print it on the screen.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
 	Yes, I worked with Sean nishi since the beginning of this project. We were allowed to have partners for this project.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 		The overloading operator was a bit tricky to figure out. Took us about 2 hours to solve it. 
 		The scaling was also a bit tricky. Probably took us the longest to figure out. We wanted to use the radius to figure out the scale. But ended up negating the e+10 by muliplying with a really small decmial number. It was basically the same as inversing but we just manually put int the number.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 	We also included the velocity and mass for the next part of the assigment.
