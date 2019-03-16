//Write a C program to compute the sum of the two given integer values. If the two values are the same, then return triple their sum.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    //Variables
	int num1, num2, sum;
    
    //Output for User Prompt
	printf("Input your numbers:\n");
    
    //Input for User
	scanf("%d %d", &num1, &num2);
    
    //Conditional Logic
	//Exception case
	if (num1 == num2) {
		sum = (num1 + num2) * 3;
	}

	//Other cases
	else {
		sum = num1 + num2;
	}

	//Final output
	printf("%d\n", sum);

	system("PAUSE");
	return 0;
}
