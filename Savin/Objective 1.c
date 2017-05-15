#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct data{
	
	char string[255];
	char element[255];
	int elem;
	int type;
	int columns;
	int lines;
	int **matrix;
	
} data;


void finding(struct data *t);



int main() {
	
	int i, j;
	
	
	/* Communication with the user */

	printf("Which type data you want enter? \n");
	printf("1. String \n2. Number \n\n");
	scanf("%d", &data.type);
	printf("\n");

	switch (data.type) {
		
		
		/* If type will be string */
		
		case 1:
			
			printf("Enter the initial string: \n\n");
			getchar();
			gets(data.string);
			printf("\n");
			
			
			/* Error initial string */
			
			if (strlen(data.string) == 0) {
				printf("There are no items in the source line!");
			}
			
			
			else {
				
				printf("Which element you want find? \n\n");
				gets(data.element);
				printf("\n");
			
				finding(&data);

			}
						
			break;
		
		
		/* If type will be numbers */
		
		case 2:
			
			printf("How many lines in the matrix? \n\n");
			scanf("%d", &data.lines);
			printf("\n");
			
			printf("How many columns in the matrix? \n\n");
			scanf("%d", &data.columns);
			
			
			/* Checking errors */
			
			if ((data.lines > 0) && (data.columns > 0)) {
				
				
				/* Memory allocation */
			
				data.matrix = (int**) malloc(data.lines * sizeof(int*));
				for (i = 0; i < data.lines; i++) {
					data.matrix[i] = (int *) malloc(data.columns * sizeof(int));
				}
			
			
				/* Filling of array */
				
				srand(time(0));
				printf("\nRandom matrix: \n\n");
				for (i = 0; i < data.lines; i++) {
					
					for (j = 0; j < data.columns; j++) {
						
						*(*(data.matrix + i) + j) = 1 + rand() % 100;
						
						
						/* Output random elements */
						
						if (data.lines > 1) {
							printf("matrix[%d][%d] = %d \t", i + 1, j + 1, data.matrix[i][j]);
						}
						
						else {
							printf("array[%d] = %d \t", j + 1, data.matrix[i][j]);
						}
						
						
					}
					
					printf("\n");
				}
		
		
			}
			
			else {
				printf("\nINPUT ERROR!\n");
			}
			
			printf("\nWhich element you want find? \n\n");
			scanf("%d", &data.elem);
			
			finding(&data);
			
			
			/* Cleaning memory */
			
			for (i = 0; i < data.lines; i++) {
				
				free(data.matrix[i]);
			}
			free(data.matrix);
			
			
			break;
			
		
		/* Error of type */
		
		default:
			
			printf("Wrong type of data!");
			break;
			
			
	}



	return 0;
}



void finding(struct data *t) {

	int i = 0, j, num = 1;


	/* If initial data will be string */

	if (t->type == 1) {
			
			
			/* Input line ñycle */

			while (t->string[i] != '\0') {


				/* Element line cycle */
		
				j = 0;
				while (1) {
	
					if (t->string[i + j] != t->element[j]) {
						break;
					}
		
					if (t->element[j + 1] == '\0') {
		
						if (j > 0) {
		
							printf("%d. element [%d-%d]\n", num, i, i + j);
							num++;
						}
		
						else {
		
							printf("%d. element [%d]\n", num, i);
							num++;
						}
		
					break;
		
				}
		
				j++;
		
			}
		
		
			i++;
		
		}
		
		if (num == 1) {
			printf("This element doesn't exist. \n");
		}
			
					
	}
	
	
	/* If initial data will be numbers */
	
	else {
		
		
		/* Finding */
		
		for (i = 0; i < t->lines; i++) {
			
			for (j = 0; j < t->columns; j++) {
				
				if (t->elem ==  *(*(t->matrix + i) + j)) {
					
					
					/* Output elements */
					
					if (t->lines > 1) {
						
						printf("\n%d. matrix[%d][%d] = %d", num, i + 1, j + 1, t->matrix[i][j]);
						num++;
					}
					
					else {
						
						printf("\n%d. array[%d] = %d", num, j + 1, t->matrix[i][j]);
						num++;
					}
					
					
				}
				
			}
			
		}
		
		
		if (num == 1) {
			printf("\nThis element doesn't exist. \n");
		}
		
	}


}



