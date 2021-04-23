/**********************************************************************
 *  readme.txt template                                                   
 *  PS7b: Kronos log parsing
 **********************************************************************/

Name: Albara Mehene


Hours to complete assignment (optional):
None

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
No I did not complete the whole assignment


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
 For start:
	"([0-9]{4})-([0-9]{2})-([0-9]{2}) "
  	"([0-9]{2}):([0-9]{2}):([0-9]{2}): " 
  	"\\(log.c.166\\) server started.*");

  	For end;
  	"([0-9]{4})-([0-9]{2})-([0-9]{2}) "
  	"([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:"
  	"oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*");

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
   So at first we thougth we were supposed to use the std-boos.cpp as a starting point. Thankfully our classmates told us it was just to test regex commands. We both looked up websites to help us figure out what would make a good regex command to find log.c.166. After we figure out the command, we searched up what date and ptime objects are. Then we started writing the code. So we first needed the user to enter the file. Checking to see if he did. Any way, after that we made a while loop to go through the file and check each line to see if it matches to regex commands. We did that for the start and end bootime. Once we did that we just subtracted the times to get the total amount of time. But I was not able to complete the ps7b.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
  Sean Nishi

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 Yeah the problems were that I did not understand ps7b


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Pretty card
