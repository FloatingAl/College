/*
Name: Albara Mehene
Date: 3/3/2018
Class: Monday Class 
*/

/* Help file for cs305 Assignment 7
//
// This file has some code any many comments to 
// direct you through assignment #7
//


 need these include files */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>

/* need just a main function, no args */
int main(void)
{
/* some local variables */ 
        pid_t   pid, ppid;
        int     ruid, rgid, euid, egid;
        int     priority;
        char    msg_buf[100];
        int 	msg_pipe[2];

/* use the pipe() system call to create the pipe */

        if(pipe(msg_pipe) == -1){
                perror("failed in Parent pipe creation:");
                exit(7);
        }

/* use various system calls to collect and print process details */
        
        printf("\nThis is the Parent process report:\n");
        pid  = getpid();
        ppid = getppid();
        ruid = getuid();
        euid = geteuid();
        rgid = getgid();
        egid = getegid();
        priority = getpriority(PRIO_PROCESS, 0);
        
        printf("\nPARENT PROG:  Process ID is:\t\t%d\n", pid);
        printf("PARENT PROC:  Process parent ID is:\t%d\n", ppid); 
		printf("PARENT PROC:  Real UID is:\t\t%d\n", ruid);
        printf("PARENT PROC:  Real GID is:\t\t%d\n", rgid);
        printf("PARENT PROC:  Effective UID is:\t\t%d\n", euid); 
        printf("PARENT PROC:  Effective GID is:\t\t%d\n", egid);
        printf("PARENT PROC:  Process priority is:\t%d\n", priority);

		printf("\nPARENT PROC: will now create child, write pipe,\n \
                and do a normal termination\n");

/* use the sprintf() call to build a message to write into the pipe
// and dont forget to write the message into the pipe before parent exits*/

		sprintf(msg_buf, "Message from the parent with PID %d", pid);

/* now use the fork() call to create the child: */

	switch(pid = fork()){

	case -1: /* if the call failes */
	  perror("Fork failed: ");
	  exit(1);

	default : /* parent's case */
	  printf("Created child with PID: %d\n", pid);
	  write(msg_pipe[1], msg_buf, strlen(msg_buf));
	  exit(1);

	case 0 : /* Childs case */
	  printf("Child Report info:\n");

	  pid  = getpid();
	  ppid = getppid();
	  ruid = getuid();
	  euid = geteuid();
	  rgid = getgid();
	  egid = getegid();
	  priority = getpriority(PRIO_PROCESS, 0);

          printf("\nPARENT PROG:  Process ID is:\t\t%d\n", pid);
          printf("PARENT PROC:  Process parent ID is:\t%d\n", ppid); 
		  printf("PARENT PROC:  Real UID is:\t\t%d\n", ruid);
          printf("PARENT PROC:  Real GID is:\t\t%d\n", rgid);
          printf("PARENT PROC:  Effective UID is:\t\t%d\n", euid); 
          printf("PARENT PROC:  Effective GID is:\t\t%d\n", egid);
          printf("PARENT PROC:  Process priority is:\t%d\n", priority);

		  
	  read(msg_pipe[0], msg_buf, 100);
		
	  printf("CHILD PROC: parent's msg is %s\n", msg_buf);
	  printf("CHILD PROC: ### Goodbye ###\n");
	  exit(1); 

    } /* switch and child end */
       

	return 0; 
}