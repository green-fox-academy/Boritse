#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int size=10;
    int* arr = (int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        arr[i]=i*2;
        printf("%d. elem: %d\n", i+1, arr[i]);
    }

    realloc(arr, 0);

    return 0;
}