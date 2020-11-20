//Thomas Davidson
//This is my functions.c file. In it, I created
//5 functions to acquire and return data through main to the user
//I found columns with pointers and used while loops to
//iterate through everything.
//begin writing functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double getMin(char csvfile[], char column[]) //csvfile is the file
{       //return the minimum of the column requested
	FILE *fp = fopen(csvfile, "r");
	//parsing the data given by the user into chunks usable
        //in searching the csv file

	 char type[5] = {'\0'};
        char number[5] = {'\0'};
        char checkOptional[5] = {'\0'}; //
        char optionalSign[] = "(0)"; //

        strncpy(type, column, 1);

        char *numberPointer = column + 1;
        strncpy(number, numberPointer, 5);

        strncpy(checkOptional, optionalSign, 3); //


	char line[3000];
	fgets(line, 3000, fp);
	char temp[strlen(line)+1];
	strcpy(temp, line);

	int i=0;
   	char *start=temp;
	int existance = 0;
	while (1) {

	char *token = strsep(&start, ",");

	if (token==NULL) break; // no more
        i++;

	char *check = strstr(token, type);
	char *check2 = strstr(token, number);
	char *check3 = strstr(token, checkOptional);//

	if (check != NULL && check2 != NULL && check3 != NULL){//checks if optional
		return -1;
	}
	else if (check != NULL && check2 != NULL){ //checks if column exists
	//printf("%d: token=%s\n", i, token);
	existance = 0;
	break;
	}
	else {
		existance = 1;
	}
}
if (existance == 1) //if it doesn't exist
	return -2;
//have the max  amount to go over, now just go over until eof and compare along the way
double minimum = 1000.00;
while (1){
	fgets(line, 3000, fp);
	if (feof(fp)) break; //checks if the end, keeps going if it isn't
	char temp[strlen(line)+1];
        strcpy(temp, line);
	char *start = temp;
	int k = 0;
		while (1){
		char *token = strsep(&start, ",");
		if (token == NULL) break;
		k++;
		if (k == i){ //i is how far over you go for the column

			if (token[0] >= 48){
			//printf("%d is number, %s is whole \n", token[0],token);
			double n = atof(token);
			if (n < minimum){
				minimum = n;
				//printf("%lf and %lf\n", n, minimum);
			}

		//printf("%lf and %lf\n", n, minimum);
		}}}
	}
fclose(fp);
return minimum;
}
//end of minimum


double getMax(char csvfile[], char column[])
{
	FILE *fp = fopen(csvfile, "r");
	//parsing the data given by the user into chunks usable
        //in searching the csv file

	char type[5] = {'\0'};
        char number[5] = {'\0'};
	char checkOptional[5] = {'\0'}; //
	char optionalSign[] = "(0)"; //

        strncpy(type, column, 1);

	char *numberPointer = column + 1;
        strncpy(number, numberPointer, 5);

	strncpy(checkOptional, optionalSign, 3); //

	char line[3000];
	fgets(line, 3000, fp);
	char temp[strlen(line)+1];
	strcpy(temp, line);

	int i=0;
   	char *start=temp;
	int existance = 0;
	while (1) {

	char *token = strsep(&start, ",");

	if (token==NULL) break; // no more
        i++;

	char *check = strstr(token, type);
	char *check2 = strstr(token, number);
	char *check3 = strstr(token, checkOptional);//

	if (check != NULL && check2 != NULL && check3 != NULL){//checks if optional
		return -1;
	}
	else if (check != NULL && check2 != NULL){ //checks if column exists
	//printf("%d: token=%s\n", i, token);
	existance = 0;
	break;
	}
	else {
		existance = 1;
	}
}
if (existance == 1) //if it doesn't exist
	return -2;
//have the max  amount to go over, now just go over until eof and compare along the way
double maximum = -1000.00;
while (1){
	fgets(line, 3000, fp);
	if (feof(fp)) break; //checks if the end, keeps going if it isn't
	char temp[strlen(line)+1];
        strcpy(temp, line);
	char *start = temp;
	int k = 0;
		while (1){
		char *token = strsep(&start, ",");
		if (token == NULL) break;
		k++;
		if (k == i){ //i is how far over you go for the column

			if (token[0] >= 48){
			//printf("%d is number, %s is whole \n", token[0],token);
			double n = atof(token);
			if (n > maximum){
				maximum = n;
				//printf("%lf and %lf\n", n, maximum);
			}

		//printf("%lf and %lf\n", n, minimum);
		}}}
	}
fclose(fp);
return maximum;
}
//end of maximum

