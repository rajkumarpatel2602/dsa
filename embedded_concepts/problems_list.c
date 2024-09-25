/*
Chat GPT prompt:
#1 (1st 20 qna)
I loved these explanation. You are smart. See, as you come up with this solution, can you come up with such programs where user application can use hardware or kernel resources in some ways? This are actual real life embedded system problems which embedded engineers are expected to well versed about. Give me such problems for my embedded coding interviews which uses concept of scheduling, deadlock scenario, race conditions, data structures, etc. Give me list of 20 such famous problems and what kind of embedded concepts are used in it, and then provide comprehensive solution for each, after providing list.

#2 (2nd 20 qna)
I liked this list very much, but can you please provide 20 more such questions, but consider to ignore peripheral protocol related problems, and more to include very low level problems which includes deep OS concepts like scheduling, cache etc
*/

/*
1. Blinking LED with Timer Interrupts
Concepts: Timer interrupts, GPIO control

Problem: Implement a program that blinks an LED at a fixed interval using a hardware timer interrupt.
*/

#include <stdint.h>
#include <stdbool.h>

#define LED_PIN 13

void TimerISR(void) {
    static bool led_state = false;
    led_state = !led_state;
    if (led_state) {
        // Turn on LED
        GPIO_SetPin(LED_PIN);
    } else {
        // Turn off LED
        GPIO_ClearPin(LED_PIN);
    }
}

void InitHardwareTimer(void) {
    // Configure the hardware timer to generate an interrupt every 500 milliseconds
    // This is platform-specific and depends on the microcontroller being used
}

int main(void) {
    InitHardwareTimer();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
2. UART Communication with Circular Buffer
Concepts: UART, circular buffer, interrupt handling

Problem: Implement UART communication using a circular buffer to handle incoming and outgoing data.
*/

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} CircularBuffer;

CircularBuffer tx_buffer;
CircularBuffer rx_buffer;

