#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의
typedef struct tagNode
{
	ElementType Data; // 노드가 저장하는 데이터
	struct tagNode* NextNode; // 다음 노드에 대한 포인터
} Node;

// 함수 원형 선언
Node* SLL_CreateNode(ElementType NewData); // 새로운 노드를 생성하는 함수
void  SLL_DestroyNode(Node* Node);         // 노드를 해제하는 함수
void  SLL_AppendNode(Node** Head, Node* NewNode); // 리스트 끝에 노드를 추가하는 함수
void  SLL_InsertAfter(Node* Current, Node* NewNode); // 특정 노드 뒤에 새 노드를 삽입하는 함수
void  SLL_InsertNewHead(Node** Head, Node* NewHead); // 리스트의 시작 부분에 새 노드를 삽입하는 함수
void  SLL_RemoveNode(Node** Head, Node* Remove); // 특정 노드를 리스트에서 삭제하는 함수
Node* SLL_GetNodeAt(Node* Head, int Location); // 지정된 위치의 노드를 반환하는 함수
int   SLL_GetNodeCount(Node* Head); // 리스트의 노드 개수를 세는 함수

#endif