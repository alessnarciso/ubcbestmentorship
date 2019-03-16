//Write a function to reverse an array.
//Only reverse array if at least one of the values in indexes of search are prime
//Scale odd values within array by 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int start, int end);
void printArray(int arr[], int len);
void scaleArray(int arr[], int len);
int isPrime(int num);

int main(void) {
	int arr[] = { 100, 17, 25, 3, 1, 80, 50, 2, 79, 62};
	//start index
	int start = 0;

	//end index
	int end = 9;

	//length of array
	int len = 10;
	
	//print orginal array
	printf("Original array: \n");
	printArray(arr, len);

	//reverse array
	reverseArray(arr, start, end);

	//print reverse array
	printf("Reverse array: \n");
	printArray(arr, len);

	//scale array
	scaleArray(arr, len);

	//print scaled reverse array
	printf("Scaled array: \n");
	printArray(arr, len);

	system("PAUSE");
	return 0;
}

//Function to reverse the array
void reverseArray(int arr[], int start, int end)
{
	//set variables for index and temporary value
	int i, temp;

	//run for loop to switch values until (end/2) index
	for (i = start; i <= (end / 2); i++) {
		//check for prime
		int num1, num2, num1Prime, num2Prime;
		num1 = arr[i];
		num2 = arr[end - i];

		num1Prime = isPrime(num1);
		num2Prime = isPrime(num2);

		//reverse only if at least 1 of evaluated numbers are prime
		if (num1Prime == 1 || num2Prime == 1) {
			// temporary variable = value to be switched with
			temp = arr[end - i];

			//reassign values with temp and arr[i]
			arr[end - i] = arr[i];
			arr[i] = temp;
		}
	}
}

// scale by 5 only if value at index is odd
void scaleArray(int arr[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 5;
		}
	}
}

//if number is 1, return 0
//else, divide num by 2 and increment by 1 until it reaches (num - 1)
//      if remainder is always non-zero until i reaches (num - 1), return 1 (ie. number evaluated is prime)
//      if remainder == 0 at any point before, return 0 (ie. number evaluated is not prime)

int isPrime(int num) {
	//1 is not prime
	if (num == 1) {
		return 0;
	}

	//go through loop for every other num
	int i = 2;
	while (i < num) {
		if (num % i == 0) {
			return 0;
		}
		else {
			i++;
		}
	}

	return 1;
}

void printArray(int arr[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}