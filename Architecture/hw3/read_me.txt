Name: Albara Mehene
Email: Albara_Mehene@student.uml.edu
Class: Monday night class

Degree of Success:
100%

Description:
The approach I had for this program was to transfer the a recursive fibonnaci program to aseembly language. (Mic1). I first took the sample code that was given to us by Professor Hedrickson. The sample code did the fibonacci sequence in a loop. My thought process was all I needed to do was remove the looping and iteration to recursive calls. By doing so, I would load the the arg into the AC and then subtract 1 for the first function. It would call the function until it becomes 0 or 1. After that, it would move onto to the second recusive call and subttract 2. My first approach was to create another variable that would subtract 2 from the AC. However, I found out that arg-1 was placed onto the stack instead of having it as just arg. I needed to instead subtract 1 from the arg-1 making it arg-2. After the recusive calls, I needed to add the results of both arg-1 and arg-2 into the AC then removing the arguments from the stack for good practice. Then finally returning that final value.
