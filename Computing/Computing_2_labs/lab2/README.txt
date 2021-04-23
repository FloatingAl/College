Albara Mehene
9/24/2015
Lab 2


This program seperates what in the txtfile "book". Each line seperating the
author name and the book name. Then storing them in a array of characters. 

First I needed to create three variables, a array of spaces for the string and 2
temporary storage. I used the fgets to get the first line in the file. then 
store it into buffer. After than I use the strcpy function to copy the first 
half of the line before the comma. The I malloc enough for a string for authorName
Then Copy the the lone to authorname from temp. 
This applys to the bookName so its basically the same process. 
