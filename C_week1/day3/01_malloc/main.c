#include <stdlib.h>
#include <stdio.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits

int main()
{
    int* arr=(int*)malloc(10*sizeof(int));
    int* other_arr=(int*)calloc(10, sizeof(int));

    for(int i=0; i<10; i++){
        if(i<5){
            arr[i]=i;
            other_arr[i]=i*10;
        }
        printf("malloc: %d    calloc: %d\n", arr[i], other_arr[i]);
    }

    free(arr);
    free(other_arr);

    return 0;
}