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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sure! Let's go through each of the 30 coding problems, explaining the concept in depth and providing a working C program for each. Due to the length and complexity of these problems, I'll provide detailed explanations and code for the first few problems. If you need more, please let me know, and I can continue with the rest.

1. Implement a Simple Thread Pool in C
Concept:
A thread pool is a collection of pre-initialized threads that stand ready to perform tasks. When a task is submitted, a thread from the pool is assigned to execute it. This approach helps in managing a large number of short-lived tasks efficiently by reusing threads, thus reducing the overhead of thread creation and destruction.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_POOL_SIZE 4
#define TASK_QUEUE_SIZE 10

typedef struct {
    void (*function)(void*);
    void* argument;
} Task;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t notify;
    pthread_t threads[THREAD_POOL_SIZE];
    Task taskQueue[TASK_QUEUE_SIZE];
    int taskCount;
    int head;
    int tail;
    int shutdown;
} ThreadPool;

ThreadPool pool;

void* threadFunction(void* arg) {
    while (1) {
        pthread_mutex_lock(&pool.lock);

        while (pool.taskCount == 0 && !pool.shutdown) {
            pthread_cond_wait(&pool.notify, &pool.lock);
        }

        if (pool.shutdown) {
            pthread_mutex_unlock(&pool.lock);
            pthread_exit(NULL);
        }

        Task task = pool.taskQueue[pool.head];
        pool.head = (pool.head + 1) % TASK_QUEUE_SIZE;
        pool.taskCount--;

        pthread_mutex_unlock(&pool.lock);

        (*(task.function))(task.argument);
    }
    return NULL;
}

void threadPoolInit() {
    pthread_mutex_init(&pool.lock, NULL);
    pthread_cond_init(&pool.notify, NULL);
    pool.taskCount = 0;
    pool.head = 0;
    pool.tail = 0;
    pool.shutdown = 0;

    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&pool.threads[i], NULL, threadFunction, NULL);
    }
}

void threadPoolShutdown() {
    pthread_mutex_lock(&pool.lock);
    pool.shutdown = 1;
    pthread_cond_broadcast(&pool.notify);
    pthread_mutex_unlock(&pool.lock);

    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(pool.threads[i], NULL);
    }

    pthread_mutex_destroy(&pool.lock);
    pthread_cond_destroy(&pool.notify);
}

void threadPoolAddTask(void (*function)(void*), void* argument) {
    pthread_mutex_lock(&pool.lock);

    pool.taskQueue[pool.tail].function = function;
    pool.taskQueue[pool.tail].argument = argument;
    pool.tail = (pool.tail + 1) % TASK_QUEUE_SIZE;
    pool.taskCount++;

    pthread_cond_signal(&pool.notify);
    pthread_mutex_unlock(&pool.lock);
}

void sampleTask(void* arg) {
    int num = *(int*)arg;
    printf("Task %d is being processed by thread %ld\n", num, pthread_self());
    sleep(1);
}

int main() {
    threadPoolInit();

    int taskArgs[TASK_QUEUE_SIZE];
    for (int i = 0; i < TASK_QUEUE_SIZE; i++) {
        taskArgs[i] = i;
        threadPoolAddTask(sampleTask, &taskArgs[i]);
    }

    sleep(5);
    threadPoolShutdown();
    return 0;
}
2. Write a Program to Simulate the Dining Philosophers Problem Using Semaphores
Concept:
The Dining Philosophers problem is a classic synchronization problem. It involves philosophers sitting at a table with a fork between each pair. A philosopher needs both forks to eat but can only pick up one fork at a time. The challenge is to design a protocol that prevents deadlock and ensures that no philosopher starves.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int id = *(int*)num;
    int leftFork = id;
    int rightFork = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        printf(""Philosopher %d is hungry.\n", id);

        // Pick up forks
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);

        printf("Philosopher %d is eating.\n", id);
        sleep(1);

        // Put down forks
        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
    }
    return NULL;
}

