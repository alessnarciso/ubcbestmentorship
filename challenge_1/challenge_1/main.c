//
//  challenge_1.c
//  prac_prob_3
//
//  Created by Alessandro Narciso on 2019-03-15.
//  Copyright © 2019 Alessandro Narciso. All rights reserved.
//
//Note: We are trying to use this to reverse the array: {1, 2, 3, 4, 5, 6}

//challenge: if the number in the array is odd, multiply it by 5

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

void printArray(int arr[], int size)
{
    //Variable for array for loop counter
    int i;
    
    //For loop to print array, iterating through index values i
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

//Function for printing arrays
void scaleArray(int arr[], int size)
{
    //Variable for array for loop counter
    int i;
    
    //For loop iterating through index values i
    for (i=0; i < size; i++){
        
        //If the value is odd, then scale by factor 5
        if(arr[i]%2 == 1)
            arr[i]=5*arr[i];
        
        //If even, leave as is
        else
            arr[i] = arr[i];
    }
}

//Main function that calls to other functions
int main(void)
{
    //Array we will be reversing
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    //Print original array
    printf("Original array is: \n");//Output for user feedback
    printArray(arr, 6);//Call to function to print array
    
    //Reverse array
    rvereseArray(arr, 0, 5); //Call to function to reverse array
    printf("Reversed array is: \n"); //Output for user feedback
    printArray(arr, 6); //Call to function to print array
    
    //Output for user feedback
    printf("Scaled array is: \n"); //Output for user feedback
    scaleArray(arr, 6); //Call to function to scale array
    printArray(arr, 6); //Call to function to print array
    
    return 0;
}
