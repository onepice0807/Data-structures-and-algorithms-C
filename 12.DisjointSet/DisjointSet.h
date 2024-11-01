#pragma once

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// �и� ���� ��� ����ü ����
typedef struct tagDisjointSet {
    struct tagDisjointSet* Parent;  // �θ� ��带 ����Ű�� ������
    void* Data; // ��尡 �����ϴ� ������
} DisjointSet;

// �Լ� ���� ����
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2); // �� ������ ��ġ�� �Լ�
DisjointSet* DS_FindSet(DisjointSet* Set); // ������ ��ǥ ��带 ã�� �Լ�
DisjointSet* DS_MakeSet(void* NewData); // ���ο� ������ �����ϴ� �Լ�
void DS_DestroySet(DisjointSet* Set); // ������ �Ҹ��Ű�� �Լ�

#endif