#include "DoublyLinkedList.h"

// ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
Node* DLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // �޸� �Ҵ�
    NewNode->Data = NewData; // ������ �ʱ�ȭ
    NewNode->PrevNode = NULL; // ���� ��� ������ �ʱ�ȭ
    NewNode->NextNode = NULL; // ���� ��� ������ �ʱ�ȭ
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void DLL_DestroyNode(Node* Node) {
    free(Node); // �޸� ����
}

// ����Ʈ�� ���� �� ��带 �߰��ϴ� �Լ�
void DLL_AppendNode(Node** Head, Node* NewNode) {
    if (*Head == NULL) {
        // ��尡 NULL�̸� �� ��带 ���� ����
        *Head = NewNode;
    }
    else {
        // ����Ʈ�� ������ ��带 ã�� �� ��带 ����
        Node* Tail = *Head;
        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; // ���ο� ����� PrevNode�� ���� ���Ϸ� ����
    }
}

// Ư�� ��� �ڿ� �� ��带 �����ϴ� �Լ�
void DLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode; // ���ο� ����� ������ ���� ����� �������� ����
    NewNode->PrevNode = Current; // ���ο� ����� ������ ���� ���� ����
    if (Current->NextNode != NULL) {
        Current->NextNode->PrevNode = NewNode; // ���� ����� PrevNode�� �� ���� ����
    }
    Current->NextNode = NewNode; // ���� ����� ������ �� ���� ����
}

// ����Ʈ���� Ư�� ��带 �����ϴ� �Լ�
void DLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        // ������ ��尡 ����� ���
        *Head = Remove->NextNode; // ��带 ���� ���� ����
        if (*Head != NULL) {
            (*Head)->PrevNode = NULL; // ���ο� ����� PrevNode�� NULL�� ����
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else {
        // �߰��̳� ������ ��带 �����ϴ� ���
        if (Remove->NextNode != NULL) {
            Remove->PrevNode->NextNode = Remove->NextNode; // ���� ����� NextNode�� ����
            Remove->NextNode->PrevNode = Remove->PrevNode; // ���� ����� PrevNode�� ����
        }
    }
}

// Ư�� ��ġ�� ��带 ��ȯ�ϴ� �Լ�
Node* DLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    // ��ġ�� ������ ������ ����Ʈ�� ��ȸ
    while (Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

// ����Ʈ�� ��� ��� ������ ���� �Լ�
int DLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;
    // ����Ʈ�� ��ȸ�ϸ� ��� ���� ����
    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

// Ư�� ����� �����Ϳ� ���� ����� ������ ���
void PrintNode(Node* _Node) {
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL ");
    else
        printf("Prev: %d ", _Node->PrevNode->Data);

    printf("Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}