void UART_ISR(void) {
    if (UART_ReceiveInterruptFlag()) {
        uint8_t data = UART_Read();
        rx_buffer.buffer[rx_buffer.head] = data;
        rx_buffer.head = (rx_buffer.head + 1) % BUFFER_SIZE;
    }
    if (UART_TransmitInterruptFlag()) {
        if (tx_buffer.head != tx_buffer.tail) {
            UART_Write(tx_buffer.buffer[tx_buffer.tail]);
            tx_buffer.tail = (tx_buffer.tail + 1) % BUFFER_SIZE;
        }```c
        }
    }
}

void UART_Send(uint8_t data) {
    tx_buffer.buffer[tx_buffer.head] = data;
    tx_buffer.head = (tx_buffer.head + 1) % BUFFER_SIZE;
    UART_EnableTransmitInterrupt();
}

uint8_t UART_Receive(void) {
    uint8_t data = rx_buffer.buffer[rx_buffer.tail];
    rx_buffer.tail = (rx_buffer.tail + 1) % BUFFER_SIZE;
    return data;
}

void InitUART(void) {
    // Initialize UART hardware and enable interrupts
}

int main(void) {
    InitUART();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
3. Task Scheduling with Round-Robin Algorithm
Concepts: Task scheduling, round-robin algorithm, context switching

Problem: Implement a simple round-robin scheduler to manage multiple tasks.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
} Task;

Task tasks[MAX_TASKS];
uint8_t current_task = 0;

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task == NULL) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}

  
  /*
4. Priority Inversion in Real-Time Systems
Concepts: Priority inversion, real-time scheduling, mutex

Problem: Implement a solution to handle priority inversion using priority inheritance.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t resource_mutex;
int resource;

void LowPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource++;
    pthread_mutex_unlock(&resource_mutex);
}

void MediumPriorityTask(void) {
    // Perform some work
}

void HighPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource--;
    pthread_mutex_unlock(&resource_mutex);
}

int main(void) {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&resource_mutex, &attr);

    // Create and start tasks
    pthread_create(&low_priority_thread, NULL, LowPriorityTask, NULL);
    pthread_create(&medium_priority_thread, NULL, MediumPriorityTask, NULL);
    pthread_create(&high_priority_thread, NULL, HighPriorityTask, NULL);

    while (1) {
        // Main loop
    }
    return 0;
}

/*
5. Producer-Consumer Problem with Semaphores
Concepts: Semaphores, synchronization, shared resources

Problem: Implement the producer-consumer problem using semaphores to synchronize access to a shared buffer.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t buffer_mutex;

void *Producer(void *arg) {
    while (1) {
        int item = ProduceItem();
        sem_wait(&empty);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full);
    }
}

void *Consumer(void *arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_mutex);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
       ```c
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty);
        ConsumeItem(item);
    }
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buffer_mutex, NULL);

    pthread_create(&producer_thread, NULL, Producer, NULL);
    pthread_create(&consumer_thread, NULL, Consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

/*
6. Deadlock Detection and Avoidance
Concepts: Deadlock detection, resource allocation graph, avoidance algorithms

Problem: Implement a system to detect and avoid deadlocks using the Banker's algorithm.
 */
#include <stdbool.h>
#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES] = {3, 3, 2};
int maximum[NUM_PROCESSES][NUM_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[NUM_PROCESSES][NUM_RESOURCES];

void CalculateNeed() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool IsSafe() {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

bool RequestResources(int process_id, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > need[process_id][i]) {
            return false;
        }
        if (request[i] > available[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }

    if (IsSafe()) {
        return true;
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        return false;
    }
}

int main(void) {
    CalculateNeed();

    int request1[] = {1, 0, 2};
    if (RequestResources(1, request1)) {
        printf("Request granted.\n");
    } else {
        printf("Request denied.\n");
    }

    return 0;
}

/*
7. Race Condition in Shared Memory Access
Concepts: Race condition, critical section, mutex

Problem: Implement a solution to prevent race conditions when accessing shared memory.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

```c
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t data_mutex;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data++;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data--;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&data_mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&data_mutex);
    return 0;
}

/*
8. Implementing a Software Watchdog Timer
Concepts: Watchdog timer, system reliability, timer interrupts

Problem: Implement a software watchdog timer that resets the system if the main loop becomes unresponsive.
 */
#include <stdint.h>
#include <stdbool.h>

volatile bool watchdog_reset = false;

void WatchdogISR(void) {
    if (!watchdog_reset) {
        // Reset the system
        SystemReset();
    }
    watchdog_reset = false;
}

void InitWatchdogTimer(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

void ResetWatchdog(void) {
    watchdog_reset = true;
}

int main(void) {
    InitWatchdogTimer();
    while (1) {
        // Main loop
        ResetWatchdog();
    }
    return 0;
}

/*
9. Memory Management with Dynamic Allocation
Concepts: Dynamic memory allocation, fragmentation, memory pools

Problem: Implement a memory pool allocator to manage dynamic memory allocation efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

uint8_t memory_pool[POOL_SIZE];
bool block_used[POOL_SIZE / BLOCK_SIZE];

void *AllocateBlock(void) {
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        if (!block_used[i]) {
            block_used[i] = true;
            return &memory_pool[i * BLOCK_SIZE];
        }
    }
    return NULL; // No available blocks
}

void FreeBlock(void *block) {
    int index = ((uint8_t *)block - memory_pool) / BLOCK_SIZE;
    block_used[index] = false;
}

int main(void) {
    void *block1 = AllocateBlock();
    void *block2 = AllocateBlock();
    FreeBlock(block1);
    void *block3 = AllocateBlock();
    return 0;
}

/*
10. Inter-Process Communication with Message Queues
Concepts: IPC, message queues, synchronization

Problem: Implement inter-process communication using message queues to exchange data between tasks.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <mqueue.h>

#define QUEUE_NAME "/message_queue"
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256

mqd_t mq;

void *SenderTask(void *arg) {
    char message[MAX_MESSAGE_SIZE] = "Hello, World!";
    while (1) {
        mq_send(mq, message, sizeof(message), 0);
        sleep(1);
    }
    return NULL;
}

void *ReceiverTask(void *arg) {
    char message[MAX_MESSAGE_SIZE];
    while (1) {
        mq_receive(mq, message, sizeof(message), NULL);
        printf("Received message: %s\n", message);
    }
    return NULL;
}

int main(void) {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MESSAGE_SIZE;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

    pthread_t sender_thread, receiver_thread;
    pthread_create(&sender_thread, NULL, SenderTask, NULL);
    pthread_create(&receiver_thread, NULL, ReceiverTask, NULL);

    pthread_join(sender_thread, NULL);
    pthread_join(receiver_thread, NULL);

    mq_close(mq);
```c
    mq_unlink(QUEUE_NAME);
    return 0;
}

/*
11. Real-Time Clock (RTC) Implementation
Concepts: RTC, timekeeping, low-power modes

Problem: Implement a real-time clock (RTC) to keep track of the current time and date.
 */
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

struct tm current_time;

void RTCISR(void) {
    // Update the current time
    current_time.tm_sec++;
    if (current_time.tm_sec >= 60) {
        current_time.tm_sec = 0;
        current_time.tm_min++;
        if (current_time.tm_min >= 60) {
            current_time.tm_min = 0;
            current_time.tm_hour++;
            if (current_time.tm_hour >= 24) {
                current_time.tm_hour = 0;
                current_time.tm_mday++;
                // Handle month and year changes
            }
        }
    }
}

void InitRTC(void) {
    // Configure the RTC hardware to generate an interrupt every second
}

int main(void) {
    InitRTC();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
12. I2C Communication with Multiple Slaves
Concepts: I2C protocol, multi-master, multi-slave communication

Problem: Implement I2C communication to interface with multiple slave devices.
 */
#include <stdint.h>
#include <stdbool.h>

#define I2C_ADDRESS_SLAVE1 0x50
#define I2C_ADDRESS_SLAVE2 0x60

void I2C_Write(uint8_t slave_address, uint8_t *data, uint8_t length) {
    // Implement I2C write operation
}

void I2C_Read(uint8_t slave_address, uint8_t *data, uint8_t length) {
    // Implement I2C read operation
}

int main(void) {
    uint8_t data_to_write[] = {0x01, 0x02, 0x03};
    uint8_t data_to_read[3];

    I2C_Write(I2C_ADDRESS_SLAVE1, data_to_write, sizeof(data_to_write));
    I2C_Read(I2C_ADDRESS_SLAVE2, data_to_read, sizeof(data_to_read));

    while (1) {
        // Main loop
    }
    return 0;
}

/*
13. SPI Communication with DMA
Concepts: SPI protocol, DMA, data transfer efficiency

Problem: Implement SPI communication using DMA to transfer data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>

#define SPI_BUFFER_SIZE 256

uint8_t spi_tx_buffer[SPI_BUFFER_SIZE];
uint8_t spi_rx_buffer[SPI_BUFFER_SIZE];

void InitSPI(void) {
    // Configure SPI hardware
}

void InitDMA(void) {
    // Configure DMA for SPI data transfer
}

void StartSPITransfer(void) {
    // Start SPI data transfer using DMA
}

int main(void) {
    InitSPI();
    InitDMA();

    // Fill the transmit buffer with data
    for (int i = 0; i < SPI_BUFFER_SIZE; i++) {
        spi_tx_buffer[i] = i;
    }

    StartSPITransfer();

    while (1) {
        // Main loop
    }
    return 0;
}

/*
14. Implementing a Finite State Machine (FSM)
Concepts: FSM, state transitions, event handling

Problem: Implement a finite state machine to control a simple traffic light system.
 */
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} TrafficLightState;

TrafficLightState current_state = STATE_RED;

void TrafficLightFSM(void) {
    switch (current_state) {
        case STATE_RED:
            // Turn on red light
            if (/* condition to change to green */) {
                current_state = STATE_GREEN;
            }
            break;
        case STATE_GREEN:
            // Turn on green light
            if (/* condition to change to yellow */) {
                current_state = STATE_YELLOW;
            }
            break;
        case STATE_YELLOW:
            // Turn on yellow light
            if (/* condition to change to red */) {
                current_state = STATE_RED;
            }
            break;
    }
}

int main(void) {
    while (1) {
        TrafficLightFSM();
        // Delay to simulate time passing
    }
    return 0;
}

/*
15. Handling Multiple ADC Channels
Concepts: ADC, multiplexing, data acquisition

Problem: Implement a system to read data from multiple ADC channels and process the data.
 */
#include <stdint.h>
#include <stdbool.h>

#define NUM_ADC_CHANNELS 4

uint16_t adc_values[NUM_ADC_CHANNELS];

void ADCISR(void) {
    static uint8_t current_channel = 0;
    adc_values[current_channel] = ADC_Read(current_channel);
    current_channel = (current_channel + 1) % NUM_ADC_CHANNELS;
    ADC_StartConversion(current_channel);
}

void InitADC(void) {
    // Configure ADC hardware and enable interrupts
    ADC_StartConversion(0);
}

int main(void) {
    InitADC();
    while (1) {
        // Process ADC values
    }
    return 0;
}

/*
16. PWM Signal Generation for Motor Control
Concepts: PWM, motor control, duty cycle adjustment

Problem: Implement PWM signal generation to control the speed of a motor.
 */
#include <stdint.h>
#include <stdbool.h>

#define PWM_FREQUENCY 1000 // 1 kHz

void SetPWMDutyCycle(uint8_t duty_cycle) {
    // Set the PWM duty cycle (0-100%)
}

void InitPWM(void) {
    // Configure PWM hardware
}

int main(void) {
    InitPWM();
    while (1) {
        for (uint8_t duty_cycle = 0; duty_cycle <= 100; duty_cycle++) {
            SetPWMDutyCycle(duty_cycle);
            // Delay to observe the change in motor speed
        }
    }
    return 0;
}

/*
17. Implementing a Circular Buffer for Data Logging
Concepts: Circular buffer, data logging, memory management

Problem: Implement a circular buffer to log data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} CircularBuffer;

CircularBuffer log_buffer;

void LogData(uint8_t data) {
    log_buffer.buffer[log_buffer.head] = data;
    log_buffer.head = (log_buffer.head + 1) % BUFFER_SIZE;
    if (log_buffer.head == log_buffer.tail) {
        log_buffer.tail = (log_buffer.tail + 1) % BUFFER_SIZE; // Overwrite oldest data
    }
}

uint8_t ReadLog(void) {
    if (log_buffer.head == log_buffer.tail) {
        return 0; // Buffer is empty
    }
    uint8_t data = log_buffer.buffer[log_buffer.tail];
    log_buffer.tail = (log_buffer.tail + 1) % BUFFER_SIZE;
    return data;
}

int main(void) {
    while (1) {
        // Log data and read log
    }
    return 0;
}

/*
18. Low-Power Modes and Wake-Up Sources
Concepts: Low-power modes, wake-up sources, power management

Problem: Implement a system that enters a low-power mode and wakes up on an external interrupt.
 */
#include <stdint.h>
#include <stdbool.h>

void EnterLowPowerMode(void) {
    // Configure the system to enter a low-power mode
}

void WakeUpISR(void) {
    // Handle wake-up event
}

void InitWakeUpSource(void) {
    // Configure external interrupt as wake-up source
}

int main(void) {
    InitWakeUpSource();
    while (1) {
        EnterLowPowerMode();
        // System will wake up on external interrupt
    }
    return 0;
}

/*
19. Implementing a Bootloader
Concepts: Bootloader, firmware update, memory management

Problem: Implement a bootloader to update firmware over UART.
 */
#include <stdint.h>
#include <stdbool.h>

#define FIRMWARE_START_ADDRESS 0x08004000

void UART_ReceiveFirmware(void) {
    // Receive firmware data over UART and write to flash memory
}

void JumpToFirmware(void) {
    void (*firmware_start)(void) = (void (*)(void))(*(uint32_t *)(FIRMWARE_START_ADDRESS + 4));
    __set_MSP(*(uint32_t *)FIRMWARE_START_ADDRESS);
    firmware_start();
}

int main(void) {
    UART_ReceiveFirmware();
    JumpToFirmware();
    while (1) {
        // Main loop
    }
    return 0;
}

/*
20. Handling External Interrupts with Debouncing
Concepts: External interrupts, debouncing, GPIO

Problem: Implement a system to handle external interrupts withdebouncing.
 */
#include <stdint.h>
#include <stdbool.h>

#define DEBOUNCE_DELAY 50 // 50 milliseconds

volatile bool button_pressed = false;
volatile uint32_t last_interrupt_time = 0;

void ExternalInterruptISR(void) {
    uint32_t current_time = GetSystemTime();
    if ((current_time - last_interrupt_time) > DEBOUNCE_DELAY) {
        button_pressed = true;
        last_interrupt_time = current_time;
    }
}

void InitExternalInterrupt(void) {
    // Configure external interrupt and enable it
}

int main(void) {
    InitExternalInterrupt();
    while (1) {
        if (button_pressed) {
            // Handle button press
            button_pressed = false;
        }
    }
    return 0;
}

/*
1. Implementing a Round-Robin Scheduler
Concepts: Task scheduling, round-robin algorithm, context switching

Problem: Implement a simple round-robin scheduler to manage multiple tasks.
 */
 #include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
} Task;

Task tasks[MAX_TASKS];
uint8_t current_task = 0;

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task == NULL) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
2. Priority-Based Preemptive Scheduler
Concepts: Priority scheduling, preemption, context switching

Problem: Implement a priority-based preemptive scheduler to manage multiple tasks.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32```c
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
    uint8_t priority;
    bool active;
} Task;

Task tasks[MAX_TASKS];

void SchedulerISR(void) {
    uint8_t highest_priority = 255;
    int highest_priority_task = -1;

    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].active && tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].remaining_time = tasks[i].period;
                if (tasks[i].priority < highest_priority) {
                    highest_priority = tasks[i].priority;
                    highest_priority_task = i;
                }
            }
        }
    }

    if (highest_priority_task != -1) {
        tasks[highest_priority_task].task();
    }
}

void AddTask(TaskFunction task, uint32_t period, uint8_t priority) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            tasks[i].priority = priority;
            tasks[i].active = true;
            break;
        }
    }
}

void InitScheduler(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitScheduler();
    AddTask(Task1, 1000, 1);
    AddTask(Task2, 2000, 2);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
3. Implementing a Mutex for Synchronization
Concepts: Mutex, critical section, synchronization

Problem: Implement a mutex to protect a critical section in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t mutex;
int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);
        shared_data++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);
        shared_data--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&mutex);
    return 0;
}
/*
4. Semaphore-Based Synchronization
Concepts: Semaphores, synchronization, inter-process communication

Problem: Implement semaphore-based synchronization to manage access to a shared resource.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;
int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        sem_wait(&semaphore);
        shared_data--;
        sem_post(&semaphore);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    sem_destroy(&semaphore);
    return 0;
}
/*
5. Implementing a Spinlock
Concepts: Spinlock, busy-waiting, synchronization

Problem: Implement a spinlock to protect a critical section in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile bool lock = false;

void SpinlockAcquire(void) {
    while (__sync_lock_test_and_set(&lock, 1)) {
        // Busy-wait until the lock is acquired
    }
}

void SpinlockRelease(void) {
    __sync_lock_release(&lock);
}

int shared_data = 0;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        SpinlockAcquire();
        shared_data++;
        SpinlockRelease();
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        SpinlockAcquire();
        shared_data--;
        SpinlockRelease();
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    return 0;
}
/*
6. Cache Coherence in Multi-Core Systems
Concepts: Cache coherence, multi-core, memory consistency

Problem: Implement a mechanism to ensure cache coherence in a multi-core system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile int shared_data = 0;

void *Core1Task(void *arg) {
    for (int i = 0; i < 1000; i++) {
        __sync_fetch_and_add(&shared_data, 1);
    }
    return NULL;
}

void *Core2Task(void *arg) {
    for (int i = 0; i < 1000; i++) {
        __sync_fetch_and_sub(&shared_data, 1);
    }
    return NULL;
}

int main(void) {
    pthread_t core1_thread, core2_thread;

    pthread_create(&core1_thread, NULL, Core1Task, NULL);
    pthread_create(&core2_thread, NULL, Core2Task, NULL);

    pthread_join(core1_thread, NULL);
    pthread_join(core2_thread, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    return 0;
}
/*
7. Implementing a Memory Barrier
Concepts: Memory barrier, instruction ordering, synchronization

Problem: Implement a memory barrier to ensure proper instruction ordering in a multi-core system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

volatile int shared_data = 0;
volatile bool flag = false;

void MemoryBarrier(void) {
    __sync_synchronize();
}

void *ProducerTask(void *arg) {
    shared_data = 42;
    MemoryBarrier();
    flag = true;
    return NULL;
}

void *ConsumerTask(void *arg) {
    while (!flag) {
        // Busy-wait until flag is set
    }
    MemoryBarrier();
    printf("Shared data: %d\n", shared_data);
    return NULL;
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, ProducerTask, NULL);
    pthread_create(&consumer_thread, NULL, ConsumerTask, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
/*
8. Page Replacement Algorithms
Concepts: Memory management, page replacement, algorithms

Problem: Implement the Least Recently Used (LRU) page replacement algorithm.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_PAGES 4
#define NUM_FRAMES 3

int pages[NUM_PAGES] = {1, 2, 3, 4};
int frames[NUM_FRAMES] = {-1, -1, -1};
int lru[NUM_FRAMES] = {0, 0, 0};

int FindLRU(void) {
    int min = lru[0], pos = 0;
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (lru[i] < min) {
            min = lru[i];
            pos = i;
        }
    }
    return pos;
}

void PageReplacement(void) {
    int page_faults = 0;
    for (int i = 0; i < NUM_PAGES; i++) {
        int page =```c
        pages[i];
        bool found = false;
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = true;
                lru[j] = i;
                break;
            }
        }
        if (!found) {
            int pos = FindLRU();
            frames[pos] = page;
            lru[pos] = i;
            page_faults++;
        }
    }
    printf("Page faults: %d\n", page_faults);
}

