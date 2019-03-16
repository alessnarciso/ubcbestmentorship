//Write a function to reverse an array.
//Note: We are trying to use this to reverse the array: {1, 2, 3, 4, 5, 6}

#include <stdio.h>


//Function to reverse the array
void reverseArray(int arr[], int start, int end)
{
	int temp;
    /*write code here*/
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
    /*write code here*/
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

void scaleArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] *= 5;
		}
		else {
			arr[i] = arr[i];
		}
	}
}

//Main function that calls to other functions
int main()
{
    //Array we will be reversing
    //int arr[] = {1, 2, 3, 4, 5, 6};
	int arr[] = {1, 2, 3, 4, 5, 6};
    
    //Print original array
    //printf("Original array is: \n");
    //printArray(arr, 6);
	printf("Original array is: \n");
	printArray(arr, 6);
    
    //Call to function to reverse array
    /*write code here*/
	reverseArray(arr, 0, 5);
	

    //Output for user feedback
    //printf("Reversed array is: \n");
    //printArray(arr, 6); //Call to function to print array
	printf("Reversed array is: \n");
	printArray(arr, 6); //Call to function to print array
	//Call function to scale array and print
	scaleArray(arr, 6);
	printf("Scaled array is: \n");
	printArray(arr, 6); //Call to function to print array
    return 0;
}
