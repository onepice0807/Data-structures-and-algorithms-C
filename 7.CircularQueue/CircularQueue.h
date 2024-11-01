#pragma once
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의
typedef struct tagNode {
    ElementType Data;  // 큐에 저장될 데이터
} Node;

// 원형 큐 구조체 정의
typedef struct tagCircularQueue {
    int Capacity;  // 큐의 최대 용량
    int Front;     // 큐의 맨 앞 인덱스
    int Rear;      // 큐의 맨 뒤 인덱스
    Node* Nodes;   // 데이터를 저장하는 노드 배열 포인터
} CircularQueue;

// 함수 원형 선언
void CQ_CreateQueue(CircularQueue** Queue, int Capacity); // 큐 생성 함수
void CQ_DestroyQueue(CircularQueue* Queue); // 큐 해제 함수
void CQ_Enqueue(CircularQueue* Queue, ElementType Data); // 큐에 데이터 추가
ElementType CQ_Dequeue(CircularQueue* Queue); // 큐에서 데이터 제거
int CQ_GetSize(CircularQueue* Queue); // 큐 크기 반환
int CQ_IsEmpty(CircularQueue* Queue); // 큐가 비어있는지 확인
int CQ_IsFull(CircularQueue* Queue); // 큐가 가득 찼는지 확인

#endif