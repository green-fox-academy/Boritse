#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int size=10;
    int* even_arr;
    int* odd_arr;
    even_arr=(int*)malloc(size*sizeof(int));
    odd_arr=(int*)malloc(size*sizeof(int));
    int filling_number=1;
    for(int i=0; i<size; i++){
        even_arr[i]=filling_number+1;
        odd_arr[i]=filling_number;
        filling_number+=2;
    }

    int* all_arr=(int*)malloc(size*2*sizeof(int));
    for(int i=size*2-1; i>=0; i--){
        if(i%2==0){
            all_arr[i]=odd_arr[i/2];
        }else{
            all_arr[i]=even_arr[i/2];
        }
        printf("%d\n", all_arr[i]);
    }

    free(even_arr);
    free(odd_arr);

    return 0;
}