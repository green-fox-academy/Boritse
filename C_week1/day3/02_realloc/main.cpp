#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* arr = (int*)malloc(10*sizeof(int));
    for(int i=0; i<10; i++){
        arr[i]=i*2;
        printf("%d. elem: %d\n", i+1, arr[i]);
    }

    realloc(arr, 0);

    return 0;
}