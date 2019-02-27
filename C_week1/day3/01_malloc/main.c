#include <stdlib.h>
#include <stdio.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits

int main()
{
    int size=10;
    int* arr=(int*)malloc(size*sizeof(int));
    int* other_arr=(int*)calloc(size, sizeof(int));

    for(int i=0; i<size; i++){
        if(i<size/2){
            arr[i]=i;
            other_arr[i]=i*size;
        }
        printf("malloc: %d in: %p    calloc: %d in: %p\n", arr[i], &arr[i], other_arr[i], &other_arr[i]);
    }

    free(arr);
    free(other_arr);

    return 0;
}