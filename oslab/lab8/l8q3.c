#include <pthread.h>
#include <stdio.h>
 
typedef struct {
    int start;
    int end;
} ThreadArgs;

int isPrime(int n) {
    if (n == 1 || n == 0)
        return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
 
void* child_thread(void * arg) {
   ThreadArgs* args = (ThreadArgs*)arg;
    for (int i = args->start; i<args->end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
 
int main() {
    pthread_t thread;
    ThreadArgs args;
    int st,en;
    printf("Enter start and end: ");
    scanf("%d %d", &st, &en);
    args.start=st;
    args.end=en;
    pthread_create(&thread, NULL, &child_thread, &args);
    pthread_join(thread, 0);
}