#include "CircularDoublyLinkedList.h"

// ���ο� ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
Node* CDLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // �޸� �Ҵ�
    NewNode->Data = NewData; // ������ �ʱ�ȭ
    NewNode->PrevNode = NULL; // ���� ��� ������ �ʱ�ȭ
    NewNode->NextNode = NULL; // ���� ��� ������ �ʱ�ȭ
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void CDLL_DestroyNode(Node* Node) {
    free(Node); // �޸� ����
}

// ����Ʈ�� ���� �� ��带 �߰��ϴ� �Լ�
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    if (*Head == NULL) {
        // ����Ʈ�� ��������� ���ο� ��带 ���� �����ϰ� ��ȯ ����
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else {
        // ������ ����(������ ���) �ڿ� ���ο� ��带 �߰��ϰ� ��ȯ ����
        Node* Tail = (*Head)->PrevNode;
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
        NewNode->NextNode = *Head;
        (*Head)->PrevNode = NewNode;
    }
}

// Ư�� ��� �ڿ� �� ��带 �����ϴ� �Լ�
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode; // �� ����� ������ ���� ����� �������� ����
    NewNode->PrevNode = Current; // �� ����� ������ ���� ���� ����
    Current->NextNode->PrevNode = NewNode; // ���� ����� ������ �� ���� ����
    Current->NextNode = NewNode; // ���� ����� ������ �� ���� ����
}

// ����Ʈ���� Ư�� ��带 �����ϴ� �Լ�
void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        // ������ ��尡 ����� ���
        *Head = Remove->NextNode;
        if (*Head != Remove) {
            // ����Ʈ�� ��尡 ���� ���� �� ���� ������Ʈ
            (*Head)->PrevNode = Remove->PrevNode;
            Remove->PrevNode->NextNode = *Head;
        }
        else {
            // ����Ʈ�� ���� ��常 �ִ� ���
            *Head = NULL;
        }
    }
    else {
        // �߰� �Ǵ� ������ ��带 �����ϴ� ���
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}

// Ư�� ��ġ�� ��带 ��ȯ�ϴ� �Լ�
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while (Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

// ����Ʈ�� ��� ��� ������ ���� �Լ�
int CDLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;
    do {
        Current = Current->NextNode;
        Count++;
    } while (Current != Head);
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
