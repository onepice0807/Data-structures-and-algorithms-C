#pragma once

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct tagNode {
    char* Data; // 노드가 저장하는 문자열 데이터
    struct tagNode* NextNode; // 다음 노드를 가리키는 포인터
} Node;

// 연결 리스트 큐 구조체 정의
typedef struct tagLinkedQueue {
    Node* Front; // 큐의 첫 번째 노드를 가리키는 포인터
    Node* Rear; // 큐의 마지막 노드를 가리키는 포인터
    int Count; // 큐 내 노드 개수
} LinkedQueue;

// 함수 원형 선언
void LQ_CreateQueue(LinkedQueue** Queue); // 큐 생성 함수
void LQ_DestroyQueue(LinkedQueue* Queue); // 큐 해제 함수
Node* LQ_CreateNode(char* Data); // 새로운 노드 생성 함수
void LQ_DestroyNode(Node* _Node); // 노드 해제 함수
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode); // 큐에 데이터 추가
Node* LQ_Dequeue(LinkedQueue* Queue); // 큐에서 데이터 제거
int LQ_IsEmpty(LinkedQueue* Queue); // 큐가 비어있는지 확인

#endif