int main() {
    int ids[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
3. Implement the Banker's Algorithm for Deadlock Avoidance in C
Concept:
The Banker's Algorithm is used to avoid deadlock by ensuring that resource allocation does not leave the system in an unsafe state. It checks if granting a resource request will keep the system in a safe state.

Code:
c
#include <stdio.h>
#include <stdbool.h>

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

void calculateNeed() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false};

    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool canProceed = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }
                if (canProceed) {
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

bool requestResources(int process, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > need[process][i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > available[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    if (isSafe()) {
        return true;
    } else {
        for (int i = 0; i < NUM_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[[i][j] += request[i];
        }
        return false;
    }
}

int main() {
    calculateNeed();

    int process = 1;
    int request[NUM_RESOURCES] = {1, 0, 2};

    if (requestResources(process, request)) {
        printf("Request granted.\n");
    } else {
        printf("Request denied.\n");
    }

    return 0;
}
4. Write a Program to Demonstrate the Use of Mutexes for Thread Synchronization
Concept:
Mutexes (mutual exclusions) are used to prevent multiple threads from accessing a shared resource simultaneously, which can lead to data corruption. Mutexes ensure that only one thread can access the critical section at a time.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int counter = 0;

void* incrementCounter(void* arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread %ld incremented counter to %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, incrementCounter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
5. Implement a Producer-Consumer Problem Using Condition Variables and Mutexes
Concept:
The producer-consumer problem is a classic synchronization problem where producers generate data and place it in a buffer, and consumers take data from the buffer. Condition variables and mutexes are used to synchronize access to the buffer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex;
pthread_cond_t notEmpty;
pthread_cond_t notFull;

void* producer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&notFull, &mutex);
        }

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced: %d\n", i);

        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&notEmpty, &mutex);
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed: %d\n", item);

        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prodThread, consThread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&notEmpty, NULL);
    pthread_cond_init(&notFull, NULL);

    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);

    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&notEmpty);
    pthread_cond_destroy(&notFull);

    return 0;
}
6. Write a Program to Simulate a Priority Queue Scheduler
Concept:
A priority queue scheduler assigns tasks based on their priority. Higher priority tasks are executed before lower priority ones. This can be implemented using a priority queue data structure.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int taskID;
} Task;

