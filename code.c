// using posix threads

// pthreads

// int pthread_create(pthread_t *thread, 
// const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)

// 3rd arg => pass a pointer to the function that we wanna run

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* my_turn(){
    while (1)
    {
        sleep(1);
        printf("my turn\n");
    }
    
}

void your_turn(){
    while (1)
    {
        sleep(1);
        printf("your turn\n");
    }
    
}

int main(){

    pthread_t newthread;

    pthread_create(&newthread, NULL, my_turn, NULL);
    // my_turn();
    your_turn();
}