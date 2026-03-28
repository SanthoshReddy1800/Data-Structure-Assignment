#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

// Enqueue function
void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], doc);

    printf("Document added to queue\n");
}

// Dequeue function
void dequeue() {
    if (front == -1 || front > rear) {
        printf("No documents to print\n");
        return;
    }

    printf("Printing: %s\n", queue[front]);
    front++;
}

// Display function
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Pending Documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    while (1) {
        printf("\n1. Add Document\n2. Print Document\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                fgets(doc, 50, stdin);
                doc[strcspn(doc, "\n")] = '\0';  // remove newline
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}