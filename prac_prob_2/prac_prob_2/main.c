//
//  main.c
//  prac_prob_2
//
//  Created by Alessandro Narciso on 2019-03-15.
//  Copyright © 2019 Alessandro Narciso. All rights reserved.
//
//Write a program in C to display the pattern like right angle triangle with a number.
//The pattern's like this:
//1
//12
//123
//1234

#include <stdio.h>
int main(void){
    
    //Variables
    int i,j,rows;
    
    //Output for User Prompt
    printf("Input number of rows: ");
    
    //Input for User
    scanf("%d",&rows);
    
    //Loop Logic
    //Loop for how many rows will be printed
    for(i=1;i<=rows;i++)
    {
        //Loop for what numbers will be printed in each row
        //j<=i condition so that the row number is the last digit printed
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
            
        }
        
        //Print new line after every row printed for pyramid pattern
        printf("\n");
        
    }
    
}
