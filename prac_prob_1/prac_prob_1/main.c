//
//  main.c
//  prac_prob_1
//
//  Created by Alessandro Narciso on 2019-03-15.
//  Copyright © 2019 Alessandro Narciso. All rights reserved.
//
//Write a C program to compute the sum of the two given integer values. If the two values are the same, then return triple their sum.

#include <stdio.h>

int main(void){
    
    //Variables
    int num1,num2,sum;
    
    //Output for User Prompt
    printf("Input your numbers\n");
    
    //Input for User
    scanf("%d", &num1);
    scanf("%d", &num2);
    
    //Conditional Logic
    //Exception Case
    if(num1 == num2)
        sum = 3*(num1 + num2);
    
    //Other Cases
    else
        sum = num1 + num2;
    
    //Final Output
    printf("%d\n",sum);
}

