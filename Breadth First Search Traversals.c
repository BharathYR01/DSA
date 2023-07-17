#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue data structure
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph representation using adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

// Queue operations
void enqueue(Queue* queue, int vertex) {
    queue->rear++;
    queue->items[queue->rear] = vertex;
}

int dequeue(Queue* queue) {
    int item = queue->items[queue->front];
    queue->front++;
    return item;
}

bool isQueueEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

// BFS traversal function
void BFS(int startVertex, int numVertices) {
    Queue queue;
    queue.front = 0;
    queue.rear = -1;

    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
}

int main() {
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal: ");
    BFS(startVertex, numVertices);

    return 0;
}
