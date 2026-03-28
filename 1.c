#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
char pop() {
    return stack[top--];
}

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Push all characters into stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    printf("Reversed string: ");

    // Pop all characters from stack
    for (int i = 0; i < len; i++) {
        printf("%c", pop());
    }

    return 0;
}