typedef struct {
    Task* tasks;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->tasks = (Task*)malloc(sizeof(Task) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Task* a, Task* b)```c
void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index && pq->tasks[(index - 1) / 2].priority < pq->tasks[index].priority) {
        swap(&pq->tasks[index], &pq->tasks[(index - 1) / 2]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->tasks[left].priority > pq->tasks[largest].priority) {
        largest = left;
    }

    if (right < pq->size && pq->tasks[right].priority > pq->tasks[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->tasks[index], &pq->tasks[largest]);
        heapifyDown(pq, largest);
    }
}

void insertTask(PriorityQueue* pq, int priority, int taskID) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full\n");
        return;
    }

    pq->tasks[pq->size].priority = priority;
    pq->tasks[pq->size].taskID = taskID;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

Task extractMax(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        Task emptyTask = {0, 0};
        return emptyTask;
    }

    Task root = pq->tasks[0];
    pq->tasks[0] = pq->tasks[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);

    return root;
}

void printTasks(PriorityQueue* pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("Task ID: %d, Priority: %d\n", pq->tasks[i].taskID, pq->tasks[i].priority);
    }
}

int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    insertTask(pq, 3, 101);
    insertTask(pq, 5, 102);
    insertTask(pq, 1, 103);
    insertTask(pq, 4, 104);

    printf("Tasks in Priority Queue:\n");
    printTasks(pq);

    printf("\nExtracting tasks based on priority:\n");
    while (pq->size > 0) {
        Task task = extractMax(pq);
        printf("Task ID: %d, Priority: %d\n", task.taskID, task.priority);
    }

    free(pq->tasks);
    free(pq);

    return 0;
}
7. Implement a Simple Round-Robin Scheduler in C
Concept:
A round-robin scheduler assigns a fixed time slice to each task in a cyclic order. This ensures that all tasks get an equal share of the CPU time.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_TASKS 4
#define TIME_SLICE 1

typedef struct {
    int taskID;
    int burstTime;
} Task;

void roundRobinScheduler(Task tasks[], int numTasks, int timeSlice) {
    int remainingBurstTime[NUM_TASKS];
    for (int i = 0; i < numTasks; i++) {
        remainingBurstTime[i] = tasks[i].burstTime;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < numTasks; i++) {
            if (remainingBurstTime[i] > 0) {
                done = 0;
                if (remainingBurstTime[i] > timeSlice) {
                    time += timeSlice;
                    remainingBurstTime[i] -= timeSlice;
                } else {
                    time += remainingBurstTime[i];
                    remainingBurstTime[i] = 0;
                    printf("Task %d finished at time %d\n", tasks[i].taskID, time);
                }
            }
        }
        if (done) {
            break;
        }
    }
}

int main() {
    Task tasks[NUM_TASKS] = {
        {1, 5},
        {2, ```c
        {2, 3},
        {3, 8},
        {4, 6}
    };

    printf("Round-Robin Scheduling:\n");
    roundRobinScheduler(tasks, NUM_TASKS, TIME_SLICE);

    return 0;
}
8. Write a Program to Demonstrate the Use of Read-Write Locks
Concept:
Read-write locks allow multiple threads to read a shared resource simultaneously while ensuring exclusive access for writing. This improves performance when reads are more frequent than writes.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_rwlock_t rwlock;
int sharedData = 0;