int main(void) {
    PageReplacement();
    return 0;
}
/*
9. Implementing a Simple Virtual Memory System
Concepts: Virtual memory, paging, memory management

Problem: Implement a simple virtual memory system with paging.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 16
#define NUM_FRAMES 4

typedef struct {
    int frame_number;
    bool valid;
} PageTableEntry;

PageTableEntry page_table[NUM_PAGES];
int frames[NUM_FRAMES] = {-1, -1, -1, -1};

int AllocateFrame(void) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frames[i] == -1) {
            return i;
        }
    }
    return -1; // No available frames
}

void AccessMemory(int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;

    if (!page_table[page_number].valid) {
        int frame_number = AllocateFrame();
        if (frame_number == -1) {
            printf("Page fault: No available frames\n");
            return;
        }
        page_table[page_number].frame_number = frame_number;
        page_table[page_number].valid = true;
        frames[frame_number] = page_number;
    }

    int physical_address = page_table[page_number].frame_number * PAGE_SIZE + offset;
    printf("Virtual address %d maps to physical address %d\n", virtual_address, physical_address);
}

int main(void) {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i].valid = false;
    }

    AccessMemory(0);
    AccessMemory(4096);
    AccessMemory(8192);
    AccessMemory(12288);
    AccessMemory(16384);

    return 0;
}
/*
10. Handling Page Faults
Concepts: Page faults, memory management, exception handling

Problem: Implement a mechanism to handle page faults in a virtual memory system.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 16
#define NUM_FRAMES 4

typedef struct {
    int frame_number;
    bool valid;
} PageTableEntry;

PageTableEntry page_table[NUM_PAGES];
int frames[NUM_FRAMES] = {-1, -1, -1, -1};

int AllocateFrame(void) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frames[i] == -1) {
            return i;
        }
    }
    return -1; // No available frames
}

void HandlePageFault(int page_number) {
    int frame_number = AllocateFrame();
    if (frame_number == -1) {
        printf("Page fault: No available frames\n");
        return;
    }
    page_table[page_number].frame_number = frame_number;
    page_table[page_number].valid = true;
    frames[frame_number] = page_number;
}

void AccessMemory(int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;

    if (!page_table[page_number].valid) {
        HandlePageFault(page_number);
    }

    int physical_address = page_table[page_number].frame_number * PAGE_SIZE + offset;
    printf("Virtual address %d maps to physical address %d\n", virtual_address, physical_address);
}

int main(void) {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i].valid = false;
    }

    AccessMemory(0);
    AccessMemory(4096);
    AccessMemory(8192);
    AccessMemory(12288);
    AccessMemory(16384);

    return 0;
}
/*
11. Implementing a Memory Pool Allocator
Concepts: Memory management, dynamic allocation, memory pools

Problem:Implement a memory pool allocator to manage dynamic memory allocation efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

uint8_t memory_pool[POOL_SIZE];
bool block_used[POOL_SIZE / BLOCK_SIZE];

void *AllocateBlock(void) {
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        if (!block_used[i]) {
            block_used[i] = true;
            return &memory_pool[i * BLOCK_SIZE];
        }
    }
    return NULL; // No available blocks
}

void FreeBlock(void *block) {
    int index = ((uint8_t *)block - memory_pool) / BLOCK_SIZE;
    block_used[index] = false;
}

int main(void) {
    void *block1 = AllocateBlock();
    void *block2 = AllocateBlock();
    FreeBlock(block1);
    void *block3 = AllocateBlock();
    return 0;
}
/*
12. Deadlock Detection and Recovery
Concepts: Deadlock detection, recovery, resource allocation

Problem: Implement a system to detect and recover from deadlocks using a resource allocation graph.
 */
