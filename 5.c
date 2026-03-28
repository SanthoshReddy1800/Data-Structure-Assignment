#include <stdio.h>

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    cq[rear] = value;

    printf("Inserted: %d\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Removed: %d\n", cq[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Peek
void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element: %d\n", cq[front]);
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements:\n");
    int i = front;

    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}