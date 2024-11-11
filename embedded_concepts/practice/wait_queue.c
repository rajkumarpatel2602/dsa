/* https://www.udemy.com/course/multithreading-design-patterns/learn/lecture/27843880#overview */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

/**
 * Work queue
 * 
 * Helps to stop the therad execution until some
 * conditions meets.
 * Imagine waiting for IP address entry in routing
 * table, before sending the packet.
 * 
 * void wq_test_and_wait(workq_t , 
 *                          void (*cond_fun)(void *, pthread_mutex_t **),
 *                          void *args,
 *                          pthread_mutex_t **applock);
 * 
 * bool app_condition_check_fun(void *args, pthread_mutex_t **applock);
 */

pthread_mutex_t applock;
pthread_cond_t cv;
typedef bool(*condition_test_fun_t)(void *, pthread_mutex_t **);

typedef struct disk_struct {
    pthread_mutex_t dmutex;
    int shared_data;
    bool ready;
}disk_t;

typedef struct wait_queue {
    size_t waiting_threads;
    pthread_mutex_t *applock;
    pthread_cond_t cv;
} waitq_t;

waitq_t *wq;
disk_t disk;

bool app_condition_check_fun (void *args, pthread_mutex_t **lock) {
    disk_t *disk = args;

    // lock when test_and_wait ask check for condition.
    // checking condition means, it has come for testing
    // before using the shared resource or function call 
    if(lock) {
        pthread_mutex_lock(&disk->dmutex);
        *lock = &(disk->dmutex);
    }
    // in any case, return the status of disk
    return disk->ready; 
}

void wq_test_and_wait(waitq_t *wq, 
                        condition_test_fun_t cond_fun,
                        void *args) {
    pthread_mutex_t *app_lock;

    bool signal = cond_fun(args, &app_lock);

    wq->applock = app_lock;

    while(signal) {
        wq->waiting_threads++;
        pthread_cond_wait(&wq->cv, wq->applock);
        wq->waiting_threads--;
        signal = cond_fun(args, NULL);
    }
}

void app() {
    wq_test_and_wait(wq, app_condition_check_fun, &disk);
    disk.shared_data = 20;
    pthread_mutex_unlock(wq->applock);
}

void * myThreadFun(void *args) {
    printf("Thread %d enter\n", *(int *)args);
    app(); // executing app
    printf("Thread %d exit\n", *(int *)args);
}

void wq_init() {
    wq = (waitq_t *)malloc(sizeof(struct wait_queue));
    wq->waiting_threads = 0; // number of waiting threads
    pthread_cond_init(&wq->cv, NULL); // used for impose condition
    wq->applock = NULL; // it's used to hold the app lock
}

void wq_deinit() {
    wq->waiting_threads = 0; // mark threads as zero.
    pthread_cond_destroy(&wq->cv); // free cv
    pthread_mutex_destroy(wq->applock); // free mutex
}

void app_init() {
    disk.shared_data = 100;
    disk.ready = true;
    pthread_mutex_init(&(disk.dmutex), NULL);
}

void *mySignalingThread( void *args) {
    int i = 10;
    while(i--) {
        printf("signal is pending\n");
        sleep(2);
        pthread_mutex_lock(&(disk.dmutex));
        disk.ready = false;
        pthread_cond_signal(&wq->cv);
        pthread_mutex_unlock(&(disk.dmutex));
        printf("signaled ready\n");
    }
}

int main(int argc, char *args[]) {
    
    printf("program started\n");
    
    wq_init(wq);
    app_init();

    static int cnt[3] = {0, 1, 2};

    pthread_t th[4];
    for(int i = 0; i < 3; i++) {
        pthread_create(&th[i], NULL, myThreadFun, &cnt[i]);
    }
    
    pthread_create(&th[3], NULL, mySignalingThread, NULL);

    int j;
    for(j = 0; j < 3; j++) {
        pthread_join(th[j], NULL);
    }

    wq_deinit(&wq);

    printf("program ended\n");
}
