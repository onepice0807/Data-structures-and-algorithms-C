#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

// 스택 생성 함수
void LLS_CreateStack(LinkedListStack** Stack) {
    // 스택을 동적 메모리 할당
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL; // 리스트 초기화
    (*Stack)->Top = NULL; // Top 초기화
    (*Stack)->Count = 0; // 노드 개수 초기화
}

// 스택 해제 함수
void LLS_DestroyStack(LinkedListStack* Stack) {
    // 스택이 비어있을 때까지 노드를 pop하고 메모리 해제
    while (!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack); // 스택 구조체 자체를 동적 메모리에서 해제
}

// 새로운 노드를 생성하는 함수
Node* LLS_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // 노드 메모리 할당
    NewNode->Data = (char*)malloc(strlen(NewData) + 1); // 데이터 메모리 할당

    strcpy_s(NewNode->Data, strlen(NewData) + 1, NewData); // 데이터를 저장
    NewNode->NextNode = NULL; // 다음 노드 포인터 초기화
    NewNode->PrevNode = NULL; // 이전 노드 포인터 초기화
    return NewNode;
}

// 노드를 소멸시키는 함수
void LLS_DestroyNode(Node* _Node) {
    free(_Node->Data); // 데이터 메모리 해제
    free(_Node); // 노드 메모리 해제
}

// 스택에 데이터 추가 (Push)
void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
    if (Stack->List == NULL) {
        // 스택이 비어있다면 새로운 노드를 첫 노드로 설정
        Stack->List = NewNode;
    }
    else {
        // 기존의 Top 뒤에 새로운 노드를 연결
        Stack->Top->NextNode = NewNode;
        NewNode->PrevNode = Stack->Top;
    }
    Stack->Top = NewNode; // Top을 새 노드로 갱신
    Stack->Count++; // 노드 개수 증가
}

// 스택에서 데이터 제거 (Pop)
Node* LLS_Pop(LinkedListStack* Stack) {
    Node* TopNode = Stack->Top; // 최상위 노드를 임시로 저장
    if (Stack->List == Stack->Top) {
        // 스택에 노드가 하나뿐인 경우
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else {
        // 두 번째 노드를 새로운 Top으로 설정
        Stack->Top = TopNode->PrevNode;
        Stack->Top->NextNode = NULL;
    }
    Stack->Count--; // 노드 개수 감소
    return TopNode; // 제거된 노드를 반환
}

// 스택의 최상단 데이터 확인
Node* LLS_Top(LinkedListStack* Stack) {
    return Stack->Top; // Top 노드 반환
}

// 현재 스택 크기 반환
int LLS_GetSize(LinkedListStack* Stack) {
    return Stack->Count; // 노드 개수 반환
}

// 스택이 비어있는지 확인
int LLS_IsEmpty(LinkedListStack* Stack) {
    return (Stack->List == NULL); // 리스트가 NULL이면 스택이 비어있음
}