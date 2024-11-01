#include "LinkedList.h"

// ���ο� ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node)); // �޸� �Ҵ�

	NewNode->Data = NewData; // �����͸� ����
	NewNode->NextNode = NULL; // ���� ��� ������ �ʱ�ȭ

	return NewNode; // ������ ��� ��ȯ
}

// ��� �Ҹ�
void SLL_DestroyNode(Node* Node) {
	free(Node); // ��� �޸� ����
}

// ����Ʈ ���� �� ��带 �߰��ϴ� �Լ�
void SLL_AppendNode(Node** Head, Node* NewNode) {
	// ��尡 NULL�̸� ���ο� ��尡 ��尡 ��
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		// ������ ��带 ã�Ƽ� �� ��带 ����
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// Ư�� ��� �ڿ� �� ��带 �����ϴ� �Լ�
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode; // �� ����� ������ ���� ����� �������� ����
	Current->NextNode = NewNode;           // ���� ����� ������ �� ���� ����
}

// ����Ʈ�� ���� �κп� �� ��带 �����ϴ� �Լ�
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	NewHead->NextNode = (*Head); // �� ����� ������ ���� ���� ����
	(*Head) = NewHead;           // ��带 �� ���� ������Ʈ
}

// Ư�� ��带 ����Ʈ���� �����ϴ� �Լ�
void SLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode; // ������ ��尡 �����, ���� ��带 ���� ����
	}
	else {
		// ������ ����� ���� ��带 ã�Ƽ� ���� ��� ���� ����
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// ����Ʈ���� Ư�� ��ġ�� ��带 ��ȯ�ϴ� �Լ�
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	// ������ ��ġ���� �ݺ��ؼ� �̵�
	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

// ����Ʈ�� ��� ������ ���� �Լ�
int SLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}