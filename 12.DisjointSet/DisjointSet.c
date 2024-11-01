#include "DisjointSet.h"

// 두 집합을 합치는 함수 (Set1을 Set2의 대표 노드로 설정)
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2) {
    Set2 = DS_FindSet(Set2); // Set2의 대표 노드를 찾음
    Set2->Parent = Set1; // Set2의 대표 노드가 Set1을 부모로 가리키도록 설정
}

// 집합의 대표 노드를 찾는 함수 (경로 압축 적용 안 됨)
DisjointSet* DS_FindSet(DisjointSet* Set) {
    while (Set->Parent != NULL) {  // 부모가 NULL일 때까지 탐색
        Set = Set->Parent; // 상위 노드로 이동
    }
    return Set; // 대표 노드 반환
}

// 새로운 집합을 생성하고 초기화하는 함수
DisjointSet* DS_MakeSet(void* NewData) {
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet)); // 노드 메모리 할당
    NewNode->Data = NewData; // 데이터 설정
    NewNode->Parent = NULL; // 부모 노드 초기화
    return NewNode;
}

// 집합을 소멸시키는 함수
void DS_DestroySet(DisjointSet* Set) {
    free(Set); // 노드 메모리 해제
}
