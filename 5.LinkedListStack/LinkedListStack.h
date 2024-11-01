#pragma once

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct tagNode {
    char* Data; // 노드가 저장하는 문자열 데이터
    struct tagNode* NextNode; // 다음 노드를 가리키는 포인터
    struct tagNode* PrevNode; // 이전 노드를 가리키는 포인터
} Node;

// 연결 리스트 스택 구조체 정의
typedef struct tagLinkedListStack {
    int Count; // 스택 내 노드 개수
    Node* List; // 스택의 첫 번째 노드를 가리키는 포인터
    Node* Top; // 스택의 최상단 노드를 가리키는 포인터
} LinkedListStack;

// 함수 원형 선언
void LLS_CreateStack(LinkedListStack** Stack); // 스택 생성 함수
void LLS_DestroyStack(LinkedListStack* Stack); // 스택 해제 함수
Node* LLS_CreateNode(char* Data); // 새로운 노드 생성 함수
void LLS_DestroyNode(Node* _Node); // 노드 해제 함수
void LLS_Push(LinkedListStack* Stack, Node* NewNode); // 스택에 데이터 추가
Node* LLS_Pop(LinkedListStack* Stack); // 스택에서 데이터 제거
Node* LLS_Top(LinkedListStack* Stack); // 스택 최상단 데이터 반환
int LLS_GetSize(LinkedListStack* Stack); // 스택 크기 반환
int LLS_IsEmpty(LinkedListStack* Stack); // 스택이 비어있는지 확인

#endif