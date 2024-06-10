#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;  // int를 element 자료형으로 바꿔 부름.
element stack[MAX_STACK_SIZE];  // 1차원 배열
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item)
{
    if (is_full()) {
        printf("스택 포화 에러\n");
        exit(1);
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty()) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}