#include <stdbool.h>
#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int request[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 0, 0},
    {2, 0, 2},
    {0, 0, 0},
    {1, 0, 0},
    {0, 0, 2}
};
int available[NUM_RESOURCES] = {3, 3, 2};

bool IsSafe(void) {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (request[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

void RequestResources(int process_id, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > available[i]) {
            printf("Request denied: Not enough resources\n");
            return;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
    }

    if (IsSafe()) {
        printf("Request granted\n");
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
        }
        printf("Request denied: Would cause deadlock\n");
    }
}

int main(void) {
    int request1[] = {1, 0, 2};
    RequestResources(1, request1);
    return 0;
}
/*
13. Implementing a Priority Inheritance Protocol
Concepts: Priority inversion, priority inheritance, synchronization

Problem: Implement a priority inheritance protocol to handle priority inversion.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t resource_mutex;
int resource;

void LowPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource++;
    pthread_mutex_unlock(&resource_mutex);
```c
    pthread_mutex_unlock(&resource_mutex);
}

void MediumPriorityTask(void) {
    // Perform some work
}

void HighPriorityTask(void) {
    pthread_mutex_lock(&resource_mutex);
    // Access shared resource
    resource--;
    pthread_mutex_unlock(&resource_mutex);
}

int main(void) {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&resource_mutex, &attr);

    // Create and start tasks
    pthread_create(&low_priority_thread, NULL, LowPriorityTask, NULL);
    pthread_create(&medium_priority_thread, NULL, MediumPriorityTask, NULL);
    pthread_create(&high_priority_thread, NULL, HighPriorityTask, NULL);

    while (1) {
        // Main loop
    }
    return 0;
}
/*
14. Race Condition in Multi-Threaded Environment
Concepts: Race condition, critical section, synchronization

Problem: Implement a solution to prevent race conditions when accessing shared memory in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t data_mutex;

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data++;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data_mutex);
        shared_data--;
        pthread_mutex_unlock(&data_mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_mutex_init(&data_mutex, NULL);

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&data_mutex);
    return 0;
}
/*
15. Implementing a Software Timer
Concepts: Timer, scheduling, interrupt handling

Problem: Implement a software timer using a hardware timer interrupt.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TIMERS 5

typedef void (*TimerCallback)(void);

typedef struct {
    uint32_t duration;
    uint32_t remaining_time;
    TimerCallback callback;
    bool active;
} SoftwareTimer;

SoftwareTimer timers[MAX_TIMERS];

void TimerISR(void) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i].active && timers[i].remaining_time > 0) {
            timers[i].remaining_time--;
            if (timers[i].remaining_time == 0) {
                timers[i].callback();
                timers[i].active = false;
            }
        }
    }
}

void InitHardwareTimer(void) {
    // Configure the hardware timer to generate an interrupt every 1 millisecond
}

int CreateSoftwareTimer(uint32_t duration, TimerCallback callback) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].duration = duration;
            timers[i].remaining_time = duration;
            timers[i].callback = callback;
            timers[i].active = true;
            return i;
        }
    }
    return -1;
}

void StartSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_TIMERS) {
        timers[timer_id].remaining_time = timers[timer_id].duration;
        timers[timer_id].active = true;
    }
}

void StopSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_TIMERS) {
        timers[timer_id].active = false;
    }
}

void TimerExpiredCallback(void) {
    // Handle timer expiration
}

int main(void) {
    InitHardwareTimer();

    int timer_id = CreateSoftwareTimer(1000, TimerExpiredCallback);
    StartSoftwareTimer(timer_id);

    while (1) {
        // Main loop
    }

    return 0;
}
/*
16. Thread Creation and Management
Concepts: Threading, task management, context switching

Problem: Implement thread creation and management in a multi-threaded environment.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

void```c
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

void *Task1(void *arg) {
    for (int i = 0; i < 1000; i++) {
        // Perform some work
    }
    return NULL;
}

void *Task2(void *arg) {
    for (int i = 0; i < 1000; i++) {
        // Perform some work
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Task1, NULL);
    pthread_create(&thread2, NULL, Task2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
/*
17. Implementing a Real-Time Operating System (RTOS) Kernel
Concepts: RTOS, task scheduling, inter-task communication

Problem: Implement a simple RTOS kernel with task scheduling and inter-task communication.
 */
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef void (*TaskFunction)(void);

typedef struct {
    TaskFunction task;
    uint32_t period;
    uint32_t remaining_time;
    bool active;
} Task;

Task tasks[MAX_TASKS];

void SchedulerISR(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].active && tasks[i].remaining_time > 0) {
            tasks[i].remaining_time--;
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].period;
            }
        }
    }
}

