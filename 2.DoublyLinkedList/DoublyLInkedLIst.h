#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// ��� ����ü ����
typedef struct tagNode {
    ElementType Data; // ��尡 �����ϴ� ������
    struct tagNode* PrevNode; // ���� ��带 ����Ű�� ������
    struct tagNode* NextNode; // ���� ��带 ����Ű�� ������
} Node;

// �Լ� ���� ����
Node* DLL_CreateNode(ElementType NewData); // ���ο� ��带 �����ϴ� �Լ�
void DLL_DestroyNode(Node* Node); // ��带 �޸𸮿��� �����ϴ� �Լ�
void DLL_AppendNode(Node** Head, Node* NewNode); // ����Ʈ�� ���� ��带 �߰��ϴ� �Լ�
void DLL_InsertAfter(Node* Current, Node* NewNode); // ������ ��� �ڿ� �� ��带 �����ϴ� �Լ�
void DLL_RemoveNode(Node** Head, Node* Remove); // ����Ʈ���� ������ ��带 �����ϴ� �Լ�
Node* DLL_GetNodeAt(Node* Head, int Location); // ����Ʈ���� Ư�� ��ġ�� ��带 ��ȯ�ϴ� �Լ�
int DLL_GetNodeCount(Node* Head); // ����Ʈ�� ��� ��� ������ ��ȯ�ϴ� �Լ�

#endif