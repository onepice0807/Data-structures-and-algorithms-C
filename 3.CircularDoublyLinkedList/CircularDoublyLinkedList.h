#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

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
Node* CDLL_CreateNode(ElementType NewData); // ���ο� ��带 �����ϴ� �Լ�
void  CDLL_DestroyNode(Node* Node); // ��带 �޸𸮿��� �����ϴ� �Լ�
void  CDLL_AppendNode(Node** Head, Node* NewNode); // ����Ʈ�� ���� ��带 �߰��ϴ� �Լ�
void  CDLL_InsertAfter(Node* Current, Node* NewNode); // ������ ��� �ڿ� �� ��带 �����ϴ� �Լ�
void  CDLL_RemoveNode(Node** Head, Node* Remove); // ����Ʈ���� ������ ��带 �����ϴ� �Լ�
Node* CDLL_GetNodeAt(Node* Head, int Location); // ����Ʈ���� Ư�� ��ġ�� ��带 ��ȯ�ϴ� �Լ�
int   CDLL_GetNodeCount(Node* Head); // ����Ʈ�� ��� ��� ������ ��ȯ�ϴ� �Լ�

#endif