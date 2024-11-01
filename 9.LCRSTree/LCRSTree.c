#include "LCRSTree.h"

// 새로운 노드를 생성하는 함수
LCRSNode* LCRS_CreateNode(ElementType NewData) {
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode)); // 노드 메모리 할당
    NewNode->LeftChild = NULL; // 자식 노드 포인터 초기화
    NewNode->RightSilbling = NULL; // 형제 노드 포인터 초기화
    NewNode->Data = NewData; // 데이터 저장
    return NewNode;
}

// 노드를 소멸시키는 함수
void LCRS_DestroyNode(LCRSNode* Node) {
    free(Node); // 노드 메모리 해제
}

// 트리 전체를 소멸시키는 함수
void LCRS_DestroyTree(LCRSNode* Root) {
    if (Root->RightSilbling != NULL)
        LCRS_DestroyTree(Root->RightSilbling); // 형제 노드 재귀적으로 소멸
    if (Root->LeftChild != NULL)
        LCRS_DestroyTree(Root->LeftChild); // 자식 노드 재귀적으로 소멸

    Root->LeftChild = NULL;
    Root->RightSilbling = NULL;
    LCRS_DestroyNode(Root); // 현재 노드 소멸
}

// 부모 노드에 자식 노드를 추가하는 함수
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
    if (Parent->LeftChild == NULL) {
        // 부모 노드에 자식이 없으면 새로운 자식을 LeftChild로 설정
        Parent->LeftChild = Child;
    }
    else {
        // 부모 노드에 자식이 있으면 형제 리스트의 끝에 추가
        LCRSNode* TempNode = Parent->LeftChild;
        while (TempNode->RightSilbling != NULL)
            TempNode = TempNode->RightSilbling; // 형제 노드의 끝을 찾음
        TempNode->RightSilbling = Child; // 끝에 새 자식 노드를 연결
    }
}

// 트리를 들여쓰기 형태로 출력하는 함수
void LCRS_PrintTree(LCRSNode* Node, int Depth) {
    int i;
    for (i = 0; i < Depth - 1; i++) // Depth에 따라 들여쓰기
        printf("   ");

    if (Depth > 0) // 자식 노드 표시
        printf("+--");

    printf("%c\n", Node->Data); // 노드 데이터 출력

    if (Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth + 1); // 자식 노드를 출력
    if (Node->RightSilbling != NULL)
        LCRS_PrintTree(Node->RightSilbling, Depth); // 형제 노드를 출력
}