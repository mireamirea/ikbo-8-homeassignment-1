#include <stdio.h>

int main (int argc, char *argv[])
{
	int a[3][3] = {{0, 1, 15}, {2, 15, 3}, {3, 15, 15}};
	int b[9] = {1, 55, 23, 27, 4427, 27, 88, 19, 1995};
	int el;
	int arrLength;;

	printf("Looking for a number in a matrix...\n");
	el = 15;
	arrLength = sizeof(a)/sizeof(int);
	FindInArray(a, el, arrLength);

	printf("Looking for a number in a 1-dimensional array...\n");
    el = 27;
	arrLength = sizeof(b)/sizeof(int);
	FindInArray(b, el, arrLength);
	return 0;
}

void FindInArray(int* arr, int elementToFind, int arrLength){
    printf("Array length: %d\nElement to find: %d\n", arrLength, elementToFind);
    int i, curElem;
    for (i = 0; i < arrLength; i++){
        curElem = *(arr+i);
        if (elementToFind == curElem){
            printf("a[%d] = %d\n", i, elementToFind);
        }
    }
    printf("Search complete.\n\n");
}