void* reader(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Reader %d: read sharedData = %d\n", id, sharedData);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);
        sharedData++;
        printf("Writer %d: updated sharedData to %d\n", id, sharedData);
        pthread_rwlock_unlock(&rwlock);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int ids[NUM_READERS + NUM_WRITERS];

    pthread_rwlock_init(&rwlock, NULL);

    for (int i = 0; i < NUM_READERS; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        ids[NUM_READERS + i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[NUM_READERS + i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    return 0;
}
9. Implement a Barrier Synchronization Mechanism in C
Concept:
A barrier synchronization mechanism ensures that multiple threads reach a certain point in their execution before any of them proceed. This is useful for coordinating phases of parallel computation.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_barrier_t barrier;

void* threadFunction(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d reached the barrier\n", id);
    pthread_barrier_wait(&barrier);
    printf("Thread %d passed the barrier\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
    return 0;
}
10. Write a Program to Simulate a Simple Memory Allocator Using the Buddy System
Concept:
The buddy system is a memory allocation technique that divides memory into partitions to try to satisfy a memory request as suitably as possible. Memory is allocated in powers of two, and adjacent free blocks of the same size can be combined to form a larger block.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEVEL 5
#define MIN_BLOCK_SIZE 32

typedef struct Block {
    int size;
    int isFree;
    struct Block* next;
} Block;

Block* freeList[MAX_LEVEL + 1];

void initializeMemory() {
    for (int i = 0; i <= MAX_LEVEL; i++) {
        freeList[i] = NULL;
    }
    Block* initialBlock = (Block*)malloc(sizeof(Block));
    initialBlock->size = MIN_BLOCK_SIZE * (1 << MAX_LEVEL);
```c
    initialBlock->isFree = 1;
    initialBlock->next = NULL;
    freeList[MAX_LEVEL] = initialBlock;
}

int getLevel(int size) {
    int level = 0;
    while ((MIN_BLOCK_SIZE * (1 << level)) < size) {
        level++;
    }
    return level;
}

void* allocateMemory(int size) {
    int level = getLevel(size);
    if (level > MAX_LEVEL) {
        return NULL;
    }

    for (int i = level; i <= MAX_LEVEL; i++) {
        if (freeList[i] != NULL) {
            Block* block = freeList[i];
            freeList[i] = block->next;
            block->isFree = 0;

            while (i > level) {
                i--;
                Block* buddy = (Block*)((char*)block + (MIN_BLOCK_SIZE * (1 << i)));
                buddy->size = MIN_BLOCK_SIZE * (1 << i);
                buddy->isFree = 1;
                buddy->next = freeList[i];
                freeList[i] = buddy;
            }
            return (void*)(block + 1);
        }
    }
    return NULL;
}

void freeMemory(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Block* block = (Block*)ptr - 1;
    int level = getLevel(block->size);

    while (level < MAX_LEVEL) {
        Block* buddy = (Block*)((char*)block ^ (MIN_BLOCK_SIZE * (1 << level)));
        if (buddy->isFree && buddy->size == block->size) {
            Block** current = &freeList[level];
            while (*current != NULL && *current != buddy) {
                current = &(*current)->next;
            }
            if (*current == buddy) {
                *current = buddy->next;
                if (block > buddy) {
                    block = buddy;
                }
                level++;
                block->size *= 2;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    block->isFree = 1;
    block->next = freeList[level];
    freeList[level] = block;
}

int main() {
    initializeMemory();

    void* ptr1 = allocateMemory(100);
    void* ptr2 = allocateMemory(200);
    void* ptr3 = allocateMemory(50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    freeMemory(ptr1);
    freeMemory(ptr2);
    freeMemory(ptr3);

    return 0;
}
11. Implement a Memory Pool Allocator in C
Concept:
A memory pool allocator pre-allocates a large block of memory and manages it internally, providing fixed-size chunks to the application. This reduces the overhead of frequent dynamic memory allocations and deallocations.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 32

typedef struct Block {
    struct Block* next;
} Block;

typedef struct {
    Block* freeList;
    char pool[POOL_SIZE];
} MemoryPool;

void initializePool(MemoryPool* pool) {
    pool->freeList = (Block*)pool->pool;
    Block* current = pool->freeList;
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE - 1; i++) {
        current->next = (Block*)((char*)current + BLOCK_SIZE);
        current = current->next;
    }
    current->next = NULL;
}

void* allocateBlock(MemoryPool* pool) {
    if (pool->freeList == NULL) {
        return NULL;
    }
    Block* block = pool->freeList;
    pool->freeList = block->next;
    return (void*)block;
}

void freeBlock(MemoryPool* pool, void* ptr) {
    Block* block = (Block*)ptr;
    block->next = pool->freeList;
    pool->freeList = block;
}

int main() {
    MemoryPool pool;
    initializePool(&pool);

    void* ptr1 = allocateBlock(&pool);
    void* ptr2 = allocateBlock(&pool);
    void* ptr3 = allocateBlock(&pool);

    printf("Allocated blocks at %p, %p, %p\n", ptr1, ptr2, ptr3);

    freeBlock(&pool, ptr1);
    freeBlock(&pool, ptr2);
    freeBlock(&pool, ptr3);

    return 0;
}
12. Write a Program to Demonstrate Memory-Mapped I/O
Concept:
Memory-m-mapped I/O allows hardware devices to be controlled by reading and writing specific memory addresses. This technique is commonly used in embedded systems to interact with peripherals.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define GPIO_BASE 0x3F200000
#define GPIO_LEN  0xB4

int main() {
    int mem_fd;
    void *gpio_map;

    // Open /dev/mem
    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Map GPIO
    gpio_map = mmap(NULL, GPIO_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
    if (gpio_map == MAP_FAILED) {
        perror("mmap");
        close(mem_fd);
        exit(EXIT_FAILURE);
    }

    // Access GPIO registers
    volatile unsigned *gpio = (volatile unsigned *)gpio_map;
    gpio[10] = 1 << 17; // Set GPIO pin 17

    // Unmap and close
    if (munmap(gpio_map, GPIO_LEN) == -1) {
        perror("munmap");
    }
    close(mem_fd);

    return 0;
}
13. Implement a Simple Garbage Collector in C
Concept:
A garbage collector automatically reclaims memory that is no longer in use by the program. This example demonstrates a simple mark-and-sweep garbage collector.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Object {
    int marked;
    struct Object* next;
} Object;

typedef struct {
    Object* firstObject;
} VM;

VM* newVM() {
    VM* vm = (VM*)malloc(sizeof(VM));
    vm->firstObject = NULL;
    return vm;
}

Object* newObject(VM* vm) {
    Object* object = (Object*)malloc(sizeof(Object));
    object->marked = 0;
    object->next = vm->firstObject;
    vm->firstObject = object;
    return object;
}

void mark(Object* object) {
    if (object->marked) return;
    object->marked = 1;
}

void markAll(VM* vm) {
    Object* object = vm->firstObject;
    while (object) {
        mark(object);
        object = object->next;
    }
}

void sweep(VM* vm) {
    Object** object = &vm->firstObject;
    while (*object) {
        if (!(*object)->marked) {
            Object* unreached = *object;
            *object = unreached->next;
            free(unreached);
        } else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}

void gc(VM* vm) {
    markAll(vm);
    sweep(vm);
}

int main() {
    VM* vm = newVM();

    Object* obj1 = newObject(vm);
    Object* obj2 = newObject(vm);

    gc(vm);

    free(vm);
    return 0;
}
14. Write a Program to Simulate a Page Replacement Algorithm (e.g., LRU, FIFO)
Concept:
Page replacement algorithms decide which memory pages to swap out when a new page needs to be loaded into memory. This example demonstrates the Least Recently Used (LRU) algorithm.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3

typedef struct {
    int page;
    int age;
} Frame;

void lru(int pages[], int numPages) {
    Frame frames[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i].page = -1;
        frames[i].age = 0;
    }

    int pageFaults = 0;
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page == page) {
                frames[j].age = 0;
                found = 1;
                break;
            }
        }

        if (!found) {
            int oldest = 0;
            for (int j = 1; j < FRAME_SIZE; j++) {
                if (frames[j].age > frames[oldest].age) {
                    oldest = j;
                }
            }
            frames[oldest].page = page;
            frames[oldest].age = 0;
            pageFaults++;
        }

       frames[oldest].page = page;
            frames[oldest].age = 0;
            pageFaults++;
        }

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page != -1) {
                frames[j].age++;
            }
        }

        printf("Page %d: ", page);
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j].page != -1) {
                printf("%d ", frames[j].page);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    lru(pages, numPages);

    return 0;
}
15. Implement a Stack-Based Memory Allocator in C
Concept:
A stack-based memory allocator allocates memory in a last-in, first-out (LIFO) manner. This is useful for scenarios where memory allocation and deallocation follow a strict order.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024

typedef struct {
    char stack[STACK_SIZE];
    int top;
} StackAllocator;

void initializeStack(StackAllocator* allocator) {
    allocator->top = 0;
}

void* allocate(StackAllocator* allocator, int size) {
    if (allocator->top + size > STACK_SIZE) {
        return NULL;
    }
    void* ptr = &allocator->stack[allocator->top];
    allocator->top += size;
    return ptr;
}

void deallocate(StackAllocator* allocator, int size) {
    if (allocator->top - size < 0) {
        return;
    }
    allocator->top -= size;
}

int main() {
    StackAllocator allocator;
    initializeStack(&allocator);

    void* ptr1 = allocate(&allocator, 100);
    void* ptr2 = allocate(&allocator, 200);
    void* ptr3 = allocate(&allocator, 50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    deallocate(&allocator, 50);
    deallocate(&allocator, 200);
    deallocate(&allocator, 100);

    return 0;
}
16. Write a Program to Demonstrate the Use of Virtual Memory
Concept:
Virtual memory allows a computer to compensate for physical memory shortages by temporarily transferring data from random access memory (RAM) to disk storage. This example demonstrates a simple virtual memory system.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define NUM_PAGES 4
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)

typedef struct {
    int pageTable[NUM_PAGES];
    char memory[MEMORY_SIZE];
} VirtualMemory;

void initializeMemory(VirtualMemory* vm) {
    for (int i = 0; i < NUM_PAGES; i++) {
        vm->pageTable[i] = -1;
    }
}

int allocatePage(VirtualMemory* vm, int pageNumber) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (vm->pageTable[i] == -1) {
            vm->pageTable[i] = pageNumber;
            return i;
        }
    }
    return -1;
}

void writeMemory(VirtualMemory* vm, int pageNumber, int offset, char value) {
    int frameNumber = allocatePage(vm, pageNumber);
    if (frameNumber == -1) {
        printf("Memory full\n");
        return;
    }
    vm->memory[frameNumber * PAGE_SIZE + offset] = value;
}

char readMemory(VirtualMemory* vm, int pageNumber, int offset) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (vm->pageTable[i] == pageNumber) {
            return vm->memory[i * PAGE_SIZE + offset];
        }
    }
    printf("Page not found\n");
    return -1;
}

int main() {
    VirtualMemory vm;
    initializeMemory(&vm);

    writeMemory(&vm, 1, 0, 'A');
    writeMemory(&vm, 2, 1, 'B');
    writeMemory(&vm, 3, 2, 'C');

    printf("Read memory: %c %```c
    printf("Read memory: %c %c %c\n", readMemory(&vm, 1, 0), readMemory(&vm, 2, 1), readMemory(&vm, 3, 2));

    return 0;
}
17. Implement a Simple Memory Leak Detector in C
Concept:
A memory leak detector helps identify memory that has been allocated but not freed. This example demonstrates a simple memory leak detector using a linked list to track allocations.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Allocation {
    void* ptr;
    size_t size;
    struct Allocation* next;
} Allocation;

Allocation* head = NULL;

void* myMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        Allocation* newAlloc = (Allocation*)malloc(sizeof(Allocation));
        newAlloc->ptr = ptr;
        newAlloc->size = size;
        newAlloc->next = head;
        head = newAlloc;
    }
    return ptr;
}

void myFree(void* ptr) {
    Allocation** current = &head;
    while (*current) {
        if ((*current)->ptr == ptr) {
            Allocation* toFree = *current;
            *current = (*current)->next;
            free(toFree);
            break;
        }
        current = &(*current)->next;
    }
    free(ptr);
}

void checkForLeaks() {
    Allocation* current = head;
    while (current) {
        printf("Memory leak detected: %p (%zu bytes)\n", current->ptr, current->size);
        current = current->next;
    }
}

int main() {
    char* ptr1 = (char*)myMalloc(100);
    int* ptr2 = (int*)myMalloc(200);
    float* ptr3 = (float*)myMalloc(50);

    myFree(ptr1);
    myFree(ptr2);

    checkForLeaks();

    myFree(ptr3);

    return 0;
}
18. Write a Program to Simulate a Simple Paging System
Concept:
A paging system divides memory into fixed-size pages and maps them to physical memory frames. This example demonstrates a simple paging system with a page table.

Code:
c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define NUM_PAGES 4
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)

typedef struct {
    int pageTable[NUM_PAGES];
    char memory[MEMORY_SIZE];
} PagingSystem;

void initializePagingSystem(PagingSystem* ps) {
    for (int i = 0; i < NUM_PAGES; i++) {
        ps->pageTable[i] = -1;
    }
}

int allocatePage(PagingSystem* ps, int pageNumber) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (ps->pageTable[i] == -1) {
            ps->pageTable[i] = pageNumber;
            return i;
        }
    }
    return -1;
}

