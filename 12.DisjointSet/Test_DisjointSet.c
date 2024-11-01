#include <stdio.h>
#include "DisjointSet.h"

int main(void) {
    int a = 1, b = 2, c = 3, d = 4;

    // 개별 집합 생성
    DisjointSet* Set1 = DS_MakeSet(&a);
    DisjointSet* Set2 = DS_MakeSet(&b);
    DisjointSet* Set3 = DS_MakeSet(&c);
    DisjointSet* Set4 = DS_MakeSet(&d);

    // 집합 비교 (Set1과 Set2는 다른 집합)
    printf("Set1 == Set2 : %d \n", DS_FindSet(Set1) == DS_FindSet(Set2));

    // 집합 합치기 (Set1과 Set3을 하나의 집합으로)
    DS_UnionSet(Set1, Set3);
    printf("Set1 == Set3 : %d \n", DS_FindSet(Set1) == DS_FindSet(Set3));

    // 집합 합치기 (Set3과 Set4를 하나의 집합으로)
    DS_UnionSet(Set3, Set4);
    printf("Set3 == Set4 : %d \n", DS_FindSet(Set3) == DS_FindSet(Set4));

    return 0;
}