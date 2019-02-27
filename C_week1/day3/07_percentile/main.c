#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

/*int percentile_counter(int** arr, int percent_needed, int rows, int* length_of_rows){
    int element_counter=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<length_of_rows[i]; j++){
            element_counter++;
        }
    }
    int* numbers_in_order = (int*)calloc(element_counter, sizeof(int));
    int next_smallest_element=arr[0][0];
    for(int k=0; k<element_counter; k++){
        for(int i=0; i<rows; i++) {
            for (int j = 0; j < length_of_rows[i]; j++) {
                if(next_smallest_element>arr[i][j]){
                    next_smallest_element=arr[i][j];
                }
            }
        }
        numbers_in_order[k]=next_smallest_element;
    }
}
*/
int main()
{
    int** matrix;
    int rows;
    printf("how many rows will your matrix have?");
    scanf("%d", &rows);
    matrix = (int**)calloc(rows, sizeof(int*));
    int length_of_rows[rows];
    for (int i=0; i<rows; i++){
        printf("how many numbers will be in the %d. row?", i+1);
        scanf("%d", &length_of_rows[i]);
    }
    for(int i=0; i<rows; i++){
        matrix[i]=(int*)calloc(length_of_rows[i], sizeof(int));
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<length_of_rows[i]; j++){
            printf("please give me the %d. number of the %d. row", j+1, i+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<length_of_rows[i]; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);

    return 0;
}