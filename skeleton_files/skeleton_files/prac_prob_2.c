//Write a program in C to display the pattern like right angle triangle with a number from a user input.
//The pattern's like this:
//1
//12
//123
//1234

#include <stdio.h>
int main(void){
    
    //Variables
    //hint: int i,j,rows;
	int rows, i, j;
    
    //Output for User Prompt
    //printf("Input number of rows: ");
	printf("Input number of rows: ");
    
    //Input for User
    //scanf("%d",&rows);
	scanf("%d", &rows);
    
    //Loop Logic
    /*write code here*/
	for (i = 1; i <= rows; i++) {

		for (j = 1; j <= i; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
    
}
