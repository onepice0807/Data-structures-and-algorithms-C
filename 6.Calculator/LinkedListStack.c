#include "LinkedListStack.h"

// ���� ���� �Լ�
void LLS_CreateStack(LinkedListStack** Stack) {
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); // ������ ���� �Ҵ�
    (*Stack)->List = NULL;  // ����Ʈ �ʱ�ȭ
    (*Stack)->Top = NULL;   // Top �ʱ�ȭ
}

// ���� ���� �Լ�
void LLS_DestroyStack(LinkedListStack* Stack) {
    while (!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack); // ���ÿ��� ��� ����
        LLS_DestroyNode(Popped);       // ���ŵ� ��� ����
    }
    free(Stack); // ���� ����ü ��ü�� ���� �޸𸮿��� ����
}

// ���ο� ��带 �����ϴ� �Լ�
Node* LLS_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node)); // ��� �޸� �Ҵ�
    NewNode->Data = (char*)malloc(strlen(NewData) + 1); // ������ �޸� �Ҵ�
    strcpy(NewNode->Data, NewData);  // �����͸� ����
    NewNode->NextNode = NULL; // ���� ��� ������ �ʱ�ȭ
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void LLS_DestroyNode(Node* _Node) {
    free(_Node->Data); // ������ �޸� ����
    free(_Node);       // ��� �޸� ����
}

// ���ÿ� ������ �߰� (Push)
void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
    if (Stack->List == NULL) {
        Stack->List = NewNode; // ������ ����ִٸ� ���ο� ��带 ù ���� ����
    }
    else {
        Stack->Top->NextNode = NewNode; // ������ Top �ڿ� ���ο� ��带 ����
    }
    Stack->Top = NewNode; // Top�� �� ���� ����
}

// ���ÿ��� ������ ���� (Pop)
Node* LLS_Pop(LinkedListStack* Stack) {
    Node* TopNode = Stack->Top; // �ֻ��� ��带 �ӽ÷� ����
    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else {
        Node* CurrentTop = Stack->List;
        while (CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }
        Stack->Top = CurrentTop; // ���ο� Top�� ����
        Stack->Top->NextNode = NULL;
    }
    return TopNode; // ���ŵ� ��带 ��ȯ
}

// ������ �ֻ�� ������ Ȯ��
Node* LLS_Top(LinkedListStack* Stack) {
    return Stack->Top; // Top ��� ��ȯ
}

// ������ ũ�� ��ȯ
int LLS_GetSize(LinkedListStack* Stack) {
    int Count = 0;
    Node* Current = Stack->List;
    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

// ������ ����ִ��� Ȯ��
int LLS_IsEmpty(LinkedListStack* Stack) {
    return (Stack->List == NULL); // ����Ʈ�� NULL�̸� ������ �������
}