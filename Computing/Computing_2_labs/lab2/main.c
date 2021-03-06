#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

void main() {
    //Create two arrays each with length 55
    char* authorName[55];
    char* bookName[55];
    
    //Ask the user for the name of the file
    char fileName[30];
    printf("What is the file name ? ");
    scanf(" %s",fileName);


    //Call the method loadBookName
    loadBookName(fileName, authorName, bookName);
    
    //Print the two arrays to test if the two arrays were correctly loaded with the data
    int i = 0;
    printf("%-30s%-40s\n", "Author", "Book");
    for (i = 0; i < 55; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }
}

/*
loadBookName method
This method is responsible for:
1. Take a file containing a book name and the author name as input
2. Open the file
3. Read the information in the file and store it in two arrays: authorName, bookName
4. Return the two arrays to the main method. 
*/
void loadBookName(char* filename, char* authorName[55], char* bookName[55]) {
    //Open the file
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can not open the file %s\n", filename);
        return;
    }
    
    char buffer[55];
    char temp[55];
    char temp2[55];

    int i;
    //this for loop going through authorname and 
    for(i = 0; i < 55;i++)
    {
     //This gets the line and then reads it. 
      fgets(buffer,55,fp);
      //This stops at the comma, and stores what was previously and stores it into temp.
      strcpy(temp,strtok(buffer,","));
      //Then this malloc creates space to store the string  
      authorName[i] = malloc(sizeof(char)*strlen(temp));
      //then copys what was stored in temp(which is strock) and then copys it to Authorname[0] then 
      //[1] and then [2] and so on.
      //then put it into 0
      strcpy(authorName[i],temp);
      //Then after that 
      strcpy(temp,strtok(NULL,","));
      bookName[i] = malloc(sizeof(char)*strlen(temp));
      strcpy(bookName[i],temp);
    
    }
    
    //printf("%s",temp); //DEBUG
    

   
    
    
    
    //Close the file
    fclose(fp);
}


