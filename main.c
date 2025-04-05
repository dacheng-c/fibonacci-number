#include <stdio.h>
#include <pthread.h>

// recursive fibonacci number
unsigned long long fib1(int n) {
    if (n <= 1)
        return n;
    return fib1(n - 1) + fib1(n - 2);
}

// iterative fibonacci number
unsigned long long fib2(int n) {
    if (n <= 1)
        return n;

    unsigned long long a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return b;
}

#define MAX 40

void* fib1_thread(void* arg) {
    for (int i = 0; i < MAX; i++) {
        printf("fib1(%d) => %llu\n", i, fib1(i));
    }
    return NULL;
}

void* fib2_thread(void* arg) {
    for (int i = 0; i < MAX; i++) {
        printf("fib2(%d) => %llu\n", i, fib2(i));
    }
    return NULL;
}

int
main(void) {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, fib1_thread, NULL);
    pthread_create(&thread2, NULL, fib2_thread, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
