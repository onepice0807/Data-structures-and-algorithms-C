#include "ExpressionTree.h"

// ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
ETNode* ET_CreateNode(ElementType NewData) {
    ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode)); // ��� �޸� �Ҵ�
    NewNode->Left = NULL;      // ���� �ڽ� �ʱ�ȭ
    NewNode->Right = NULL;     // ������ �ڽ� �ʱ�ȭ
    NewNode->Data = NewData;   // ������ ����
    return NewNode;
}

// ��带 �Ҹ��Ű�� �Լ�
void ET_DestroyNode(ETNode* Node) {
    free(Node); // ��� �޸� ����
}

// Ʈ�� ��ü�� �Ҹ��Ű�� �Լ�
void ET_DestroyTree(ETNode* Root) {
    if (Root == NULL)
        return;

    ET_DestroyTree(Root->Left);  // ���� ����Ʈ�� �Ҹ�
    ET_DestroyTree(Root->Right); // ������ ����Ʈ�� �Ҹ�
    ET_DestroyNode(Root);        // ��Ʈ ��� �Ҹ�
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void ET_PreorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    printf(" %c", Node->Data); // ��Ʈ ��� ���
    ET_PreorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    ET_PreorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void ET_InorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    printf("("); 
    ET_InorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    printf("%c", Node->Data); // ��Ʈ ��� ���
    ET_InorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
    printf(")");
}

// ���� ��ȸ�� Ʈ���� ����ϴ� �Լ�
void ET_PostorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    ET_PostorderPrintTree(Node->Left); // ���� ���� Ʈ�� ��ȸ
    ET_PostorderPrintTree(Node->Right); // ������ ���� Ʈ�� ��ȸ
    printf(" %c", Node->Data);  // ��Ʈ ��� ���
}

// ���� ǥ����� ������� ���� Ʈ���� �����ϴ� �Լ�
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node) {
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len - 1];
    PostfixExpression[len - 1] = '\0';

    // �������� ��� ���� Ʈ�� ����
    if (Token == '+' || Token == '-' || Token == '*' || Token == '/') {
        (*Node) = ET_CreateNode(Token);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
    }
    else {
        // �ǿ������� ��� ���� ��� ����
        (*Node) = ET_CreateNode(Token);
    }
}

// ���� Ʈ���� ���Ͽ� ����� ��ȯ�ϴ� �Լ�
double ET_Evaluate(ETNode* Tree) {
    double Left = 0, Right = 0, Result = 0;

    if (Tree == NULL)
        return 0;

    if (Tree->Data == '+' || Tree->Data == '-' || Tree->Data == '*' || Tree->Data == '/') {
        // �������� ��� �¿� ����Ʈ�� ��� ȣ��
        Left = ET_Evaluate(Tree->Left);
        Right = ET_Evaluate(Tree->Right);

        // �����ڿ� ���� ��� ����
        if (Tree->Data == '+') Result = Left + Right;
        else if (Tree->Data == '-') Result = Left - Right;
        else if (Tree->Data == '*') Result = Left * Right;
        else if (Tree->Data == '/') Result = Left / Right;
    }
    else {
        // �ǿ������� ��� ���� ��ȯ
        Result = atof(&Tree->Data);
    }

    return Result;
}
