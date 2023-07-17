#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

FILE *enquelog, *dequelog, *operationlog;

int main() {
    srand(time(NULL));
    Queue queue;
    initializeQueue(&queue);

    FILE *enquelog, *dequelog, *operationlog;
    enquelog = fopen("enquelog.txt", "w");
    dequelog = fopen("dequelog.txt", "w");
    operationlog = fopen("operationlog.txt", "w");

    for (int i = 0; i < MAX_SIZE; i++) {
        int randomNumber = rand() % 100;
        enqueue(&queue, randomNumber);
    }

    displayQueue(queue);

    char operation;
    printf("Enter operation (E for enqueue, D for dequeue): ");
    scanf("%c", &operation);

    while (operation == 'E' || operation == 'D') {
        if (operation == 'E') {
            int item;
            printf("Enter item to enqueue: ");
            scanf("%d", &item);
            enqueue(&queue, item);
        } else {
            dequeue(&queue);
        }

        displayQueue(queue);

        printf("Enter operation (E for enqueue, D for dequeue): ");
        scanf(" %c", &operation);
    }

    fclose(enquelog);
    fclose(dequelog);
    fclose(operationlog);

    return 0;
}


void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue queue) {
    return queue.rear == MAX_SIZE - 1;
}

int isEmpty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue* queue, int item)
{
    if (isFull(*queue))
    {
        printf("Queue is full\n");
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->item[queue->rear] = item;
        fprintf(enquelog, "Enqueued item: %d\n", item);
    }
}

int dequeue(Queue* queue) {
    int dequeuedItem = -1;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        dequeuedItem = queue->items[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        fprintf(dequelog, "Dequeued item: %d\n", dequeuedItem);
    }
    return dequeuedItem;
}


void displayQueue(Queue queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");

    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
    }

    printf("\n");
}

