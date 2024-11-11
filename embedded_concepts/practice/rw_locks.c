#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

pthread_rwlock_t rwl;
pthread_mutex_t lock;
volatile int r_cnt = 0;
volatile int w_cnt = 0;

void inc_reader(){
    pthread_mutex_lock(&lock);
    r_cnt++;    
    pthread_mutex_unlock(&lock);
}

void inc_writer() {
    w_cnt++;    
}

void dec_reader(){
    pthread_mutex_lock(&lock);
    r_cnt--;    
    pthread_mutex_unlock(&lock);
}

void dec_writer(){
    w_cnt--;    
}

void shared_resources() {
    pthread_mutex_lock(&lock);
    printf("rd = %d, wr = %d\n", r_cnt, w_cnt);
    pthread_mutex_unlock(&lock);
}

void *readerThreads(void *args) {
    while(1) {
        pthread_rwlock_rdlock(&rwl);
        inc_reader();
        shared_resources();
        dec_reader();
        pthread_rwlock_unlock(&rwl);
    }
}

void *writerThreads(void *args) {

    while(1) {
        pthread_rwlock_wrlock(&rwl); /* no protection needed for writer. */
        inc_writer();
        shared_resources();
        dec_writer();
        pthread_rwlock_unlock(&rwl);
    }
}


int main(int argc, char *args[]) {
    
    printf("Read write lock program started\n");
    
    pthread_rwlock_init(&rwl, NULL);
    pthread_mutex_init(&lock, NULL);

    pthread_t th[6];

    for(int i = 0; i < 3; i++) {
        pthread_create(&th[i], NULL, readerThreads, NULL);
        pthread_create(&th[i+3], NULL, writerThreads, NULL);
    }

    for(int j = 0; j < 6; j++) {
        pthread_join(th[j], NULL);
    }

    pthread_rwlock_destroy(&rwl);
    pthread_mutex_destroy(&lock);

    printf("program ended\n");
}
