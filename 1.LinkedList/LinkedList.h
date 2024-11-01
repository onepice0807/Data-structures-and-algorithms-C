#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// ��� ����ü ����
typedef struct tagNode
{
	ElementType Data; // ��尡 �����ϴ� ������
	struct tagNode* NextNode; // ���� ��忡 ���� ������
} Node;

// �Լ� ���� ����
Node* SLL_CreateNode(ElementType NewData); // ���ο� ��带 �����ϴ� �Լ�
void  SLL_DestroyNode(Node* Node);         // ��带 �����ϴ� �Լ�
void  SLL_AppendNode(Node** Head, Node* NewNode); // ����Ʈ ���� ��带 �߰��ϴ� �Լ�
void  SLL_InsertAfter(Node* Current, Node* NewNode); // Ư�� ��� �ڿ� �� ��带 �����ϴ� �Լ�
void  SLL_InsertNewHead(Node** Head, Node* NewHead); // ����Ʈ�� ���� �κп� �� ��带 �����ϴ� �Լ�
void  SLL_RemoveNode(Node** Head, Node* Remove); // Ư�� ��带 ����Ʈ���� �����ϴ� �Լ�
Node* SLL_GetNodeAt(Node* Head, int Location); // ������ ��ġ�� ��带 ��ȯ�ϴ� �Լ�
int   SLL_GetNodeCount(Node* Head); // ����Ʈ�� ��� ������ ���� �Լ�

#endif