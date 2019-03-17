#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[50];
  int *members;
} class_t;

int *biggest_difference(class_t **classes, int number_of_classes, int *size_of_classes){
    int local_diff[number_of_classes];
    int local_min=classes[0]->members[0];
    int local_max=classes[0]->members[0];

    for(int i=0; i<number_of_classes; i++){
        for(int j=0; j<size_of_classes[i]; j++){
            if(classes[i]->members[j]>local_max) {
                local_max = classes[i]->members[j];
            }else if(classes[i]->members[j]<local_min) {
                local_min = classes[i]->members[j];
            }
        }
        local_diff[i]=local_max-local_min;
    }

    int biggest_difference=local_diff[0];
    int index_of_biggest_difference_class=0;

    for(int i=0; i<number_of_classes; i++){
        if(biggest_difference<local_diff[i]){
            biggest_difference=local_diff[i];
            index_of_biggest_difference_class=i;
        }
    }
    int answer[2];
    answer[0]=biggest_difference;
    answer[1]=index_of_biggest_difference_class;
    int *biggi=answer;
    return biggi;
}

char* best_exam(class_t **classes, int number_of_classes, int *size_of_classes){
    int best_result=0;
    int class_best_result_index=0;
    for(int i=0; i<number_of_classes; i++){
        for(int j=0; j<size_of_classes[i]; j++){
            if(classes[i]->members[j]>best_result){
                best_result=classes[i]->members[j];
                class_best_result_index=i;
            }
        }
    }
    return classes[class_best_result_index]->name;
}

int main()
{
    int number_of_classes;
    class_t **classes;
    printf("how many classes will you have?\n");
    scanf("%d", &number_of_classes);
    classes = (class_t**)malloc(number_of_classes*sizeof(class_t*));
    int size_of_the_classes[number_of_classes];
    for(int i=0; i<number_of_classes; i++){
        printf("how many students are there in the %d. class?\n", i+1);
        scanf("%d", &size_of_the_classes[i]);
    }
    for(int i=0; i<number_of_classes; i++){
        classes[i]=(class_t*)malloc(size_of_the_classes[i]*sizeof(int)+sizeof(class_t));
    }
    for(int i=0; i<number_of_classes; i++){
        printf("what's the name of the %d. class?\n", i+1);
        scanf("%s", classes[i]->name);
        for(int j=0; j<size_of_the_classes[i]; j++){
            printf("what's the result of the %d. student of the %d. class?\n", j+1, i+1);
            scanf("%d", &classes[i]->members[j]);
        }
    }

    for(int i=0; i<number_of_classes; i++){
            free(classes[i]);
        }

    printf("the class with the best exam result is: %s\n", best_exam(classes, number_of_classes, size_of_the_classes));

    int *biggest_differenc;
    biggest_differenc=biggest_difference(classes, number_of_classes, size_of_the_classes);

    printf("the %s class has the biggest difference, exactly %d percent\n", classes[biggest_differenc[1]]->name, biggest_differenc[0]);

    free(classes);

    return 0;
}
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// What is the average of all the exams?