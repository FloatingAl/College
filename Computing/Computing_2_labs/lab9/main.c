/**********************************************************************
Program: Lab9	 
Author: Albara Mehene	
Date: 11/24/15
Time spent: 3 hours
Purpose: The purpose of this program is to be able to have users enter. Then have them log in or log out. Then show who is loged in or loged out

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListSt.h"

int main(void)
{
	/*So I created the menu to have the person know what to fo. I created a choice to store, repeat for the while loop and have then enter it into username and use it for other functions. Then temp to have the response for the user to be logged in or logged out*/
	int choice;
	char* username;
	int temp;
	int repeat = 1;
	pLinkedList list = linkedlistInitDefault();
	while(repeat == 1)
	{	
		printf("Enter user (1)\n");
		printf("Log In (2)\n");
		printf("Log Out (3)\n");
		printf("Check who is online (4)\n");
		printf("Quit (5)\n");
		printf("Enter here:");
		scanf("%d",&choice);
	
		switch(choice){
		case 1:
			if(enterinfo(list) == 1)
			{
				printf("\nThe username was succesful\n\n");
			}
			else
			{
				
				printf("\nThe user already exits\n\n");
			}
			break;
		case 2:
			username = malloc(50*sizeof(char));
			printf("Enter user name to login:");
			scanf(" %s",username);

			temp = login(list,username);
			if(temp == 1)
			{
				printf("\nSuccessful log in\n\n");
			}
			else if(temp == 0)
			{
				printf("\nCould not find username\n\n");
			}
			else if(temp == -1)
			{
				printf("\nThe user is already logged in\n\n");
			}     
			break;
		case 3:
			username = malloc(50*sizeof(char));
			printf("Enter user name to logout:");
			scanf(" %s",username);

			temp = logout(list,username);
			if(temp == 1)
			{
				printf("\nSuccessful log out\n\n");
				
			}
			else if(temp == 0)
			{
				printf("\nCould not find username\n\n");
			}	
			else if(temp == -1)
			{
				printf("\nThe user is already logged out\n\n");
			}     
			break;
		case 4:
			show(list);
			break;
		case 5:
			repeat = 0;
			break;
		}
	
 	}
	linkedlistDestroy(&list);
		
}
