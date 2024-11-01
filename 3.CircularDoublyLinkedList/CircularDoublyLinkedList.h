#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의
typedef struct tagNode {
    ElementType Data; // 노드가 저장하는 데이터
    struct tagNode* PrevNode; // 이전 노드를 가리키는 포인터
    struct tagNode* NextNode; // 다음 노드를 가리키는 포인터
} Node;

// 함수 원형 선언
Node* CDLL_CreateNode(ElementType NewData); // 새로운 노드를 생성하는 함수
void  CDLL_DestroyNode(Node* Node); // 노드를 메모리에서 해제하는 함수
void  CDLL_AppendNode(Node** Head, Node* NewNode); // 리스트의 끝에 노드를 추가하는 함수
void  CDLL_InsertAfter(Node* Current, Node* NewNode); // 지정된 노드 뒤에 새 노드를 삽입하는 함수
void  CDLL_RemoveNode(Node** Head, Node* Remove); // 리스트에서 지정된 노드를 삭제하는 함수
Node* CDLL_GetNodeAt(Node* Head, int Location); // 리스트에서 특정 위치의 노드를 반환하는 함수
int   CDLL_GetNodeCount(Node* Head); // 리스트의 모든 노드 개수를 반환하는 함수

#endif