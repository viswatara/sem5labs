#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
    int evensum, oddsum;
} ThreadArgs;

int isOdd(int n) {
    if (n%2==0)
        return 0;
    return 1;
}
 
void* evensum(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    args->evensum = 0;
    for (int i = 0; i < args->size; i++) {
       if(isOdd(args->array[i])==0){
        args->evensum+=args->array[i];
       }
    }
    return NULL;
}

void* oddsum(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    args->oddsum = 0;
    for (int i = 0; i < args->size; i++) {
       if(isOdd(args->array[i])){
        args->oddsum+=args->array[i];
       }
    }
    return NULL;
}

int main() {
    pthread_t thread;
    ThreadArgs args;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int temp[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
    }
    args.array = temp;
    args.size=n;
    pthread_create(&thread, NULL, &evensum, &args);
    pthread_create(&thread, NULL, &oddsum, &args);
    pthread_join(thread, NULL);
    printf("Sum of odd elements: %d\n", args.oddsum);
    printf("Sum of even elements: %d\n", args.evensum);
    return 0;
}
