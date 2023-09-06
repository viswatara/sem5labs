#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int sum,size;
} ThreadArgs;

void* child_thread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    args->sum = 0;
    for (int i = 0; i < args->size; i++) {
        if(args->array[i]>0) {
            args->sum += args->array[i];
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
    pthread_create(&thread, NULL, &child_thread, &args);
    pthread_join(thread, NULL);
    printf("Sum of the entered elements: %d\n", args.sum);
    return 0;
}
