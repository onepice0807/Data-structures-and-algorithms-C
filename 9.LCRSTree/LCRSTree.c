#include "LCRSTree.h"

// ���ο� ��带 �����ϴ� �Լ�
LCRSNode* LCRS_CreateNode(ElementType NewData) {
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode)); // ��� �޸� �Ҵ�
    NewNode->LeftChild = NULL; // �ڽ� ��� ������ �ʱ�ȭ
    NewNode->RightSilbling = NULL; // ���� ��� ������ �ʱ�ȭ
    NewNode->Data = NewData; // ������ ����
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void LCRS_DestroyNode(LCRSNode* Node) {
    free(Node); // ��� �޸� ����
}

// Ʈ�� ��ü�� �Ҹ��Ű�� �Լ�
void LCRS_DestroyTree(LCRSNode* Root) {
    if (Root->RightSilbling != NULL)
        LCRS_DestroyTree(Root->RightSilbling); // ���� ��� ��������� �Ҹ�
    if (Root->LeftChild != NULL)
        LCRS_DestroyTree(Root->LeftChild); // �ڽ� ��� ��������� �Ҹ�

    Root->LeftChild = NULL;
    Root->RightSilbling = NULL;
    LCRS_DestroyNode(Root); // ���� ��� �Ҹ�
}

// �θ� ��忡 �ڽ� ��带 �߰��ϴ� �Լ�
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
    if (Parent->LeftChild == NULL) {
        // �θ� ��忡 �ڽ��� ������ ���ο� �ڽ��� LeftChild�� ����
        Parent->LeftChild = Child;
    }
    else {
        // �θ� ��忡 �ڽ��� ������ ���� ����Ʈ�� ���� �߰�
        LCRSNode* TempNode = Parent->LeftChild;
        while (TempNode->RightSilbling != NULL)
            TempNode = TempNode->RightSilbling; // ���� ����� ���� ã��
        TempNode->RightSilbling = Child; // ���� �� �ڽ� ��带 ����
    }
}

// Ʈ���� �鿩���� ���·� ����ϴ� �Լ�
void LCRS_PrintTree(LCRSNode* Node, int Depth) {
    int i;
    for (i = 0; i < Depth - 1; i++) // Depth�� ���� �鿩����
        printf("   ");

    if (Depth > 0) // �ڽ� ��� ǥ��
        printf("+--");

    printf("%c\n", Node->Data); // ��� ������ ���

    if (Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth + 1); // �ڽ� ��带 ���
    if (Node->RightSilbling != NULL)
        LCRS_PrintTree(Node->RightSilbling, Depth); // ���� ��带 ���
}