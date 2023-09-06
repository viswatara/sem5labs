#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
} ThreadArgs;

void* child_thread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    args->array[0] = 0;
    args->array[1] = 1;

    for (int i = 2; i <= args->size; i++) {
        args->array[i] = args->array[i-1]+args->array[i-2];
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
    args.array=temp;
    args.size=n;
    pthread_create(&thread, NULL, &child_thread, &args);
    pthread_join(thread, NULL);
    for(int i=0;i<n;i++) {
      printf("%d ", args.array[i]);	
    }
    return 0;
}
