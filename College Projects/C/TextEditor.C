#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 300

char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

char pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW ERROR\n");
        return '\0';
    }
    printf("\n\nDELETED CHAR: %c\n", stack[top][0]);
    return stack[top--][0];
}

void push(char input[]) {
    if (top == MAX_SIZE-1) {
        printf("STACK OVERFLOW ERROR\n");
        return;
    }
    strcpy(stack[++top], input);
}

void display() {
    int temp = 0;
    if (top == -1) {
        printf("STACK IS EMPTY\n");
        return;
    }
    while (temp <= top) {
        printf("%s", stack[temp++]);
        if (temp <= top) {
            printf(" ");
        }
    }
}

void menu() {
    printf("\n///////////////TEXT EDITOR 2023///////////////\n");
    printf("/////PRESS 9 TO DISPLAY \n");
    printf("/////PRESS 0 TO EXIT\n");
    printf("\n");
}

int main() {
    char input[MAX_SIZE];
    int choice = 1;

    do {
        menu();
        fgets(input, MAX_SIZE, stdin);
        if (strcmp(input, "undo\n") == 0) {
            pop();
        } else if (strcmp(input, "9\n") == 0) {
            display();
        } else if (strcmp(input, "0\n") != 0) {
            push(input);
        }
    } while (strcmp(input, "0\n") != 0);

    return 0;
}