void AddTask(TaskFunction task, uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].task = task;
            tasks[i].period = period;
            tasks[i].remaining_time = period;
            tasks[i].active = true;
            break;
        }
    }
}

void InitRTOS(void) {
    // Configure the hardware timer to generate an interrupt at a regular interval
}

int main(void) {
    InitRTOS();
    AddTask(Task1, 1000);
    AddTask(Task2, 2000);
    while (1) {
        // Main loop
    }
    return 0;
}
/*
18. Implementing a Double-Ended Queue (Deque)
Concepts: Data structures, deque, memory management

Problem: Implement a double-ended queue (deque) to manage data efficiently.
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEQUE_SIZE 128

typedef struct {
    int data[DEQUE_SIZE];
    int front;
    int rear;
    int size;
} Deque;

Deque deque;

void InitDeque(void) {
    deque.front = -1;
    deque.rear = 0;
    deque.size = 0;
}

bool IsFull(void) {
    return deque.size == DEQUE_SIZE;
}

bool IsEmpty(void) {
    return deque.size == 0;
}

void InsertFront(int value) {
    if (IsFull()) {
        return;
    }
    if (deque.front == -1) {
        deque.front = 0;
        deque.rear = 0;
    } else if (deque.front == 0) {
        deque.front = DEQUE_SIZE - 1;
    } else {
        deque.front--;
    }
    deque.data[deque.front] = value;
    deque.size++;
}

void InsertRear(int value) {
    if (IsFull()) {
        return;
    }
    if (deque.front == -1) {
        deque.front = 0;
        deque.rear = 0;
    } else if (deque.rear == DEQUE_SIZE - 1) {
        deque.rear = 0;
    } else {
        deque.rear++;
    }
    deque.data[deque.rear] = value;
    deque.size++;
}

int DeleteFront(void) {
    if (IsEmpty()) {
        return -1;
    }
    int value = deque.data[deque.front];
    if (deque.front == deque.rear) {
        deque.front = -1;
        deque.rear = 0;
    } else if (deque.front == DEQUE_SIZE - 1) {
        deque.front = 0;
    } else {
        deque.front++;
    }
    deque.size--;
    return value;
}

int DeleteRear(void) {
    if (IsEmpty()) {
        return -1;
    }
    int value = deque.data[deque.rear];
    if (deque.front == deque.rear) {
        deque.front = -1;
        deque.rear = 0;
    } else if (deque.rear == 0) {
        deque.rear = DEQUE_SIZE - 1;
    } else {
        deque.rear--;
    }
    deque.size--;
    return value;
}

int main(void) {
    InitDeque();
    InsertFront(10);
    InsertRear(20);
    printf("Front: %d\n", DeleteFront());
    printf("Rear: %d\n", DeleteRear());
    return 0;
}
/*
19. Implementing a Bounded Buffer
Concepts: Bounded buffer, synchronization, inter-process communication

Problem: Implement a bounded buffer to manage data between producer and consumer tasks.
 */
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t buffer_mutex;

