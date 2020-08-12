#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* my_turn(){
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("my turn %d\n",i);
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

    pthread_create(&newthread, NULL, my_turn, NULL);
    // my_turn();
    your_turn();
    pthread_join(newthread, NULL); // didnt do &newthread as it was giving an error
}