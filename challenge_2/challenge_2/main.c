//
//  main.c
//  challenge_2
//
//  Created by Alessandro Narciso on 2019-03-16.
//  Copyright © 2019 Alessandro Narciso. All rights reserved.
//
//Harder challenge: only if one or more of the numbers are prime, swap the places

//{100,17,25,3,1,80,50,2,79,62}
//{comp, prime, comp, prime, comp, comp, comp, prime, prime, comp}
//{1, 2, 3, 4, 5, 5, 4, 3, 2, 1} 5 pairs
//pair 1, both comp, no swap
//pair 2, both prime, swap
//pair 3, one prime, swap
//pair 4, one prime, swap
//pair 5, both comp, no swap
//finished array should be: //{100,79,2,50,1,80,3,25,17,62}

#include <stdio.h>

//Function for printing arrays
//If prime, will return 1; else, will return 0;
int isprime(int num)
{
    //Variables: j to iterate through natural numbers, flag to signal if num is prime
    int j, flag;
    
    //Check edge cases
    if(num <= 1)
        return 0; //0 and 1 are not prime
    
    //Set flag
    flag = 1;
    
    //Iterate through loop until num/2; start at 2 and increment through all natural numbers until limit
    for (j = 2; j <= num/2; j++)
    {
        //If num is divisible by a natural number j, it is not prime
        if ((num % j) == 0)
        {
            flag = 0; //flag signal not prime if divisible by a natural number
            break; //break loop to stop iterating and return value
        }
    }
    
    if (flag == 0)
        return 0; //number is not prime
    
    else
        return 1; //number is prime
}

//Function to reverse the array
void rvereseArray(int arr[], int start, int end)
{
    //Use temp to hold values from one array when swapping placement
    int temp;
    
    //Loop for reversing
    while (start < end)
    {
        if(isprime(arr[start]) == 1 || isprime(arr[end]) == 1){
            temp = arr[start]; //Temp holds value at index start
            arr[start] = arr[end]; //Value at index start takes the value at index end
            arr[end] = temp; //Value at index end takes the value temp is holding (original value at index start)
        }
        
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

//Main function that calls to other functions
int main(void)
{
    //Array we will be reversing
    int arr[] = {100,17,25,3,1,80,50,2,79,62};
    
    //Print original array
    printf("Original array is: \n");//Output for user feedback
    printArray(arr, 10);//Call to function to print array
    
    //Reverse array and check if prime
    rvereseArray(arr, 0, 9); //Call to function to reverse array (index value of edges as parameters)
    printf("Reversed array is: \n"); //Output for user feedback
    printArray(arr, 10); //Call to function to print array
    
    return 0;
}
