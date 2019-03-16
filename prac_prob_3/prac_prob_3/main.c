//
//  main.c
//  prac_prob_3
//
//  Created by Alessandro Narciso on 2019-03-15.
//  Copyright © 2019 Alessandro Narciso. All rights reserved.
//
//Note: We are trying to use this to reverse the array: {1, 2, 3, 4, 5, 6}

#include <stdio.h>


//Function to reverse the array
void rvereseArray(int arr[], int start, int end)
{
    //Use temp to hold values from one array when swapping placement
    int temp;
    
    //Loop for reversing
    while (start < end)
    {
        temp = arr[start]; //Temp holds value at index start
        arr[start] = arr[end]; //Value at index start takes the value at index end
        arr[end] = temp; //Value at index end takes the value temp is holding (original value at index start)
        
        //Moving indices to reverse next values
        start++;
        end--;
    }
}

//Function for printing arrays
void printArray(int arr[], int size)
{
    //Variable for array for loop counter
    int i;
    
    //For loop to print array, iterating through index values i
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

//Main function that calls to other functions
int main()
{
    //Array we will be reversing
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    //Print original array
    printf("Original array is: \n");
    printArray(arr, 6);
    
    //Call to function to reverse array
    rvereseArray(arr, 0, 5);
    
    //Output for user feedback
    printf("Reversed array is: \n");
    printArray(arr, 6); //Call to function to print array
    return 0;
}