void *Producer(void *arg) {
    for (int i = 0; i < 100; i++) {
        int item = i; // Produce an item
        sem_wait(&empty);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full);
    }
    return NULL;
}

void *Consumer(void *arg) {
    for (int i = 0; i < 100; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_mutex);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty);
        printf("Consumed: %d\n", item);
    }
    return NULL;
}

int main(void) {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buffer_mutex, NULL);

    pthread_create(&producer_thread, NULL, Producer, NULL);
    pthread_create(&consumer_thread, NULL, Consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&buffer_mutex);

    return 0;
}
/*
20. Implementing a Priority Queue
Concepts: Data structures, priority queue, scheduling

Problem: Implement a priority queue to manage tasks based on their priority.
*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct {
    int priority;
    void (*task)(void);
} Task;

Task priority_queue[MAX_TASKS];
int task_count = 0;

void Swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void InsertTask(int priority, void (*task)(void)) {
    if (task_count == MAX_TASKS) {
        printf("Priority queue is full\n");
        return;
    }
    Task new_task = {priority, task};
    priority_queue[task_count] = new_task;
    int i = task_count;
    while (i > 0 && priority_queue[i].priority < priority_queue[(i - 1) / 2].priority) {
        Swap(&priority_queue[i], &priority_queue[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    task_count++;
}

Task ExtractMin(void) {
    if (task_count == 0) {
        printf("Priority queue is empty\n");
        exit(1);
    }
    Task min_task = priority_queue[0];
    priority_queue[0] = priority_queue[--task_count];
    int i = 0;
    while (2 * i + 1 < task_count) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < task_count && priority_queue[left].priority < priority_queue[smallest].priority) {
            smallest = left;
        }
        if (right < task_count && priority_queue[right].priority < priority_queue[smallest].priority) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        Swap(&priority_queue[i], &priority_queue[[smallest]);
        i = smallest;
    }
    return min_task;
}

void Task1(void) {
    printf("Executing Task 1\n");
}

void Task2(void) {
    printf("Executing Task 2\n");
}

int main(void) {
    InsertTask(2, Task1);
    InsertTask(1, Task2);

    while (task_count > 0) {
        Task task = ExtractMin();
        task.task();
    }

    return 0;
}

//BONUS QNA

/*
Now, Imagine I want to use Hardware timer internally to make software timer on top of it. Show me how would you design this?

Designing a software timer on top of a hardware timer involves leveraging the hardware timer's capabilities to create multiple software-based timers. Here's a step-by-step approach to achieve this:

1. Understanding the Hardware Timer
A hardware timer typically has the following features:

A counter that increments or decrements based on a clock source.
An interrupt that triggers when the counter reaches a specific value (overflow or compare match).
2. Designing the Software Timer
The software timer will use the hardware timer's interrupt to keep track of elapsed time and manage multiple software timers.

3. Implementation Steps
Step 1: Initialize the Hardware Timer
Configure the hardware timer to generate an interrupt at a regular interval (e.g., every 1 millisecond).

Step 2: Define Software Timer Structures
Create a structure to represent each software timer, including fields for the timer's duration, remaining time, and a callback function to be executed when the timer expires.

Step 3: Implement the Timer Management Functions
Implement functions to create, start, stop, and manage software timers.

Step 4: Handle the Hardware Timer Interrupt
In the hardware timer interrupt service routine (ISR), decrement the remaining time for each active software timer and call the callback function if a timer expires.
*/

