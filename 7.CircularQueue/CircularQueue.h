#pragma once
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// ��� ����ü ����
typedef struct tagNode {
    ElementType Data;  // ť�� ����� ������
} Node;

// ���� ť ����ü ����
typedef struct tagCircularQueue {
    int Capacity;  // ť�� �ִ� �뷮
    int Front;     // ť�� �� �� �ε���
    int Rear;      // ť�� �� �� �ε���
    Node* Nodes;   // �����͸� �����ϴ� ��� �迭 ������
} CircularQueue;

// �Լ� ���� ����
void CQ_CreateQueue(CircularQueue** Queue, int Capacity); // ť ���� �Լ�
void CQ_DestroyQueue(CircularQueue* Queue); // ť ���� �Լ�
void CQ_Enqueue(CircularQueue* Queue, ElementType Data); // ť�� ������ �߰�
ElementType CQ_Dequeue(CircularQueue* Queue); // ť���� ������ ����
int CQ_GetSize(CircularQueue* Queue); // ť ũ�� ��ȯ
int CQ_IsEmpty(CircularQueue* Queue); // ť�� ����ִ��� Ȯ��
int CQ_IsFull(CircularQueue* Queue); // ť�� ���� á���� Ȯ��

#endif