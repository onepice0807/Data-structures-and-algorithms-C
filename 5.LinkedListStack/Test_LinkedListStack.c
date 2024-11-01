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

    // 스택 생성
    LLS_CreateStack(&Stack);

    startTime = (double)clock() / CLOCKS_PER_SEC;

    // 스택에 데이터 추가
    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("efg"));
    LLS_Push(Stack, LLS_CreateNode("hij"));

    // 10000개의 노드 추가
    for (int i = 0; i < 10000; i++) {
        sprintf(buff, "monster_%d", i);
        LLS_Push(Stack, LLS_CreateNode(buff));
    }

    // 스택의 크기와 최상단 데이터 출력
    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n", Count, LLS_Top(Stack)->Data);

    // 스택에서 데이터를 pop하고 출력
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

    // 스택 해제
    LLS_DestroyStack(Stack);
    endTime = (double)clock() / CLOCKS_PER_SEC;

    printf("소요시간: %lf\n", (endTime - startTime));

    return 0;
}