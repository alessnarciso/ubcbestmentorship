//Write a function to reverse an array.
//Note: We are trying to use this to reverse the array: {1, 2, 3, 4, 5, 6}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int start, int stop);
void printArray(int arr[], int size);
void scaleArray(int arr[], int size);

//Main function that calls to other functions
int main()
{
	//Array we will be reversing
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	//Print original array
	printf("Original array is: \n");
	printArray(arr, 6);

	//Call to function to reverse array
	/*write code here*/

	reverseArray(arr, 0, 5);

	//Output for user feedback
	printf("Reversed array is: \n");
	printArray(arr, 6); //Call to function to print array

	scaleArray(arr, 6);
	printArray(arr, 6);

	system("PAUSE");
	return 0;
}

//Function to reverse the array
void reverseArray(int arr[], int start, int end)
{
	/*write code here*/

	int temp;

	while (start < end) {

		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}

}


//Function for printing arrays
void printArray(int arr[], int size)
{

	for (int i = 0; i < size; i++) {

		printf("%d", arr[i]);

	}

	printf("\n");
	/*write code here*/
}

void scaleArray(int arr[], int size) {

	for (int i = 0; i < size; i++) {

		if (arr[i] % 2 == 1) {
			arr[i] = 5 * arr[i];
		}

	}

}