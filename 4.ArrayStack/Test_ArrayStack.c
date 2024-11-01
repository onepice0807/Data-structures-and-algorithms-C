#include "ArrayStack.h"

// 스택 생성 함수
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    // 스택을 동적 메모리 할당
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    // 입력된 용량만큼 노드 배열을 동적 할당
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

    // 스택의 용량 및 Top 초기화
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

// 스택 해제 함수
void AS_DestroyStack(ArrayStack* Stack) {
    // 스택의 노드 배열을 동적 메모리에서 해제
    free(Stack->Nodes);

    // 스택 구조체를 동적 메모리에서 해제
    free(Stack);
}

// 스택에 데이터 추가 (Push)
void AS_Push(ArrayStack* Stack, ElementType Data) {
    Stack->Top++; // Top 위치를 증가
    Stack->Nodes[Stack->Top].Data = Data; // 데이터 저장
}

// 스택에서 데이터 제거 (Pop)
ElementType AS_Pop(ArrayStack* Stack) {
    int Position = Stack->Top--; // 현재 Top 위치 저장 후 감소
    return Stack->Nodes[Position].Data; // 제거된 데이터 반환
}

// 스택의 최상위 데이터 확인 (Top)
ElementType AS_Top(ArrayStack* Stack) {
    return Stack->Nodes[Stack->Top].Data; // 최상위 데이터 반환
}

// 현재 스택 크기 반환
int AS_GetSize(ArrayStack* Stack) {
    return Stack->Top + 1; // Top 인덱스 + 1이 스택의 실제 크기
}

// 스택이 비어있는지 확인
int AS_IsEmpty(ArrayStack* Stack) {
    return (Stack->Top == -1); // Top이 -1이면 스택이 비어있음
}

#include "ArrayStack.h"
#include <stdio.h>

int main(void) {
    int i = 0;
    ArrayStack* Stack = NULL;

    // 용량이 50인 스택 생성
    AS_CreateStack(&Stack, 50);

    // 스택을 용량만큼 채우기
    while (i < Stack->Capacity) {
        AS_Push(Stack, i + 1); // 1부터 50까지 추가
        i++;
    }

    // 스택의 상태 출력
    printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    // 스택이 비어있을 때까지 pop하고 각 값을 출력
    while (!AS_IsEmpty(Stack)) {
        printf("Popped: %d", AS_Pop(Stack));

        if (!AS_IsEmpty(Stack))
            printf(" Current Top: %d\n", AS_Top(Stack));
        else
            printf(" Stack Is Empty.\n");
    }

    // 스택 해제
    AS_DestroyStack(Stack);

    return 0;
}