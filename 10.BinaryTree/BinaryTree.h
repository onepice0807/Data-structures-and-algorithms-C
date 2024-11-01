#pragma once

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 노드의 데이터 타입
typedef char ElementType;

// 이진 트리 노드 구조체 정의
typedef struct tagSBTNode {
    struct tagSBTNode* Left; // 왼쪽 자식 노드를 가리키는 포인터
    struct tagSBTNode* Right; // 오른쪽 자식 노드를 가리키는 포인터
    ElementType Data; // 노드에 저장된 데이터
} SBTNode;

// 함수 원형 선언
SBTNode* SBT_CreateNode(ElementType NewData); // 노드 생성 함수
void SBT_DestroyNode(SBTNode* Node); // 노드 소멸 함수
void SBT_DestroyTree(SBTNode* Root); // 트리 전체 소멸 함수
void SBT_PreorderPrintTree(SBTNode* Node); // 전위 순회 출력 함수
void SBT_InorderPrintTree(SBTNode* Node); // 중위 순회 출력 함수
void SBT_PostorderPrintTree(SBTNode* Node); // 후위 순회 출력 함수

#endif // ! BINARY_TREE_H