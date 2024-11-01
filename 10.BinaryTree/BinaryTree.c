#include "BinaryTree.h"

// 노드를 생성하고 초기화하는 함수
SBTNode* SBT_CreateNode(ElementType NewData) {
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode)); // 노드 메모리 할당
    NewNode->Left = NULL; // 왼쪽 자식 초기화
    NewNode->Right = NULL; // 오른쪽 자식 초기화
    NewNode->Data = NewData; // 데이터 설정
    return NewNode;
}

// 노드를 소멸시키는 함수
void SBT_DestroyNode(SBTNode* Node) {
    free(Node); // 노드 메모리 해제
}

// 트리 전체를 소멸시키는 함수
void SBT_DestroyTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    // 왼쪽 서브트리 소멸
    SBT_DestroyTree(Node->Left);

    // 오른쪽 서브트리 소멸
    SBT_DestroyTree(Node->Right);

    // 루트 노드 소멸
    SBT_DestroyNode(Node);
}

// 전위 순회로 트리를 출력하는 함수
void SBT_PreorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    printf(" %c", Node->Data);  // 루트 노드 출력
    SBT_PreorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    SBT_PreorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
}

// 중위 순회로 트리를 출력하는 함수
void SBT_InorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    SBT_InorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    printf(" %c", Node->Data); // 루트 노드 출력
    SBT_InorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
}

// 후위 순회로 트리를 출력하는 함수
void SBT_PostorderPrintTree(SBTNode* Node) {
    if (Node == NULL)
        return;

    SBT_PostorderPrintTree(Node->Left); // 왼쪽 하위 트리 순회
    SBT_PostorderPrintTree(Node->Right); // 오른쪽 하위 트리 순회
    printf(" %c", Node->Data); // 루트 노드 출력
}