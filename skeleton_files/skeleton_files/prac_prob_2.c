//Write a program in C to display the pattern like right angle triangle with a number from a user input.
//The pattern's like this:
//1
//12
//123
//1234

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void){
    
    //Variables
    int i,j,rows;
    
    //Output for User Prompt
    printf("Input number of rows: ");
    
    //Input for User
    scanf("%d",&rows);
    
    //Loop Logic
    /*write code here*/
    
	for (i = 1; i <= rows; i++) {

		for (j = 0; j < i; j++) {

			printf("%d", j+1);

		}

		printf("\n");

	}

	return 0;

}
