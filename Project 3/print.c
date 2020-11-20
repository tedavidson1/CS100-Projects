#include <stdio.h>

#include "permute.h"

int main(void)
{
    int array[4];
	printf("Enter 4 integers ranging from 1 through 10: ");
	for (int i=0; i<4; i++) scanf("%d", &array[i]);

	// Sort the 4 numbers in ascending order
    sortArray(4, array);

    do {
        printArray(4, array);
    }
    while (findNext(4, array)==1);

    return 0;
}