double getAvg(char csvfile[], char column[])
{
	FILE *fp = fopen(csvfile, "r");
	//parsing the data given by the user into chunks usable
        //in searching the csv file

	char type[5] = {'\0'};
        char number[5] = {'\0'};
	char checkOptional[5] = {'\0'}; //
	char optionalSign[] = "(0)"; //

        strncpy(type, column, 1);

	char *numberPointer = column + 1;
        strncpy(number, numberPointer, 5);

	strncpy(checkOptional, optionalSign, 3); //

	char line[3000];
	fgets(line, 3000, fp);
	char temp[strlen(line)+1];
	strcpy(temp, line);

	int i=0;
   	char *start=temp;
	int existance = 0;
	while (1) {

	char *token = strsep(&start, ",");

	if (token==NULL) break; // no more
        i++;

	char *check = strstr(token, type);
	char *check2 = strstr(token, number);
	char *check3 = strstr(token, checkOptional);//

	if (check != NULL && check2 != NULL && check3 != NULL){//checks if optional
		return -1;
	}
	else if (check != NULL && check2 != NULL){ //checks if column exists
	//printf("%d: token=%s\n", i, token);
	existance = 0;
	break;
	}
	else {
		existance = 1;
	}
}
if (existance == 1) //if it doesn't exist
	return -2;
//have the max  amount to go over, now just go over until eof and compare along the way
double sum = 0;
int counts = 0;

while (1){
	fgets(line, 3000, fp);
	if (feof(fp)) break; //checks if the end, keeps going if it isn't
	char temp[strlen(line)+1];
        strcpy(temp, line);
	char *start = temp;
	int k = 0;
		while (1){
		char *token = strsep(&start, ",");
		if (token == NULL) break;
		k++;
		if (k == i){ //i is how far over you go for the column

			if (token[0] >= 48){
			//printf("%d is number, %s is whole \n", token[0],token);
			double n = atof(token);
			sum = sum + n;
			counts++;
		//printf("%lf and %lf\n", n, minimum);
		}}}
	}
fclose(fp);
double average = (double) sum / counts;
return average;
}

int getCount(char csvfile[], char column[], double threshold)
{
	FILE *fp = fopen(csvfile, "r");
	//parsing the data given by the user into chunks usable
        //in searching the csv file

	char type[5] = {'\0'};
        char number[5] = {'\0'};
	char checkOptional[5] = {'\0'}; //
	char optionalSign[] = "(0)"; //

        strncpy(type, column, 1);

	char *numberPointer = column + 1;
        strncpy(number, numberPointer, 5);

	strncpy(checkOptional, optionalSign, 3); //

	char line[3000];
	fgets(line, 3000, fp);
	char temp[strlen(line)+1];
	strcpy(temp, line);

	int i=0;
   	char *start=temp;
	int existance = 0;
	while (1) {

	char *token = strsep(&start, ",");

	if (token==NULL) break; // no more
        i++;

	char *check = strstr(token, type);
	char *check2 = strstr(token, number);
	char *check3 = strstr(token, checkOptional);//

	if (check != NULL && check2 != NULL && check3 != NULL){//checks if optional
		return -1;
	}
	else if (check != NULL && check2 != NULL){ //checks if column exists
	//printf("%d: token=%s\n", i, token);
	existance = 0;
	break;
	}
	else {
		existance = 1;
	}
}
if (existance == 1) //if it doesn't exist
	return -2;
//have the max  amount to go over, now just go over until eof and compare along the way
int counts = 0;

while (1){
	fgets(line, 3000, fp);
	if (feof(fp)) break; //checks if the end, keeps going if it isn't
	char temp[strlen(line)+1];
        strcpy(temp, line);
	char *start = temp;
	int k = 0;
		while (1){
		char *token = strsep(&start, ",");
		if (token == NULL) break;
		k++;
		if (k == i){ //i is how far over you go for the column

			if (token[0] >= 48){
			//printf("%d is number, %s is whole \n", token[0],token);
			double n = atof(token);
			if (n >= threshold)
				counts++;
		//printf("%lf and %lf\n", n, minimum);
		}}}
	}
fclose(fp);
return counts;
}

double getGrade(char csvfile[], char first[], char last[])
{
       FILE *fp = fopen(csvfile, "r");

	char line[3000]; //set up for getting first line and and strsep
	fgets(line, 3000, fp);
	char temp[strlen(line)+1];
	strcpy(temp, line);

	int i=0;
   	char *start=temp;
	//char *token;
	int pointWeight [3000]; //array for holding weights

	while (1) {

	strsep(&start, "(");
	char *token = strsep(&start, ")"); //double strsep to get just the number inside the ()
	//printf("%s ", token);
	if (token==NULL) break;	// no more

	double n = atof(token);
	pointWeight[i] = n;
	i++;
	}
	//printf("\n");

//have all weights, now find the row

int totalWeight = 0;
double studentGrade = 0;
for (int k = 0; k < i; k++){
	totalWeight = totalWeight + pointWeight[k];
}
int j = 0;
//printf("%d\n", totalWeight);


while (1){
        fgets(line, 3000, fp);
        if (feof(fp)) break; //checks if the end, keeps going if it isn't
        char temp[strlen(line)+1];
        strcpy(temp, line);
        char *start = temp;

	 char *tokenLast = strsep(&start, ",");
                char *tokenFirst = strsep(&start, ",");
                //printf("%s %s\n", tokenLast, tokenFirst);
                if ((strcasecmp(tokenLast, last) == 0) && (strcasecmp(tokenFirst, first) == 0)){

			while (1){
			char *token = strsep(&start, ",");
			if (token == NULL) break;
			double value = atof(token);
			studentGrade = studentGrade + (value * pointWeight[j]);
					j++;
           	}
		return (studentGrade / (double) totalWeight);
	}
}
fclose(fp);
return -2;
}
