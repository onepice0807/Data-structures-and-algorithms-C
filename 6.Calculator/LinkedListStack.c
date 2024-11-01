#include "LinkedListStack.h"

// 스택 생성 함수
void LLS_CreateStack(LinkedListStack** Stack) {
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); // 스택을 동적 할당
    (*Stack)->List = NULL;  // 리스트 초기화
    (*Stack)->Top = NULL;   // Top 초기화
}

// 스택 해제 함수
void LLS_DestroyStack(LinkedListStack* Stack) {
    while (!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack); // 스택에서 노드 제거
        LLS_DestroyNode(Popped);       // 제거된 노드 해제
    }
    free(Stack); // 스택 구조체 자체를 동적 메모리에서 해제
}

// 새로운 노드를 생성하는 함수
Node* LLS_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // 노드 메모리 할당
    NewNode->Data = (char*)malloc(strlen(NewData) + 1); // 데이터 메모리 할당
    strcpy(NewNode->Data, NewData);  // 데이터를 저장
    NewNode->NextNode = NULL; // 다음 노드 포인터 초기화
    return NewNode;
}

// 노드를 소멸시키는 함수
void LLS_DestroyNode(Node* _Node) {
    free(_Node->Data); // 데이터 메모리 해제
    free(_Node);       // 노드 메모리 해제
}

// 스택에 데이터 추가 (Push)
void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
    if (Stack->List == NULL) {
        Stack->List = NewNode; // 스택이 비어있다면 새로운 노드를 첫 노드로 설정
    }
    else {
        Stack->Top->NextNode = NewNode; // 기존의 Top 뒤에 새로운 노드를 연결
    }
    Stack->Top = NewNode; // Top을 새 노드로 갱신
}

// 스택에서 데이터 제거 (Pop)
Node* LLS_Pop(LinkedListStack* Stack) {
    Node* TopNode = Stack->Top; // 최상위 노드를 임시로 저장
    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else {
        Node* CurrentTop = Stack->List;
        while (CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }
        Stack->Top = CurrentTop; // 새로운 Top을 설정
        Stack->Top->NextNode = NULL;
    }
    return TopNode; // 제거된 노드를 반환
}

// 스택의 최상단 데이터 확인
Node* LLS_Top(LinkedListStack* Stack) {
    return Stack->Top; // Top 노드 반환
}

// 스택의 크기 반환
int LLS_GetSize(LinkedListStack* Stack) {
    int Count = 0;
    Node* Current = Stack->List;
    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

// 스택이 비어있는지 확인
int LLS_IsEmpty(LinkedListStack* Stack) {
    return (Stack->List == NULL); // 리스트가 NULL이면 스택이 비어있음
}