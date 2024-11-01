#include "CircularDoublyLinkedList.h"

// 새로운 노드를 생성하고 초기화하는 함수
Node* CDLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // 메모리 할당
    NewNode->Data = NewData; // 데이터 초기화
    NewNode->PrevNode = NULL; // 이전 노드 포인터 초기화
    NewNode->NextNode = NULL; // 다음 노드 포인터 초기화
    return NewNode;
}

// 노드를 소멸시키는 함수
void CDLL_DestroyNode(Node* Node) {
    free(Node); // 메모리 해제
}

// 리스트의 끝에 새 노드를 추가하는 함수
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    if (*Head == NULL) {
        // 리스트가 비어있으면 새로운 노드를 헤드로 설정하고 순환 연결
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else {
        // 기존의 테일(마지막 노드) 뒤에 새로운 노드를 추가하고 순환 연결
        Node* Tail = (*Head)->PrevNode;
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
        NewNode->NextNode = *Head;
        (*Head)->PrevNode = NewNode;
    }
}

// 특정 노드 뒤에 새 노드를 삽입하는 함수
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode; // 새 노드의 다음을 현재 노드의 다음으로 설정
    NewNode->PrevNode = Current; // 새 노드의 이전을 현재 노드로 설정
    Current->NextNode->PrevNode = NewNode; // 다음 노드의 이전을 새 노드로 설정
    Current->NextNode = NewNode; // 현재 노드의 다음을 새 노드로 설정
}

// 리스트에서 특정 노드를 삭제하는 함수
void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        // 삭제할 노드가 헤드인 경우
        *Head = Remove->NextNode;
        if (*Head != Remove) {
            // 리스트에 노드가 여러 개일 때 연결 업데이트
            (*Head)->PrevNode = Remove->PrevNode;
            Remove->PrevNode->NextNode = *Head;
        }
        else {
            // 리스트에 단일 노드만 있던 경우
            *Head = NULL;
        }
    }
    else {
        // 중간 또는 마지막 노드를 삭제하는 경우
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}

// 특정 위치의 노드를 반환하는 함수
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while (Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

// 리스트의 모든 노드 개수를 세는 함수
int CDLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;
    do {
        Current = Current->NextNode;
        Count++;
    } while (Current != Head);
    return Count;
}

// 특정 노드의 데이터와 양쪽 노드의 데이터 출력
void PrintNode(Node* _Node) {
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL ");
    else
        printf("Prev: %d ", _Node->PrevNode->Data);

    printf("Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}
