#pragma once

#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 노드의 데이터 타입
typedef char ElementType;

// LCRS 트리 노드 구조체 정의
typedef struct tagLCRSNode {
    struct tagLCRSNode* LeftChild; // 자식 노드를 가리키는 포인터
    struct tagLCRSNode* RightSilbling; // 형제 노드를 가리키는 포인터
    ElementType Data; // 노드가 저장하는 데이터
} LCRSNode;

// 함수 원형 선언
LCRSNode* LCRS_CreateNode(ElementType NewData); // 노드 생성 함수
void LCRS_DestroyNode(LCRSNode* Node); // 노드 해제 함수
void LCRS_DestroyTree(LCRSNode* Root); // 트리 전체 해제 함수
void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode); // 자식 노드 추가 함수
void LCRS_PrintTree(LCRSNode* Node, int Depth); // 트리 출력 함수

#endif // !LCRS_TREE_H