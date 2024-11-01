#pragma once

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct tagNode {
    char* Data; // ��尡 �����ϴ� ���ڿ� ������
    struct tagNode* NextNode; // ���� ��带 ����Ű�� ������
} Node;

// ���� ����Ʈ ť ����ü ����
typedef struct tagLinkedQueue {
    Node* Front; // ť�� ù ��° ��带 ����Ű�� ������
    Node* Rear; // ť�� ������ ��带 ����Ű�� ������
    int Count; // ť �� ��� ����
} LinkedQueue;

// �Լ� ���� ����
void LQ_CreateQueue(LinkedQueue** Queue); // ť ���� �Լ�
void LQ_DestroyQueue(LinkedQueue* Queue); // ť ���� �Լ�
Node* LQ_CreateNode(char* Data); // ���ο� ��� ���� �Լ�
void LQ_DestroyNode(Node* _Node); // ��� ���� �Լ�
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode); // ť�� ������ �߰�
Node* LQ_Dequeue(LinkedQueue* Queue); // ť���� ������ ����
int LQ_IsEmpty(LinkedQueue* Queue); // ť�� ����ִ��� Ȯ��

#endif