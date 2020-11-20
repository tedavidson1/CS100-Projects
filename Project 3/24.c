//Thomas Davidson
//This is my twenty four game calculator. It uses a double loop
//in the main method to permutate through all possibilities
//I wrote a function to make main a lot cleaner. It passes by pointer
//all the data I need to print a proper result.

#include <stdio.h>
#include "permute.h"

int OperatorSolver(int array[], int determine, int *op1, int *op2, int *op3, int *type)
{
double temp = 0;
double temp2 = 0;
double temp3 = 0;

int i = 0, k = 0, j = 0;

if (determine == 0){
  for (i = 0; i < 4; i++){ //case 1: 123 on sheet
    for (j = 0; j < 4; j++){
      for (k = 0; k < 4; k++){

        if (i == 0) temp = array[0] + array[1];
        else if (i == 1) temp = array[0] - array[1];
        else if (i == 2) temp = array[0] * array[1];
        else temp = (double) array[0] / array[1];

        if (j == 0) temp = temp + array[2];
        else if (j == 1) temp = temp - array[2];
        else if (j == 2) temp = temp * array[2];
        else temp = (double) temp / array[2];

        if (k == 0) temp = temp + array[3];
        else if (k == 1) temp = temp - array[3];
        else if (k == 2) temp = temp * array[3];
        else temp = (double) temp / array[3];

        if (24 - 0.0001 < temp && temp < 24 + 0.0001){
            *op1 = i;
            *op2 = j;
            *op3 = k;
            *type = determine;
          return 1;
        }
}}}}

if (determine == 1){
for (i = 0; i < 4; i++){ //case 2: 132 on sheet
  for (j = 0; j < 4; j++){
    for (k = 0; k < 4; k++){

      if (i == 0) temp = array[0] + array[1];
      else if (i == 1) temp = array[0] - array[1];
      else if (i == 2) temp = array[0] * array[1];
      else if (i == 3) temp =  (double) array[0] / array[1];

      if (j == 0) temp2 = array[2] + array[3];
      else if (j == 1) temp2 = array[2] - array[3];
      else if (j == 2) temp2 = array[2] * array[3];
      else if (j == 3) temp2 =  (double) array[2] / array[3];

      if (k == 0) temp3 = temp + temp2;
      else if (k == 1) temp3 = temp - temp2;
      else if (k == 2) temp3 = temp * temp2;
      else if (k == 3) temp3 =  (double) temp / temp2;

      if (24 - 0.0001 < temp3 && temp3 < 24 + 0.0001){
        *op1 = i;
        *op2 = j;
        *op3 = k;
        *type = determine;
        return 1;
      }
}}}}

if (determine == 2){
for (i = 0; i < 4; i++){ //case 3: 213 on sheet
  for (j = 0; j < 4; j++){
    for (k = 0; k < 4; k++){

      if (i == 0) temp = array[1] + array[2];
      else if (i == 1) temp = array[1] - array[2];
      else if (i == 2) temp = array[1] * array[2];
      else if (i == 3) temp =  (double) array[1] / array[2];

      if (j == 0) temp = array[0] + temp;
      else if (j == 1) temp = array[0] - temp;
      else if (j == 2) temp = array[0] * temp;
      else if (j == 3) temp =  (double) array[0] / temp;

      if (k == 0) temp = temp + array[3];
      else if (k == 1) temp = temp - array[3];
      else if (k == 2) temp = temp * array[3];
      else if (k == 3) temp =  (double) temp / array[3];

      if (24 - 0.0001 < temp && temp < 24 + 0.0001){
        *op1 = i;
        *op2 = j;
        *op3 = k;
        *type = determine;
        return 1;
      }
}}}}

if (determine == 3){
for (i = 0; i < 4; i++){ //case 4: 231 on sheet
  for (j = 0; j < 4; j++){
    for (k = 0; k < 4; k++){

      if (i == 0) temp = array[1] + array[2];
      else if (i == 1) temp = array[1] - array[2];
      else if (i == 2) temp = array[1] * array[2];
      else if (i == 3) temp =  (double) array[1] / array[2];

      if (j == 0) temp = temp + array[3];
      else if (j == 1) temp = temp - array[3];
      else if (j == 2) temp = temp * array[3];
      else if (j == 3) temp =  (double) temp / array[3];

      if (k == 0) temp = array[0] + temp;
      else if (k == 1) temp = array[0] - temp;
      else if (k == 2) temp = array[0] * temp;
      else if (k == 3) temp =  (double) array[0] / temp;

      if (24 - 0.0001 < temp && temp < 24 + 0.0001){
        *op1 = i;
        *op2 = j;
        *op3 = k;
        *type = determine;
        return 1;
      }
}}}}

if (determine == 4){
for (i = 0; i < 4; i++){ //case 5: 321 on sheet
  for (j = 0; j < 4; j++){
    for (k = 0; k < 4; k++){

      if (i == 0) temp = array[2] + array[3];
      else if (i == 1) temp = array[2] - array[3];
      else if (i == 2) temp = array[2] * array[3];
      else if (i == 3) temp =  (double) array[2] / array[3];

      if (j == 0) temp = array[1] + temp;
      else if (j == 1) temp = array[1] - temp;
      else if (j == 2) temp = array[1] * temp;
      else if (j == 3) temp =  (double) array[1] / temp;

      if (k == 0) temp = array[0] + temp;
      else if (k == 1) temp = array[0] - temp;
      else if (k == 2) temp = array[0] * temp;
      else if (k == 3) temp =  (double) array[0] / temp;

      if (24 - 0.0001 < temp && temp < 24 + 0.0001){
        *op1 = i;
        *op2 = j;
        *op3 = k;
        *type = determine;
        return 1;
      }
}}}}
return 0;
}// end of function

//findNext: checks if next order exists. If it does, it makes the array the new order
//sortArray: sorts into ascending order
//printArray: prints the array in one line

int main(void){

  int op1, op2, op3, type; //use to hold the operators
  int array[4]; // array of 4 numbers
  char str[] = "+-*/";
  printf("Enter 4 integers ranging from 1 through 10: ");

for (int i=0; i<4; i++){
    scanf("%d", &array[i]);
  }

sortArray(4, array); //array now ordered numerically

for (int i = 0; i < 24; i++){  //begin all the checking
  for (int determine = 0; determine < 5; determine++){
    if (OperatorSolver(array, determine, &op1, &op2, &op3, &type) == 1)
      goto printTime;
    }
  findNext(4, array);
}
// end of loop

printf("No solution\n");
return 0;
printTime:

if (type == 0)
  printf("((%d %c %d) %c %d) %c %d = 24\n", array[0], str[op1], array[1], str[op2], array[2], str[op3], array[3]);

if (type == 1)
  printf("(%d %c %d) %c (%d %c %d) = 24\n", array[0], str[op1], array[1], str[op3], array[2], str[op2], array[3]);

if (type == 2)
  printf("(%d %c (%d %c %d)) %c %d = 24\n", array[0], str[op2], array[1], str[op1], array[2], str[op3], array[3]);

if (type == 3)
  printf("%d %c ((%d %c %d) %c %d) = 24\n", array[0], str[op3], array[1], str[op1], array[2], str[op2], array[3]);

if (type == 4)
  printf("%d %c (%d %c (%d %c %d)) = 24\n", array[0], str[op3], array[1], str[op2], array[2], str[op1], array[3]);


  //printf("%d %d %d %d\n", op1, op2, op3, type);
return 0;
}
