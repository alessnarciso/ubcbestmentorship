//Harder challenge: only if one or more of the numbers are prime, swap the places

#include <stdio.h>
#include <stdlib.h>

//Function for printing arrays
//If prime, will return 1; else, will return 0;
int isprime(int num)
{
	/*write code here*/

	if (num <= 1) {
		return 0;
	}

	for (int i = 2; i <= num / 2; i++) {

		if (num%i == 0) {
			return 0;

		}

	}

	return 1;
}

//Function to reverse the array
void reverseArray(int arr[], int start, int end)
{
	/*write code here*/

	int temp;

	while (start < end) {

		if (isprime(arr[start]) == 1 || isprime(arr[end]) == 1) {

			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;



		}
		start++;
		end--;
	}

}

void printArray(int arr[], int size)
{
	//Variable for array for loop counter
	int i;

	//For loop to print array, iterating through index values i
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

//Main function that calls to other functions
int main(void)
{

	//Array we will be reversing
	int arr[] = { 100,17,25,3,1,80,50,2,79,62 };

	//Print original array
	printf("Original array is: \n");//Output for user feedback
	printArray(arr, 10);//Call to function to print array

	//Reverse array and check if prime
	reverseArray(arr, 0, 9); //Call to function to reverse array (index value of edges as parameters)
	printf("Reversed array is: \n"); //Output for user feedback
	printArray(arr, 10); //Call to function to print array

	system("PAUSE");
	return 0;
}

