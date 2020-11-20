/*Thomas Davidson
This project reads in a PGM image and stores its data into a struct
If the user encodes, I modify the last bit of each pixel in the struct
and then have it make a new image with the modified pixels. Decode
reads the last bit of each pixel and deciphers the hidden message inside.*/
#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Given a filename of a pgm image, read in the image and
// store it in the ImagePGM structure. Return the address of
// the ImagePGM structure if the file can be opened or
// NULL otherwise.
ImagePGM *readPGM(char *filename) //complete
{
FILE *fp = fopen(filename, "r");
ImagePGM *Image = malloc(sizeof(ImagePGM));

if (fp == NULL){
	return NULL;
}

fscanf(fp,"%s",Image->magic);
if (strcmp(Image->magic,"P2") != 0){
  return NULL;
}

  fscanf(fp, "%d", &Image->width); //acquires width (numCols)
  fscanf(fp, "%d", &Image->height); //acquires height (numRows)
  fscanf(fp, "%d", &Image->max_value); //acquires max intensity

	Image->pixels = malloc(Image->height * sizeof(int*)); //creation of 2D Array
	for (int i = 0; i < Image->height; i++){
		Image->pixels[i] = malloc(Image->width * sizeof(int));
  }

  for (int i = 0; i < Image->height; i++){ //storing values
    for (int j = 0; j < Image->width; j++){
      fscanf(fp, "%d", &Image->pixels[i][j]);
    }
  }
  return Image;
}

// Write out a pgm image stored in a ImagePGM structure into
// the specified file. Return 1 if the file can be opened or
// 0 otherwise.
int writePGM(ImagePGM *pImagePGM, char *filename)
{
  FILE *fp = fopen(filename, "w"); //check with professor, isn't writing at all when like this, work with w

  	if (fp == NULL){
		return 0;
	}

  fprintf(fp,"%s\n",pImagePGM->magic);

    fprintf(fp, "%d ", pImagePGM->width); //prints width (numCols)
    fprintf(fp, "%d ", pImagePGM->height); //prints height (numRows)
    fprintf(fp, "%d", pImagePGM->max_value); //prints max intensity
    fprintf(fp, "\n");

    for (int i = 0; i < pImagePGM->height; i++){ //printing values
      for (int j = 0; j < pImagePGM->width; j++){
        fprintf(fp, "%d ", pImagePGM->pixels[i][j]);
      }
      fprintf(fp, "\n");
    }
    return 1;
  }

	void makeBinary(int number, int array[])
	{
	  for (int i = 7; i >= 0; i--){
	    array[i] = number % 2;
	    number = number / 2;
	  }
	}

// Encode/embed a message into a PGM image.
// Return 0 if the image is too small or
// 1 otherwise.
int encode(ImagePGM *pImagePGM, char *msg)
{
//checking if the message will fit or not
  int imageSize = (pImagePGM->height) * (pImagePGM->width);
	int messageSize = (strlen(msg) + 1) * 8;

	if (messageSize > imageSize){
		return 0;
	}

//encoding the message
int numRows = pImagePGM->height - 1;
int numCols = pImagePGM->width - 1;
int pixelCount = 0; //counts how many pixels we've traversed
int binaryRep[8]; //storage array for binary
int letterValue = msg[0]; //starting number is the first letter
makeBinary(letterValue, binaryRep);

for (int i = numRows; i >= 0; i--){ //moving backwards
	for (int j = numCols; j >= 0; j--){ //through the array

		if (pixelCount == messageSize){
			return 1;
		}

		if ((pixelCount != 0) && (pixelCount % 8) == 0){
		letterValue = msg[pixelCount / 8];
		makeBinary(letterValue, binaryRep);
		}

		pImagePGM->pixels[i][j] = ((pImagePGM->pixels[i][j] / 2) * 2) + binaryRep[pixelCount % 8];
			pixelCount++;

		}
	}
return 1;
}
char convertToChar(int array[]) //make return a letter for array later
{
	char letter;
/*printf("Values: ");
for (int i = 0; i < 8; i++){
	printf("%d ", array[i]);
}*/
	int converted = 0;
	int j = 7;
	for (int i = 0; i < 8; i++){
	  if (array[i] == 1){
	    converted = converted + pow(2, j);
	  }
		j--;
	}
	//printf("\n");
//printf("%d -", converted);
if (converted == 0){
 letter = '\0';
}
else{
	letter = converted;
}
//printf("%c\n", letter);
return letter;
}

// Decode/extract and return the message embedded in a PGM image
char *decode(ImagePGM *pImagePGM)
{
	int numRows = pImagePGM->height - 1;
	int numCols = pImagePGM->width - 1;

	int storageArray[8] = {0}; //array to hold binary values
	int maxMessageSize = (pImagePGM->height * pImagePGM->width) / 8; //message can only be as large space
	char *messagePointer = (char*)malloc(sizeof(char)*maxMessageSize);//message
	int mainCount = 0; //how many numbers we have been through
	int letterCount = 0; //how many letters we have added

for (int i = numRows; i >= 0; i--){ //go through array backwards
	for (int j = numCols; j >= 0; j--){
		int value = pImagePGM->pixels[i][j]; //the pixel value

if (mainCount != 0 && (mainCount % 8) == 0){
	messagePointer[letterCount] = convertToChar(storageArray);
	if (messagePointer[letterCount] == '\0'){
		return messagePointer; //will free in the free function
	}
letterCount++;
}
		if ((value % 2) == 1){
			storageArray[mainCount % 8] = 1;
		}

		else{
			storageArray[mainCount % 8] = 0;
		}

		mainCount++;
	}
}//end of first for loop
return messagePointer;
}

// Free the space used by a pgm image.
void freePGM(ImagePGM *pImagePGM)
{
	for (int i = 0; i < pImagePGM->height; i++){
		free(pImagePGM->pixels[i]);
	}
	free(pImagePGM->pixels);
}
