#include "ExpressionTree.h"

// 노드를 생성하고 초기화하는 함수
ETNode* ET_CreateNode(ElementType NewData) {
    ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode)); // 노드 메모리 할당
    NewNode->Left = NULL;      // 왼쪽 자식 초기화
    NewNode->Right = NULL;     // 오른쪽 자식 초기화
    NewNode->Data = NewData;   // 데이터 설정
    return NewNode;
}

// 노드를 소멸시키는 함수
void ET_DestroyNode(ETNode* Node) {
    free(Node); // 노드 메모리 해제
}

// 트리 전체를 소멸시키는 함수
void ET_DestroyTree(ETNode* Root) {
    if (Root == NULL)
        return;

    ET_DestroyTree(Root->Left);  // 왼쪽 서브트리 소멸
    ET_DestroyTree(Root->Right); // 오른쪽 서브트리 소멸
    ET_DestroyNode(Root);        // 루트 노드 소멸
}

// 전위 순회로 트리를 출력하는 함수
void ET_PreorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    printf(" %c", Node->Data); // 루트 노드 출력
    ET_PreorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    ET_PreorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
}

// 중위 순회로 트리를 출력하는 함수
void ET_InorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    printf("("); 
    ET_InorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    printf("%c", Node->Data); // 루트 노드 출력
    ET_InorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
    printf(")");
}

// 후위 순회로 트리를 출력하는 함수
void ET_PostorderPrintTree(ETNode* Node) {
    if (Node == NULL)
        return;

    ET_PostorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    ET_PostorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
    printf(" %c", Node->Data);  // 루트 노드 출력
}

// 후위 표기식을 기반으로 수식 트리를 생성하는 함수
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node) {
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len - 1];
    PostfixExpression[len - 1] = '\0';

    // 연산자일 경우 하위 트리 구성
    if (Token == '+' || Token == '-' || Token == '*' || Token == '/') {
        (*Node) = ET_CreateNode(Token);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
    }
    else {
        // 피연산자인 경우 단일 노드 생성
        (*Node) = ET_CreateNode(Token);
    }
}

// 수식 트리를 평가하여 결과를 반환하는 함수
double ET_Evaluate(ETNode* Tree) {
    double Left = 0, Right = 0, Result = 0;

    if (Tree == NULL)
        return 0;

    if (Tree->Data == '+' || Tree->Data == '-' || Tree->Data == '*' || Tree->Data == '/') {
        // 연산자인 경우 좌우 서브트리 재귀 호출
        Left = ET_Evaluate(Tree->Left);
        Right = ET_Evaluate(Tree->Right);

        // 연산자에 따른 계산 수행
        if (Tree->Data == '+') Result = Left + Right;
        else if (Tree->Data == '-') Result = Left - Right;
        else if (Tree->Data == '*') Result = Left * Right;
        else if (Tree->Data == '/') Result = Left / Right;
    }
    else {
        // 피연산자인 경우 값을 반환
        Result = atof(&Tree->Data);
    }

    return Result;
}
