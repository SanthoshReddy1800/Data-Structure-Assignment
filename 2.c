#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
void pop() {
    top--;
}

int main() {
    char exp[100];

    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++) {
        // If opening parenthesis, push
        if (exp[i] == '(') {
            push(exp[i]);
        }
        // If closing parenthesis
        else if (exp[i] == ')') {
            if (top == -1) {
                printf("Not Balanced\n");
                return 0;
            }
            pop();
        }
    }

    // Final check
    if (top == -1) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}