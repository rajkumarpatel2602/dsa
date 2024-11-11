#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THREAD_NUM 10
#define QUEUE_MAX 256

typedef struct Task {
    int a, b;
} Task;

typedef struct TaskNode {
    Task task;
    struct TaskNode *next;
} TaskNode;

typedef struct TaskQueue {
    TaskNode *head;
    TaskNode *tail;
    int size;
} TaskQueue;

int taskCount = 0;
TaskQueue *tq = NULL;
pthread_mutex_t mutexQueue;

void enqueue(Task t) {
    TaskNode *temp = (TaskNode *)malloc(sizeof(TaskNode));
    temp->task = t;
    temp->next = NULL;
    if(temp == NULL) {
        perror("can't be queued");
        return;
    }

    if(tq->size > QUEUE_MAX) {
        perror("Queue is already full");
    } 

    if(tq->head == NULL) {
        tq->head = temp;        
    } else {
        tq->tail->next = temp;
    }
    tq->tail = temp;
    tq->size++;
}

Task dequeue() {
    TaskNode *temp;
    Task ret = {
        .a = -1,
        .b = -1
    };
    
    if(tq->size == 0) {
        perror("Queue is empty!");
        return ret;
    }

    temp = tq->head;
    ret = tq->head->task;
    tq->head = tq->head->next;
    free(temp);
    return ret; 
}

void initTaskQueue() {
    
    tq = (TaskQueue *)malloc(sizeof(TaskQueue));
    if(tq == NULL) {
        perror("failed to alloc task queue.");
        return;
    }
    
    tq->head = NULL;
    tq->tail = NULL;
    tq->size = 0;

    return;
}

void executeTask(Task task) {
    int result = task.a + task.b;
    printf("sum of %d and %d is : %d\n", task.a, task.b, result);
}

// submit tasks
void submitTask(Task task) {
    pthread_mutex_lock(&mutexQueue);
    if(tq->size < QUEUE_MAX) {
        enqueue(task);
    }
    pthread_mutex_unlock(&mutexQueue);
}

// execute thread
void *startThread(void *args){
    while(1) {
        Task task;
        pthread_mutex_lock(&mutexQueue);
        task = dequeue();
        pthread_mutex_unlock(&mutexQueue);

        // execute the submitted task
        if(task.a != -1) {
            executeTask(task);
        }
    }
}

// main thrad
int main(int argc, char *args[]) {    
    int i = 0;
    pthread_mutex_init(&mutexQueue, NULL);

    // init task queue 
    initTaskQueue();

    // submit tasks
    srand(time(NULL));
    for (i = 0; i < QUEUE_MAX; i++) {
        Task t = {
            .a = rand() % 100,
            .b = rand() % 100
        };
        submitTask(t);
    }

    // create thread pool
    pthread_t th[THREAD_NUM];
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&th[i], NULL, &startThread, tq)) {
            perror("Failed to create thread");
        }
    }

    // wait for threads to join
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(&th[i], NULL)) {
            perror("Failed to join the thread");          
        }
    }
}
