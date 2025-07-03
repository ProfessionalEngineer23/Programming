#include <stdio.h> //Include standard I/O library
#include <time.h> //Include time library 
#include <stdlib.h> //Include standard library
#include <unistd.h> //Include unix standard header file
#include <math.h> //Include math functions file 

int main () //Main function 
{
int arg1; //Declaring arg1 as an integer
do{printf("Please select a number between 1 and 5 only:"); //Do while loop that prints instruction and will repeat if user input is not within range
scanf("%d",&arg1);} //Assigns inputted value to arg1 variable
while(arg1>5||arg1<1); //While loop condition to that executes whenever user input is more than 5 or less than 1

if(arg1<6&&arg1>0) //If statement to lead the main function to decide whether or not the rest of the code should be executed
{ 
switch (arg1) //Switch cases with arg1  values
{
case 1: //If user inputs a 1
printf("HelloWorld!"); //Simple print function to print HelloWorld!
break; //Break from case 1 and run next code

case 2: //If user inputs 2
srand(time(NULL)); //calls functio from stdlib.h  and inputs time as null
int r= rand()%6+1,t= rand()%6+1,x = rand()%6+1; //assigns 'r,t,x' their random values between 1 and 6
printf("You rolled %d,\t%d,\t%d,\t",r,t,x); //Prints the values of the three standard dice rolled
break; //Break from case 2 and run next code

case 3: //If user inputs a 3
time_t nows = time(NULL); //Defines nows variable
printf(""); //Prints a space
int years=(1970+nows/60/60/24/365); //Defines years as an integer and calculates years since 01/01/1970 by converting from seconds into years
printf("Year now:%d",years); //Prints the current year
break; //Break from case 3 and run next code

case 4: //If user inputs a 4
float W, H, BMI; //Defines float variables
float bmi(float W, float H){return BMI=(W/(H*H));} //Function that takes in variables W, H to calculate and return BMI value
printf("Please enter your Weight in Kg:");scanf("%f",&W); //Asks user to input their weight in Kg and assigns the value to W
printf("Please enter your Height in m:");scanf("%f",&H); //Asks user to input their height in meters and assigns the value to m
BMI=bmi(W,H); //Defines BMI in float as the function
printf("The BMI is %f\n", BMI); //Prints the Body Mass Index
if(BMI<18.5){printf("Underweight BMI\n");} //If statent for Underweight category 
if(BMI>18.5&&BMI<25){printf("Normal Weight BMI\n");}//If statent for Normal category 
if(BMI>25&&BMI<30){printf("Overweight BMI\n");} //If statent for Overweight category 
if(BMI>30){printf("Obese BMI\n");} //If statent for Obese category 
break; //Break from case 4 and run next code

case 5:
int decision = 1, decision1 = 1, numbers[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}}, row, column; //Defines integer values, 2D array
do{printf("Buy a refreshing drink?\nInput 1 for Yes and 0 for No:"); //Do while loop to determine whether the user wishes to buy a drink
scanf("%d", &decision);} //Assigns user input to decision integer
while(decision >1||decision<0); //While condition that asks if the user's input number was within range

if(decision==0){printf("Get Out!\nᕙ( ᗒᗣᗕ )ᕗ\n ▄︻テ══━一💥"); return 0;} //If statement that tells the user that the full program will not execute

   while(decision1==1){ //While loop condition asking if the the user input a yes or a no
printf("\n\nOPTIONS:\n00 is Guinness\n01 is Heineken\n02 is Coors light\n10 is Birra Moretti\n11 is Orchard Thieves\n12 is Rockshore\n20 is Bulmers\n21 is WKD a drink for women\n22 is Smirnoff Vodka\n\nInput one digit at a time!\n\nChoose carefully to not select the wrong one and NO REFUNDS!");
//Top line (Line 58) prints the options of drinks
   printf("\nChoice:"); //Prints choice to signal the user to input numbers
   scanf("%d%d", &row, &column); //Assigns user input numbers to row and then comlumn
   if(row==0&&column==0){printf("You got a Guinness!\n🍺");} //If user selected Guinness
   else if(row==0&&column==1){printf("You got a Heineken!\n🍺");} //If user selected Heineken
   if(row==0&&column==2){printf("You got a Coors light!\n🍺");} //If user selected Coors Light
   else if(row==1&&column==0){printf("You got a Birra Moretti!\n🍺");} //If user selected Birra Moretti
   if(row==1&&column==1){printf("You got a Orchardthieves!\n🍺");} //If user selected Orchardthieves
   else if(row==1&&column==2){printf("You got a Rockshore!\n🍺");} //If user selected Rockshore
   if(row==2&&column==0){printf("You got a Bulmers!\n🍺");} //If user selected Bulmers
   else if(row==2&&column==1){printf("You got a WKD!?\n🍺");} //If user selected WKD
   if(row==2&&column==2){printf("You got a Smirnoff Vodka!\n🍺");} //If user selected Smirnoff Vodka
   else if (row>2||row<0||column>2||column<0) {do{printf("\nThere is no such option!\nTry again? 1 for Yes 0 for No:"); //If row or column values are out of range then a warning appears and asks if the user wants to retry
       scanf("%d", &decision1);} //Assigs user input to decision1
       while(decision1>1||decision1<0);} // While loop to ask the user to input an option within specified range
      else{ printf("\nMore? 1 for Yes 0 for No:"); //If user successfully got a drink the program will ask if the want to order more
       scanf("%d", &decision1);} //Asigns user's input to decision1
}
break; //Break from case 5 and run next code
return 0; //End of main function
}}}
//<Work in progress>