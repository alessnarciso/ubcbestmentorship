//Write a program in C to display the pattern like right angle triangle with a number from a user input.
//The pattern's like this:
//1
//12
//123
//1234

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    //Variables
	int i, j, rows;
    
    //Output for User Prompt
    printf("Input number of rows: ");
    
    //Input for User
    scanf("%d",&rows);
    
    //Loop Logic
	//Row loop
	for (i = 0; i < rows; i++) {
		// define max column number by row
		int cols = i + 1;
		// Column loop
		for (j = 1; j <= cols; j++) {
			//print column numbers
			printf("%d", j);
		}
		
		// new row
		printf("\n");
	}

	system("PAUSE");
	return 0;
}