#include <stdint.h>
#include <stdbool.h>

#define MAX_SOFTWARE_TIMERS 10

typedef void (*TimerCallback)(void);

typedef struct {
    uint32_t duration;       // Timer duration in milliseconds
    uint32_t remaining_time; // Remaining time in milliseconds
    TimerCallback callback;  // Callback function to be called when timer expires
    bool active;             // Timer active flag
} SoftwareTimer;

SoftwareTimer timers[MAX_SOFTWARE_TIMERS];

// Hardware timer interrupt service routine (ISR)
void TimerISR(void) {
    for (int i = 0; i < MAX_SOFTWARE_TIMERS; i++) {
        if (timers[i].active && timers[i].remaining_time > 0) {
            timers[i].remaining_time--;
            if (timers[i].remaining_time == 0) {
                timers[i].callback();
                timers[i].active = false; // Deactivate the timer
            }
        }
    }
}

// Initialize the hardware timer
void InitHardwareTimer(void) {
    // Configure the hardware timer to generate an interrupt every 1 millisecond
    // This is platform-specific and depends on the microcontroller being used
}

// Create a software timer
int CreateSoftwareTimer(uint32_t duration, TimerCallback callback) {
    for (int i = 0; i < MAX_SOFTWARE_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].duration = duration;
            timers[i].remaining_time = duration;
            timers[i].callback = callback;
            timers[i].active = true;
            return i; // Return the timer ID
        }
    }
    return -1; // No available timer slots
}

// Start a software timer
void StartSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_SOFTWARE_TIMERS) {
        timers[timer_id].remaining_time = timers[timer_id].duration;
        timers[timer_id].active = true;
    }
}

// Stop a software timer
void StopSoftwareTimer(int timer_id) {
    if (timer_id >= 0 && timer_id < MAX_SOFTWARE_TIMERS) {
        timers[timer_id].active = false;
    }
}

// Example callback function
void TimerExpiredCallback(void) {
    // Handle timer expiration
}

int main(void) {
    InitHardwareTimer();

    // Create and start a software timer with a duration of 1000 milliseconds (1 second)
    int timer_id = CreateSoftwareTimer(1000, TimerExpiredCallback);
    StartSoftwareTimer(timer_id);

    while (1) {
        // Main loop
    }

    return 0;
}

