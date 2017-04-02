/*  
 main.c
 findstring

 Created by Денис Скоробогатов on 28.02.17.
 Copyright © 2017 Denis Skorobogatov. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 255

void readline(char **input, int size)
{
    char *_input = malloc(size * sizeof(char));
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (i < size)
        {
            _input[i] = c;
            i++;
        }
    }
    *input = _input;
}

int readsearch(char **input)
{
    char *_input = malloc(sizeof(char));
    char c;
    int i = 0;
    while((c = getchar()) != '\n')
    {
        if (i < MAXLENGTH)
        {
            _input[i] = c;
            i++;
        }
    }
    *input = _input;
    return i;
}

void matrix(char ***input, int *row, int *column)
{
    int i;
    char **_input;
    printf("Number of rows: ");
    scanf("%d", row);
    printf("Number of columns: ");
    scanf("%d", column);
    _input = malloc(*row * sizeof(char*));
    getchar(); /* fucked up right here */
    for (i = 0; i < *row; i++)
    {
        readline(&_input[i], *column);
    }
    *input = _input;
}

void searchelemets(char **matrix, char *searcharray, int searchsize, int row, int column, int **searchresults)
{
    int i = 0, j = 0, k = 0;
    char *string = calloc(row * column, sizeof(char));
    int *z = calloc(row * column, sizeof(int));
    for (i = 0; i < row; i++) /* we form a char array out of the matrix */
    {
        for (j = 0; j < column; j++)
        {
            string[k] = matrix[i][j];
            k++;
        }
    }
    k = 0;
    for (i = 0; i < row * column; i++)
    {
        if (string[i] == searcharray[k])
        {
            k++;
            z[i] += 1;
            for (j = i + 1; j < row * column; j++)
            {
                if (string[j] == searcharray[k])
                {
                    z[i] += 1;
                    k++;
                } else {
                    k = 0;
                    break;
                }
            }
        }
    }
    *searchresults = z;
    free(string);
}

int main(int argc, const char * argv[]) {
    char **thematrix;
    char *searcharray;
    int *searchresults;
    int searchsize;
    int matrixsize;
    int i, k = 0;
    int row, column;
    printf("Enter the matrix. If u wish to enter a string - set number of rows to 1\n");
    matrix(&thematrix, &row, &column);
    matrixsize = row * column;
    printf("Enter search array\n");
    searchsize = readsearch(&searcharray);
    searchelemets(thematrix, searcharray, searchsize, row, column, &searchresults);
    for (i = 0; i < matrixsize; i++)
    {
        if (searchresults[i] == searchsize)
        {
            printf("An array number %d is positioned in: %d;%d\n", k + 1, i / column, i % column);
            k++;
        }
    }
    printf("%d arrays found\n", k);
    free(searchresults);
    for (i = 0; i < row; i++)
        free(thematrix[i]);
    free(thematrix);
    return 0;
}
