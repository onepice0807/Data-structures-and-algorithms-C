#pragma once

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드의 데이터 타입
typedef char ElementType;

// 수식 트리 노드 구조체 정의
typedef struct tagETNode {
    struct tagETNode* Left;  // 왼쪽 자식 노드를 가리키는 포인터
    struct tagETNode* Right; // 오른쪽 자식 노드를 가리키는 포인터
    ElementType Data; // 노드에 저장된 데이터 (연산자 또는 피연산자)
} ETNode;

// 함수 원형 선언
ETNode* ET_CreateNode(ElementType NewData); // 노드 생성 함수
void ET_DestroyNode(ETNode* Node); // 노드 소멸 함수
void ET_DestroyTree(ETNode* Root); // 트리 전체 소멸 함수
void ET_PreorderPrintTree(ETNode* Node); // 전위 순회 출력 함수
void ET_InorderPrintTree(ETNode* Node); // 중위 순회 출력 함수
void ET_PostorderPrintTree(ETNode* Node); // 후위 순회 출력 함수
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node); // 후위 표기식으로 수식 트리 생성
double ET_Evaluate(ETNode* Tree);  // 수식 트리 평가 함수

#endif