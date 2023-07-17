#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;

void push(Stack* stack, int item);
int pop(Stack* stack);
void display(Stack* stack);
void log_push(FILE* log_file, int item);
void log_pop(FILE* log_file, int item);
void log_operation(FILE* log_file, const char* operation);

int main() {
    srand(time(NULL));

    FILE* push_log_file = fopen("push_log.txt", "w");
    FILE* pop_log_file = fopen("pop_log.txt", "w");
    FILE* operation_log_file = fopen("operation_log.txt", "w");

    Stack stack;
    stack.top = -1;

    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 100;
        if (random_num < 50) {
            push(&stack, random_num);
            log_push(push_log_file, random_num);
        } else {
            int popped_item = pop(&stack);
            log_pop(pop_log_file, popped_item);
        }
        display(&stack);
        log_operation(operation_log_file, (random_num < 50) ? "push" : "pop");
    }

    fclose(push_log_file);
    fclose(pop_log_file);
    fclose(operation_log_file);

    return 0;
}

void push(Stack* stack, int item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Error: stack is full\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        //printf("Error: stack is empty\n");
        return -1;
    }
    int popped_item = stack->items[stack->top];
    stack->top--;
    return popped_item;
}

void display(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

void log_push(FILE* log_file, int item) {
    fprintf(log_file, "push %d\n", item);
}

void log_pop(FILE* log_file, int item) {
    fprintf(log_file, "pop %d\n", item);
}

void log_operation(FILE* log_file, const char* operation) {
    fprintf(log_file, "%s\n", operation);
}