void writeMemory(PagingSystem* ps, int pageNumber, int offset, char value) {
    int frameNumber = allocatePage(ps, pageNumber);
    if (frameNumber == -1) {
        printf("Memory full\n");
        return;
    }
    ps->memory[frameNumber * PAGE_SIZE + offset] = value;
}

char readMemory(PagingSystem* ps, int pageNumber, int offset) {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (ps->pageTable[i] == pageNumber) {
            return ps->memory[i * PAGE_SIZE + offset];
        }
    }
    printf("Page not found\n");
    return -1;
}

int main() {
    PagingSystem ps;
    initializePagingSystem(&ps);

    writeMemory(&ps, 1, 0, 'A');
    writeMemory(&ps, 2, 1, 'B');
    writeMemory(&ps, 3, 2, 'C');

    printf("Read memory: %c %c %c\n", readMemory(&ps, 1, 0), readMemory(&ps, 2, 1), readMemory(&ps, 3, 2));

    return 0;
}
19. Implement a Dynamic Memory Allocator Using a Free List
Concept:
A dynamic memory allocator manages memory allocation and deallocation using a free list to keep track of free memory blocks. This example demonstrates a simple dynamic memory allocator.

Code:
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    struct Block* next;
```c
    struct Block* next;
} Block;

Block* freeList = NULL;

void* myMalloc(size_t size) {
    Block* current = freeList;
    Block* previous = NULL;

    while (current) {
        if (current->size >= size) {
            if (previous) {
                previous->next = current->next;
            } else {
                freeList = current->next;
            }
            return (void*)(current + 1);
        }
        previous = current;
        current = current->next;
    }

    Block* newBlock = (Block*)malloc(sizeof(Block) + size);
    newBlock->size = size;
    return (void*)(newBlock + 1);
}

void myFree(void* ptr) {
    if (!ptr) return;

    Block* block = (Block*)ptr - 1;
    block->next = freeList;
    freeList = block;
}

int main() {
    char* ptr1 = (char*)myMalloc(100);
    int* ptr2 = (int*)myMalloc(200);
    float* ptr3 = (float*)myMalloc(50);

    printf("Allocated memory at %p, %p, %p\n", ptr1, ptr2, ptr3);

    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);

    return 0;
}
20. Write a Program to Demonstrate the Use of Shared Memory for IPC
Concept:
Shared memory allows multiple processes to access the same memory segment, enabling fast inter-process communication (IPC). This example demonstrates how to use shared memory for IPC.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char* str = (char*)shmat(shmid, (void*)0, 0);

    printf("Write Data: ");
    fgets(str, SHM_SIZE, stdin);

    printf("Data written in memory: %s\n", str);

    shmdt(str);

    return 0;
}
21. Implement a Software Timer in C
Concept:
A software timer is a timer implemented in software, typically using a hardware timer or system clock to keep track of elapsed time. This example demonstrates a simple software timer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    static int count = 0;
    printf("Timer expired %d times\n", ++count);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
22. Write a Program to Demonstrate the Use of a Watchdog Timer
Concept:
A watchdog timer is a hardware timer that resets the system if the software fails to reset the timer within a specified interval. This example demonstrates a simple watchdog timer.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void watchdogHandler(int signum) {
    printf("Watchdog timer expired! Resetting system...\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &watchdogHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        printf("Resetting watchdog timer...\n");
        timer.it_value.tv_sec = 5;
        setitimer(ITIMER_REAL, &timer, NULL);
        sleep(3);
    }

    return 0;
}
23. Implement a Simple Real-Time### 23. Implement a Simple Real-Time Clock in C
Concept:
A real-time clock (RTC) keeps track of the current time and date. This example demonstrates a simple RTC using the system clock.

Code:
c
#include <stdio.h>
#include <time.h>

void printCurrentTime() {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("Current local time and date: %s", asctime(timeinfo));
}

int main() {
    while (1) {
        printCurrentTime();
        sleep(1);
    }
    return 0;
}
24. Write a Program to Measure Memory Utilization in an Embedded System
Concept:
Measuring memory utilization involves tracking the amount of memory used by the program. This example demonstrates a simple way to measure memory utilization.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory usage: %ld KB\n", usage.ru_maxrss);
}

int main() {
    char* ptr1 = (char*)malloc(100 * 1024);
    char* ptr2 = (char*)malloc(200 * 1024);

    printMemoryUsage();

    free(ptr1);
    free(ptr2);

    printMemoryUsage();

    return 0;
}
25. Implement a Simple Task Scheduler with Timer Interrupts
Concept:
A task scheduler manages the execution of multiple tasks based on timer interrupts. This example demonstrates a simple task scheduler using timer interrupts.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        task1();
    } else {
        task2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
26. Write a Program to Demonstrate the Use of Hardware Timers
Concept:
Hardware timers are used to generate precise time delays and periodic interrupts. This example demonstrates the use of hardware timers in an embedded system.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    printf("Hardware timer interrupt\n");
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
27. Implement a Simple Delay Function Using Busy-Waiting
Concept:
A delay function introduces a time delay in the program execution. This example demonstrates a simple delay function using busy-waiting.

Code:
c
#include <stdio.h>
#include <time.h>

void delay(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}

int main() {
    printf("Starting delay...\n");
    delay(1000); // 1 second delay
    printf("Delay finished\n");
    return 0;
}
28. Write a Program to Simulate a Timer-Based Event Scheduler
Concept:
A timer-based event scheduler triggers events at specified intervals. This example demonstrates a simpletimer-based event scheduler.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void event1() {
    printf("Event 1 triggered\n");
}

void event2() {
    printf("Event 2 triggered\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        event1();
    } else {
        event2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
29. Implement a Simple Time-Sharing System in C
Concept:
A time-sharing system allows multiple tasks to share CPU time by switching between them at regular intervals. This example demonstrates a simple time-sharing system.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

void timerHandler(int signum) {
    static int count = 0;
    if (count % 2 == 0) {
        task1();
    } else {
        task2();
    }
    count++;
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}
30. Write a Program to Demonstrate the Use of High-Resolution Timers
Concept:
High-resolution timers provide precise timing for applications that require accurate time measurements. This example demonstrates the use of high-resolution timers.

Code:
c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timerHandler(int signum) {
    printf("High-resolution timer interrupt\n");
}

int main() {
    struct sigaction sa;
    struct itimerspec timerSpec;
    timer_t timerID;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timerHandler;
    sigaction(SIGRTMIN, &sa, NULL);

    timerSpec.it_value.tv_sec = 0;
    timerSpec.it_value.tv_nsec = 500000000; // 500 ms
    timerSpec.it_interval.tv_sec = 0;
    timerSpec.it_interval.tv_nsec = 500000000; // 500 ms

    timer_create(CLOCK_REALTIME, NULL, &timerID);
    timer_settime(timerID, 0, &timerSpec, NULL);

    while (1) {
        pause();
    }

    return 0;
}
These examples cover a wide range of topics relevant to embedded systems engineering, including OS internals, process/thread synchronization, memory layout and access, timers, and memory utilization. Each example provides a working C program to help you understand the concepts and prepare for coding interviews. If you need further explanations or additional examples, feel free to ask!


Thread synchornization apis:
1. accessing hall with 10Guest capacity
2. producer - consumer problme with 2 producer and 2 consumer
3. strict alternation
4. listerner threads // server threads
5. write a program to print odd and even number by 2 threads. (zero semaphore to avoid race condition)
https://www.youtube.com/watch?v=AD3EylLiI7U&list=PLTjcBkvRBqGGbSckyAGLTy05sbPPl6dJA&index=36
https://www.youtube.com/watch?v=Ognzlifblsc&list=PLTjcBkvRBqGGbSckyAGLTy05sbPPl6dJA&index=42