/*
context swtiching

Context switching is a fundamental concept in embedded systems, especially in real-time operating systems (RTOS). Let's add a problem that involves context switching, where the task context is stored on the stack and restored during a scheduling interrupt.

Problem: Implementing Context Switching
Concepts: Context switching, task scheduling, stack management, interrupt handling

Problem: Implement a context switcher that saves the current task's context (registers, stack pointer, etc.) onto its stack and restores the next task's context from its stack during a scheduling interrupt.

Solution
To implement context switching, we need to:

Define the Task Control Block (TCB): This structure will hold the task's context, including the stack pointer and other registers.
Implement the Scheduler: This will decide which task to run next.
Implement the Context Switcher: This will save the current task's context and restore the next task's context.

Explanation
Task Control Block (TCB): The TaskControlBlock structure holds the stack pointer and the stack for each task.

SaveContext: This function saves the current task's context (registers r4-r11 and the stack pointer) onto its stack.

RestoreContext: This function restores the next task's context from its stack.

SchedulerISR: This is the scheduler interrupt service routine. It saves the current task's context, selects the next task, and restores its context.

InitTask: This function initializes a task by setting up its stack and stack pointer.

Tasks: Three simple tasks (Task1, Task2, and Task3) that print their task number in an infinite loop.

main: The main function initializes the tasks, sets up the SysTick timer for scheduling, and starts the first task.

Summary
This example demonstrates how to implement context switching in anembedded system. 
The context switcher saves the current task's context onto its stack and restores the next task's context from its stack during a scheduling interrupt. 
This approach is fundamental in real-time operating systems (RTOS) and is crucial for managing multiple tasks efficiently.

Additional Problems
Here are 20 more low-level embedded system problems focusing on deep OS concepts like scheduling, cache management, memory management, and more:

Implementing a Non-Preemptive Scheduler
Concepts: Task scheduling, non-preemptive scheduling, context switching

Implementing a Priority Queue for Task Scheduling
Concepts: Priority queue, task scheduling, data structures

Implementing a Memory Manager with Buddy System
Concepts: Memory management, buddy system, dynamic allocation

Implementing a Cache Replacement Policy
Concepts: Cache management, replacement policies, LRU

Implementing a Spinlock for Multi-Core Systems
Concepts: Spinlock, synchronization, multi-core

Implementing a Semaphore for Resource Management
Concepts: Semaphore, synchronization, resource management

Implementing a Mutex with Priority Inheritance
Concepts: Mutex, priority inheritance, synchronization

Implementing a Round-Robin Scheduler with Time Slicing
Concepts: Round-robin scheduling, time slicing, context switching

Implementing a Real-Time Clock (RTC) with Alarms
Concepts: RTC, timekeeping, alarms

Implementing a Memory Pool with Fixed-Size Blocks
Concepts: Memory management, memory pool, fixed-size blocks

Implementing a Deadlock Detection Algorithm
Concepts: Deadlock detection, resource allocation, algorithms

Implementing a Task Scheduler with EDF (Earliest Deadline First)
Concepts: Task scheduling, EDF, real-time systems

Implementing a Software Timer with Multiple Timers
Concepts: Software timer, scheduling, interrupt handling

Implementing a Task Scheduler with Rate Monotonic Scheduling (RMS)
Concepts: Task scheduling, RMS, real-time systems

Implementing a Memory Barrier for Multi-Core Systems
Concepts: Memory barrier, synchronization, multi-core

Implementing a Task Scheduler with Fixed-Priority Preemptive Scheduling
Concepts: Task scheduling, fixed-priority, preemptive scheduling

Implementing a Task Scheduler with Dynamic Priority Scheduling
Concepts: Task scheduling, dynamic priority, context switching

Implementing a Task Scheduler with Sporadic Server Scheduling
Concepts: Task scheduling, sporadic server, real-time systems

Implementing a Task Scheduler with Deferrable Server Scheduling
Concepts: Task scheduling, deferrable server, real-time systems

Implementing a Task Scheduler with Slack Stealing
Concepts: Task scheduling, slack stealing, real-time systems
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_TASKS 3
#define STACK_SIZE 1024

typedef struct {
    uint32_t *stack_pointer;
    uint32_t stack[STACK_SIZE];
} TaskControlBlock;

TaskControlBlock tasks[MAX_TASKS];
int current_task = 0;

void SaveContext(TaskControlBlock *tcb) {
    asm volatile (
        "mrs r0, psp\n"          // Get Process Stack Pointer
        "stmdb r0!, {r4-r11}\n"  // Save registers r4-r11
        "str r0, [%0]\n"         // Save stack pointer to TCB
        : : "r" (&tcb->stack_pointer) : "memory"
    );
}

void RestoreContext(TaskControlBlock *tcb) {
    asm volatile (
        "ldr r0, [%0]\n"         // Load stack pointer from TCB
        "ldmia r0!, {r4-r11}\n"  // Restore registers r4-r11
        "msr psp, r0\n"          // Set Process Stack Pointer
        : : "r" (&tcb->stack_pointer) : "memory"
    );
}

void SchedulerISR(void) {
    SaveContext(&tasks[current_task]);
    current_task = (current_task + 1) % MAX_TASKS;
    RestoreContext(&tasks[current_task]);
}

void InitTask(TaskControlBlock *tcb, void (*task_function)(void)) {
    tcb->stack_pointer = &tcb->stack[STACK_SIZE - 16];
    tcb->stack[STACK_SIZE - 1] = 0x01000000; // xPSR
    tcb->stack[STACK_SIZE - 2] = (uint32_t)task_function; // PC
    tcb->stack[STACK_SIZE - 3] = 0xFFFFFFFD; // LR
}

void Task1(void) {
    while (1) {
        printf("Task 1\n");
    }
}

void Task2(void) {
    while (1) {
        printf("Task 2\n");
    }
}

void Task3(void) {
    while (1) {
        printf("Task 3\n");
    }
}

int main(void) {
    InitTask(&tasks[0], Task1);
    InitTask(&tasks[1], Task2);
    InitTask(&tasks[2], Task3);

    // Set up the SysTick timer to generate an interrupt for scheduling
    SysTick_Config(SystemCoreClock / 1000);

    // Start the first task
    RestoreContext(&tasks[0]);

    while (1) {
        // Main loop
    }

    return 0;
}
