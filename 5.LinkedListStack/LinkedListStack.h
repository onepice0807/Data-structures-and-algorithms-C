#pragma once

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct tagNode {
    char* Data; // ��尡 �����ϴ� ���ڿ� ������
    struct tagNode* NextNode; // ���� ��带 ����Ű�� ������
    struct tagNode* PrevNode; // ���� ��带 ����Ű�� ������
} Node;

// ���� ����Ʈ ���� ����ü ����
typedef struct tagLinkedListStack {
    int Count; // ���� �� ��� ����
    Node* List; // ������ ù ��° ��带 ����Ű�� ������
    Node* Top; // ������ �ֻ�� ��带 ����Ű�� ������
} LinkedListStack;

// �Լ� ���� ����
void LLS_CreateStack(LinkedListStack** Stack); // ���� ���� �Լ�
void LLS_DestroyStack(LinkedListStack* Stack); // ���� ���� �Լ�
Node* LLS_CreateNode(char* Data); // ���ο� ��� ���� �Լ�
void LLS_DestroyNode(Node* _Node); // ��� ���� �Լ�
void LLS_Push(LinkedListStack* Stack, Node* NewNode); // ���ÿ� ������ �߰�
Node* LLS_Pop(LinkedListStack* Stack); // ���ÿ��� ������ ����
Node* LLS_Top(LinkedListStack* Stack); // ���� �ֻ�� ������ ��ȯ
int LLS_GetSize(LinkedListStack* Stack); // ���� ũ�� ��ȯ
int LLS_IsEmpty(LinkedListStack* Stack); // ������ ����ִ��� Ȯ��

#endif