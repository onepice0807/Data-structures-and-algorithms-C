#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"
#include <time.h>

int main(void) {
    double startTime, endTime;
    char buff[50];
    int i = 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;

    // ���� ����
    LLS_CreateStack(&Stack);

    startTime = (double)clock() / CLOCKS_PER_SEC;

    // ���ÿ� ������ �߰�
    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("efg"));
    LLS_Push(Stack, LLS_CreateNode("hij"));

    // 10000���� ��� �߰�
    for (int i = 0; i < 10000; i++) {
        sprintf(buff, "monster_%d", i);
        LLS_Push(Stack, LLS_CreateNode(buff));
    }

    // ������ ũ��� �ֻ�� ������ ���
    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n", Count, LLS_Top(Stack)->Data);

    // ���ÿ��� �����͸� pop�ϰ� ���
    for (i = 0; i < Count; i++) {
        if (LLS_IsEmpty(Stack))
            break;

        Popped = LLS_Pop(Stack);
        printf("Popped: %s, ", Popped->Data);
        LLS_DestroyNode(Popped);

        if (!LLS_IsEmpty(Stack)) {
            printf("Current Top: %s\n", LLS_Top(Stack)->Data);
        }
        else {
            printf("Stack Is Empty.\n");
        }
    }

    // ���� ����
    LLS_DestroyStack(Stack);
    endTime = (double)clock() / CLOCKS_PER_SEC;

    printf("�ҿ�ð�: %lf\n", (endTime - startTime));

    return 0;
}