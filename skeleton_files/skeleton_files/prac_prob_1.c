//Write a C program to compute the sum of the two given integer values. If the two values are the same, then return triple their sum.

#include <stdio.h>

int main(void) {

	//Variables
	//hint: int num1,num2,sum;
	int num1, num2, sum;

	//Output for User Prompt
	//printf("Input your numbers\n");
	printf("Input your numbers\n");


	//Input for User
	//*write code here*/
	scanf("%d", &num1);
	scanf("%d", %num2);

	//Conditional Logic
	/*write code here*/
	if (num1 == num2) {
		sum = 3 * (num1 + num2);
	}
	else {
		sum = num1 + num2;
	}

	//Final Output
	//printf("%d\n",sum);
	printf("%d\n", sum);

}
