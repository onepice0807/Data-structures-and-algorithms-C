#pragma once

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// 분리 집합 노드 구조체 정의
typedef struct tagDisjointSet {
    struct tagDisjointSet* Parent;  // 부모 노드를 가리키는 포인터
    void* Data; // 노드가 저장하는 데이터
} DisjointSet;

// 함수 원형 선언
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2); // 두 집합을 합치는 함수
DisjointSet* DS_FindSet(DisjointSet* Set); // 집합의 대표 노드를 찾는 함수
DisjointSet* DS_MakeSet(void* NewData); // 새로운 집합을 생성하는 함수
void DS_DestroySet(DisjointSet* Set); // 집합을 소멸시키는 함수

#endif