/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Albara Mehene
Partner: Sean nishi

Hours to complete assignment (optional):
3

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes it works successfuly.
All of the parts are working.
They are working because we were able to output the files. The files succsufully printed everything in the output

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
 So at first we thougth we were supposed to use the std-boos.cpp as a starting point. Thankfully our classmates told us it was just to test regex commands. We both looked up websites to help us figure out what would make a good regex command to find log.c.166. After we figure out the command, we searched up what date and ptime objects are. Then we started writing the code. So we first needed the user to enter the file. Checking to see if he did. Any way, after that we made a while loop to go through the file and check each line to see if it matches to regex commands. We did that for the start and end bootime. Once we did that we just subtracted the times to get the total amount of time.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
 My partner was Sean nishi
 classmates helped us on steps we needed to takes.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The direction were not easy to understand.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
None

