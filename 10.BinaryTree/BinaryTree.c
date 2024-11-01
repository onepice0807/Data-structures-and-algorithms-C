#include "BinaryTree.h"

// ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
SBTNode* SBT_CreateNode(ElementType NewData) {
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode)); // ��� �޸� �Ҵ�
    NewNode->Left = NULL; // ���� �ڽ� �ʱ�ȭ
    NewNode->Right = NULL; // ������ �ڽ� �ʱ�ȭ
    NewNode->Data = NewData; // ������ ����
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void SBT_DestroyNode(SBTNode* Node) {
    free(Node); // ��� �޸� ����
}

// Ʈ�� ��ü�� �Ҹ��Ű�� �Լ�
void SBT_DestroyTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    // ���� ����Ʈ�� �Ҹ�
    SBT_DestroyTree(Node->Left);

    // ������ ����Ʈ�� �Ҹ�
    SBT_DestroyTree(Node->Right);

    // ��Ʈ ��� �Ҹ�
    SBT_DestroyNode(Node);
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void SBT_PreorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    printf(" %c", Node->Data);  // ��Ʈ ��� ���
    SBT_PreorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    SBT_PreorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void SBT_InorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    SBT_InorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    printf(" %c", Node->Data); // ��Ʈ ��� ���
    SBT_InorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void SBT_PostorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    SBT_PostorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    SBT_PostorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
    printf(" %c", Node->Data); // ��Ʈ ��� ���
}