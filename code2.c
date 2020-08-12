#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// void pointers are generic so any datatype can be passed and returned
void* my_turn(){

    int *iptr = (int *)arg;

    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("my turn %d\n",i);
        (*iptr)++;
    }
}

void your_turn(){
   for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf("your turn %d\n",i);
    }
    
}

int main(){

    pthread_t newthread;
    int v=5;

    pthread_create(&newthread, NULL, my_turn, &v);
    // my_turn();
    your_turn();
    pthread_join(newthread, NULL); // didnt do &newthread as it was giving an error
    printf("threads are done: v=%d\n",v);
}