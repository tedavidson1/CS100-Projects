//Thomas Davidson
//This program calculates the profit and profit per cup
//from the lemonade stand.
#include <stdio.h>
int main(){
  //all variables initialized
  double cupsSugar;
  int lemonsUsed;
  int smallCups;
  int largeCups;
  int refills;
  //All prints and scans
  printf("Enter the number of cups of sugar used (real number):");
  scanf("%lf", &cupsSugar);
  printf("Enter the number of lemons used (integer):");
  scanf("%d", &lemonsUsed);
  printf("Enter the number of small cups of lemonade sold (integer):");
  scanf("%d", &smallCups);
  printf("Enter the number of large cups of lemonade sold (integer):");
  scanf("%d", &largeCups);
  printf("Enter the number of refills sold (integer):");
  scanf("%d", &refills);
  //variables made for sales and expenditures. Makes math a bit easier
  double sales = ((smallCups * 2.00) + (largeCups * 3.25) + (refills * 1.25));
  double expenditures =((cupsSugar * 0.19) + (lemonsUsed * 0.48) + (smallCups * 0.14) + (largeCups * 0.18));
  double profit = sales - expenditures;
  double profitPerCup = profit / (smallCups + largeCups + refills);
  printf("You made $%lf in profit from your lemonade stand today!\n", profit);
  printf("On average, you made $%lf in profit per cup!\n", profitPerCup);
return 0;
}
