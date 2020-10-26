#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int pin = 0;
int cout = 0;
int lower = 0,high = 4;
int buffer[BufferSize];
pthread_mutex_t mutex;

//gcc prod-cons.c -pthread && ./a.out

void *Producer(void *pno){
    int item;
    for(int i=0;i<MaxItems;i++){
        item = lower + rand()%(high-lower+1);
        sem_wait(&empty);               //wait
        pthread_mutex_lock(&mutex);
        buffer[pin] = item;
        pin = (pin + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);                //signal
    }
}

void *Consumer(void *cno){
    for(int i=0;i<MaxItems;i++){
        sem_wait(&full);                //wait
        pthread_mutex_lock(&mutex);
        int item = buffer[cout];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, cout);
        cout = (cout + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);   
        sem_post(&empty);               //signal
    }
}

void main(){
    pthread_t producer[5],consumer[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5};
     //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&producer[i], NULL, (void *)Producer, (void *)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_create(&consumer[i], NULL, (void *)Consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(producer[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(consumer[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

}
