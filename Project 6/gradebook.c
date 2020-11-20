/*Thomas Davidson
This is my gradebook.c. I learned a lot about
linked lists through this project. I utilized helper Functions
to prevent reuse of the same search code or
instantiation code. I order the list by the proper method
for each function. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gradebook.h"

//Helper Functions
///////////////////////////////////////////////////////////////////
Student *createStudent(char last[], char first[], Student *headStudentList)
{
	Student *ptr = malloc(sizeof(Student));
	ptr->lastName = malloc( strlen(last) + 1 );
	strcpy(ptr->lastName, last);
	ptr->firstName = malloc( strlen(first) + 1 );
	strcpy(ptr->firstName, first);
	ptr->next = headStudentList;
	ptr->headGradeList = NULL;
	return ptr;
}

Grade *createGrade(char gradeName[], double value, Grade *head)
{
	Grade *ptr = malloc(sizeof(Grade));
	for (int i = 0; i <= strlen((gradeName) + 1); i++){
		ptr->name[i] = gradeName[i];
	}
	ptr->value = value;
	ptr->next = head;
	return ptr;
}

Student *searchName(Student *headStudentList, char last[], char first[])
{
	for (Student *cur = headStudentList; cur != NULL; cur = cur->next){
		if ((strcmp(cur->lastName, last) == 0) && (strcmp(cur->firstName, first) == 0)){
				return cur;
			}
		}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student to the list of students
//	   1. Make sure a student by that name does not exist (print an error message and do nothing if it exists)
//	   2. Add a new student with that name (add-at-front)

Student* addStudent(Student *headStudentList, char last[], char first[])
{
	Student *check = searchName(headStudentList, last, first);
	if (check != NULL){
			printf("Error: Student already exists\n");
			return headStudentList;
		}
	return createStudent(last, first, headStudentList);
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a grade to the specified student
//   1. Make sure a student by that name exists (so you can add grade to it)
//   2. If the specifed grade already exists, update the grade's value to the new value
//   3. Otherwise, add the grade to the end of the student's grade list (add-at-end)
Grade *searchGrade (Student *individual, char gradeName[])
{
	for (Grade *cur = individual->headGradeList; cur != NULL; cur = cur->next){
		if (strcmp(cur->name, gradeName) == 0){
			return cur;
		}
	}
	return NULL;
}

void addGrade(Student *headStudentList, char last[], char first[], char gradeName[], double value)
{
	 Student *check = searchName(headStudentList, last, first);
	 	if (check == NULL){
			printf("Error: Student does not exist\n");
			return;
		}
	 //we now know that student exists
	//now check if the grade exists

	if (check->headGradeList == NULL){
		check ->headGradeList = createGrade(gradeName, value, check->headGradeList);
		//printf("Empty List\n");
		return;
	}

	for (Grade *cur = check->headGradeList; cur != NULL; cur = cur->next) {

		if (strcmp(cur->name, gradeName) == 0){ //if grade exists
			cur->value = value;
			return;
		}

		if (cur->next == NULL) { //if grade does not exist
			Grade *newGrade = createGrade(gradeName, value, NULL);
			cur->next = newGrade;
			//printf("I put the grade in.\n");
			return;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
// return the number of students in the list
// Iterate through the student list to count the number of students, return that count

int count(Student *headStudentList)
{
	int count = 0;
	for (Student *cur = headStudentList; cur != NULL; cur = cur->next){
		count++;
	}
return count;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the grades for a given student
//	1. Make sure a student with that name exists
//	2. Print the name of that student
//	3. Print all the "grade name: grade value" pairs for that student

void printStudent(Student *headStudentList, char last[], char first[])
{
	Student *check = searchName(headStudentList, last, first);
	if (check == NULL){
			printf("Error: Student does not exist\n");
			return;
		}
		printf("Student Name: %s, %s\n", check->lastName, check->firstName);

		for (Grade *cur = check->headGradeList; cur != NULL; cur = cur->next){
			printf("\t%s : %lf\n", cur->name, cur->value);
		}
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the students
// If the student list is empty, print a message to indicate it.
// Otherwise, for each student
//	   a. Print the name of that student
//	   b. Print all the "grade name: grade value" pairs for that student

void print(Student *headStudentList)
{
	if (headStudentList == NULL){
		printf("Student List is empty.\n");
		return;
	}

	for (Student *person = headStudentList; person != NULL; person = person->next){
		printf("\n");
		printf("Student Name: %s, %s\n", person->lastName, person->firstName);
		for (Grade *cur = person->headGradeList; cur != NULL; cur = cur->next){
			printf("\t%s : %lf\n", cur->name, cur->value);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student (in alphabetical order)
//	1. Make sure a student by that name does not exist
//	2. Add a student with that name (add-in-order)

int compareStudentLastName(Student *ptr1, Student *ptr2)
{
	//printf("Last name comparsion: %d\n", strcmp(ptr1->lastName, ptr2->lastName));
	if (strcmp(ptr1->lastName, ptr2->lastName) < 0) return -1; //comes before
	if (strcmp(ptr1->lastName, ptr2->lastName) > 0) return 1;  //comes after
	if (strcmp(ptr1->lastName, ptr2->lastName) == 0) return 0; //equal. Need to compare first names
return -100;
}

int compareStudentFirstName(Student *ptr1, Student *ptr2)
{
	//printf("%d: New compared to list\n", strcmp(ptr1->firstName, ptr2->firstName));

	if (strcmp(ptr1->firstName, ptr2->firstName) < 0) return -1;
	if (strcmp(ptr1->firstName, ptr2->firstName) > 0) return 1;  //comes after
return -100;
}


Student *addStudentOrdered(Student *headStudentList, char last[], char first[])
{
	Student *check = searchName(headStudentList, last, first);
	if (check != NULL){
		printf("Error: Student already exists\n");
		return headStudentList;
	}

/////////////////////if the student doesn't exist////////////////////////////
Student *new = createStudent(last, first, NULL);

// case #1: list is empty
if (headStudentList == NULL) return new;

// case #2: comes before all students
if ((compareStudentLastName(new, headStudentList) == -1) || ((compareStudentLastName(new, headStudentList) == 0) && (compareStudentFirstName(new, headStudentList) == -1))) {
	new->next = headStudentList;
	//printf("Case 2\n");
	return new;
}

// search
for (Student *cur = headStudentList; cur != NULL; cur = cur->next) {
//printf("%s\n", cur->lastName);
	if (cur->next == NULL) { // case #3: cur is the last node, add rear
		if ((compareStudentLastName(new, cur) == 1) || ((compareStudentLastName(new, cur) == 0) && (compareStudentFirstName(new, cur) == 1))){
			//printf("Case 3\n");
		cur->next = new;
		return headStudentList;
		}
	}
	if ((compareStudentLastName(new, cur->next) == -1) || ((compareStudentLastName(new, cur->next) == 0) && (compareStudentFirstName(new, cur->next) == -1)))  { // case #4, insert between cur and cur->next
		//printf("Case 4\n");
		new->next = cur->next;
		cur->next = new;
		return headStudentList;
	}
}
return NULL; // unreachable
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a grade to the specified student in order
//	1. Make sure a student by that name exists (so you can add a grade to the student)
//	2. If the grade already exists, update the value
//	3. Otherwise, add the grade to the student (add-in-order)

int compareGradeChapter(Grade *ptr1, Grade *ptr2){
	char grade1[10] = {'\0'};
	char grade2[10] = {'\0'};

	int i = 0;
	int j = 0;
//lame way to get everything before the . for comparison
while (ptr1->name[i+1] != '.'){
	grade1[i] = ptr1->name[i+1];
	i++;
}

while (ptr2->name[j+1] != '.'){
	grade2[j] = ptr2->name[j+1];
	j++;
}
int grade1Num = atoi(grade1);
int grade2Num = atoi(grade2);
//printf("1: %d 2: %d\n", grade1Num, grade2Num);

//printf("%s and %s\n", grade1, grade2);
//printf("%d\n", strcmp(grade1, grade2));
if (grade1Num < grade2Num) return -1; //comes before
if (grade1Num > grade2Num) return 1;  //comes after
if (grade1Num == grade2Num) return 0; //equal
return -100;
}

int compareGradeSection(Grade *ptr1, Grade *ptr2){
	char grade1[10] = {'\0'};
	char grade2[10] = {'\0'};

	int i = 0;
	int j = 0;
//being lame again
while (ptr1->name[i] != '.'){
	i++;
}

while (ptr2->name[j] != '.'){
	j++;
}
//reused code to find value where . is. You know what that means?
while (ptr1->name[i] != '\0'){
	grade1[i] = ptr1->name[i+1];
	i++;
}

while (ptr2->name[j] != '\0'){
	grade2[j] = ptr2->name[j+1];
	j++;
}

int grade1Num = atoi(grade1);
int grade2Num = atoi(grade2);
//printf("1: %d 2: %d\n", grade1Num, grade2Num);

//printf("%s and %s\n", grade1, grade2);
//printf("%d\n", strcmp(grade1, grade2));
if (grade1Num < grade2Num) return -1; //comes before
if (grade1Num > grade2Num) return 1;  //comes after
if (grade1Num == grade2Num) return 0; //equal
return -100;
}

int compareGradeType(Grade *ptr1, Grade *ptr2){
	if (ptr1->name[0] == 'P') return -1;

	if (ptr1->name[0] == 'C'){
		if (ptr2->name[0] == 'L') return -1;
		else return 1;
	}
	if (ptr1->name[0] == 'L') return 1;
return -100;
}


void addGradeOrdered(Student *headStudentList, char last[], char first[], char gradeName[], double value)
{
	//if student even exists
	Student *check = searchName(headStudentList, last, first);
	if (check == NULL){
		printf("Error: Student does not exist\n");
		return;
	}
	//checks if grade already exists, modifies if it does
	Grade *flag = searchGrade(check, gradeName);
		if (flag != NULL){
			flag->value = value;
			return;
		}

		/////////////////////if the grade doesn't exist////////////////////////////
		Grade *new = createGrade(gradeName, value, NULL);

		// case #1: list is empty
		if (check->headGradeList == NULL){
			check->headGradeList = new;
			return;
		}

		// case #2: comes before every other grade
		if ((compareGradeChapter(new, check->headGradeList) == -1) || ((compareGradeChapter(new, check->headGradeList) == 0) && (compareGradeSection(new, check->headGradeList) == -1)) || ((compareGradeChapter(new, check->headGradeList) == 0) && (compareGradeSection(new, check->headGradeList) == 0) && (compareGradeType(new,check->headGradeList) == -1))){
			new->next = check->headGradeList;
			check->headGradeList = new;
			//printf("Case 2\n");
			return;
		}

		// search
		for (Grade *cur = check->headGradeList; cur != NULL; cur = cur->next) {
			if (cur->next == NULL) { // case #3: cur is the last node, add rear
				if ((compareGradeChapter(new, cur) == 1) || ((compareGradeChapter(new, cur) == 0) && (compareGradeSection(new, cur) == 1)) || ((compareGradeChapter(new, cur) == 0) && (compareGradeSection(new, cur) == 0) && (compareGradeType(new, cur) == 1))){
					//printf("Case 3\n");
				cur->next = new;
				return;
				}
			}
			// case #4, insert between cur and cur->next
			if ((compareGradeChapter(new, cur->next) == -1) || ((compareGradeChapter(new, cur->next) == 0) && (compareGradeSection(new, cur->next) == -1)) || ((compareGradeChapter(new, cur->next) == 0) && (compareGradeSection(new, cur->next) == 0) && (compareGradeType(new, cur->next) == -1))){
				//printf("Case 4\n");
				new->next = cur->next;
				cur->next = new;
				return;
			}
		}
		return; // unreachable
		}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a grade from a student
//	1. Make sure a student with that name exists
//	2. Make sure the grade exists in that student
//	3. Remove the grade from that student

void removeGrade(Student *headStudentList, char last[], char first[], char gradeName[])
{
	//if student even exists
	Student *check = searchName(headStudentList, last, first);
	if (check == NULL){
		printf("Error: Student does not exist\n");
		return;
	}
	//check if student has that grade
	Grade *gradeCheck = searchGrade(check, gradeName);
	if (gradeCheck == NULL){
		printf("Error: Grade does not exist\n");
		return;
	}

	//if the grade is the head
	if (strcmp(check->headGradeList->name, gradeName) == 0){
		Grade *del = check->headGradeList;
		check->headGradeList = check->headGradeList->next;
		free(del);
		return;
	}

	//other cases
	for (Grade *cur = check->headGradeList; cur != NULL; cur = cur->next){
		if (strcmp(cur->next->name, gradeName) == 0){
			Grade *del = cur->next;
			cur->next = cur->next->next;
			free(del);
			return;
		}
	}
return;
}
/////////////////////////////////////////////////////////////////////////////////////////////
// remove a student
//	1. Make sure a student with that name exists
//	2. Remove that student and all the grades of that student

Student *removeStudent(Student *headStudentList, char last[], char first[])
{
	//if the student even exists
	Student *check = searchName(headStudentList, last, first);
	if (check == NULL){
		printf("Error: Student does not exist\n");
		return headStudentList;
	}

	//if the head is the target student
	if ((strcmp(headStudentList->lastName, last) == 0) && (strcmp(headStudentList->firstName, first) == 0)){
		Student *del = headStudentList;
		headStudentList = headStudentList->next;
		for (Grade *cur = del->headGradeList; cur != NULL; cur = cur->next){
			free(cur);
		}
		free(del->lastName); //must free names
		free(del->firstName); //as they were malloced too
		free(del);
		return headStudentList;
		}

		for (Student *cur = headStudentList; cur != NULL; cur = cur->next){
			if ((strcmp(cur->next->lastName, last) == 0) && (strcmp(cur->next->firstName, first) == 0)){
				Student *del = cur->next;
				cur->next = cur->next->next;
				for (Grade *clear = del->headGradeList; clear != NULL; clear = clear->next){
					free(clear);
				}
				free(del->lastName);
				free(del->firstName);
				free(del);
				return headStudentList;
			}
		}

		return NULL;
	}
