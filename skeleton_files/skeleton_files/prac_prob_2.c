//Write a program in C to display the pattern like right angle triangle with a number from a user input.
//The pattern's like this:
//1
//12
//123
//1234

#include <stdio.h>
int main(void){
    
    //Variables
    int i,j,rows;
    
    //Output for User Prompt
    printf("Input number of rows: ");
	//Input from user
    scanf("%d",&rows);
    
    //controls the number of rows printed 
	for (i = 1; i <= rows; i++) {
	//prints the correct number of elements on each line
		for (j = 1; j <= i; j++) {
			printf("%d\n", j);
		}
		printf("\n");
	}
    
}
