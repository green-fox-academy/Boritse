#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{
  BIG, //(>= 15 cm)
  MEDIUM, // (>= 12 cm)
  SMALL // (< 12 cm)
}screen_size_t;

typedef struct{
  char name[256];
  int released_in;
  screen_size_t type;
  int price;
}smartphone_t;

char* get_oldest_phone(smartphone_t *phones, int counter){
    int oldest=phones[0].released_in;
    int oldest_index=0;
    for(int i=0; i<counter; i++){
        if(oldest>phones[i].released_in){
            oldest=phones[i].released_in;
            oldest_index=i;
        }
    }
    return phones[oldest_index].name;
}
int get_screen_size_count(smartphone_t *phones, screen_size_t type, int amount)
{
    int counter=0;
    for(int i=0; i<amount; i++){
        if(phones[i].type==type)
            counter++;
    }
    return counter;
}

int main()
{
    smartphone_t phones[100];
    int counter=0;

    FILE * working_file = fopen("phones.txt", "r");
    char line[256];
    while(!feof(working_file)){
        fgets(line, sizeof(line), working_file);
        char *data = strtok(line, " ");
        strcpy(phones[counter].name, data);
        data=strtok(NULL, " ");
        phones[counter].released_in = atoi(data);
        data=strtok(NULL, " ");
        int size=atoi(data);
        if(size>=15){
            phones[counter].type=BIG;
        }else if(size<12){
            phones[counter].type=SMALL;
        }else{
            phones[counter].type=MEDIUM;
        }
        counter++;
    }
    fclose(working_file);

    printf("the oldest phone is: %s\n", get_oldest_phone(phones, counter));
    printf("we have %d phones which are MEDIUM size\n", get_screen_size_count(phones, MEDIUM, counter));

    working_file = fopen("prices.txt", "w");
    for(int i=0; i<counter; i++){
        if(phones[i].type==BIG){
            phones[i].price=600;
        }else if(phones[i].type==MEDIUM){
            phones[i].price=400;
        }else{
            phones[i].price=300;
        }
        fprintf(working_file, "<%s> <%d>\n", phones[i].name, phones[i].price);
    }
    fclose(working_file);

    return 0;
}