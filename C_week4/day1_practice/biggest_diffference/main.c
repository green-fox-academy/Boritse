#include <stdio.h>
#include <stdlib.h>

// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, the the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?

typedef struct{
  int amount_of_students;
  int* exam_results;
  char name_of_the_class[15];
}class_t;

int main()
{
    int amount_of_classes;
    printf("how many classes took the exam?\n");
    scanf("%d", &amount_of_classes);

    class_t* classes = (class_t*)calloc(amount_of_classes, sizeof(class_t));

    for(int i=0; i<amount_of_classes; i++) {
        printf("how many students took the exam in the %d. class?\n", i+1);
        scanf("%d", &classes[i].amount_of_students);
        classes[i].exam_results = (int*)calloc(classes[i].amount_of_students, sizeof(int));
        printf("whats the name of the %d. class?\n", i+1);
        scanf("%s", classes[i].name_of_the_class);
    }

    for(int i=0; i<amount_of_classes; i++){
        for(int j=0; j<classes[i].amount_of_students; j++){
            printf("whats the result in percentage of the %d. student of the %s class?\n", j+1, classes[i].name_of_the_class);
            scanf("%d", &classes[i].exam_results[j]);
        }
    }

    int differences[amount_of_classes-1];

    for(int i=0; i<amount_of_classes; i++){
        int best_result = 0;
        int worst_result = 100;
        for(int j=0; j<classes[i].amount_of_students; j++){
            if(classes[i].exam_results[j] > best_result){
                best_result = classes[i].exam_results[j];
            }
            if(classes[i].exam_results[j] < worst_result){
                worst_result = classes[i].exam_results[j];
            }
        }
        differences[i] = best_result - worst_result;
    }

    int biggest_difference = differences[0];
    int biggest_diff_ind = 0;

    for(int i=0; i<amount_of_classes; i++){
        if(biggest_difference < differences[i]){
            biggest_difference = differences[i];
            biggest_diff_ind = i;
        }
        free(classes[i].exam_results);
    }
    
    free(classes);

    printf("the class with the biggest difference is %s, the difference between the results is %d%\n", classes[biggest_diff_ind].name_of_the_class, biggest_difference);
    
    return 0;
}