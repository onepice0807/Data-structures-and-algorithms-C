#include "DisjointSet.h"

// �� ������ ��ġ�� �Լ� (Set1�� Set2�� ��ǥ ���� ����)
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2) {
    Set2 = DS_FindSet(Set2); // Set2�� ��ǥ ��带 ã��
    Set2->Parent = Set1; // Set2�� ��ǥ ��尡 Set1�� �θ�� ����Ű���� ����
}

// ������ ��ǥ ��带 ã�� �Լ� (��� ���� ���� �� ��)
DisjointSet* DS_FindSet(DisjointSet* Set) {
    while (Set->Parent != NULL) {  // �θ� NULL�� ������ Ž��
        Set = Set->Parent; // ���� ���� �̵�
    }
    return Set; // ��ǥ ��� ��ȯ
}

// ���ο� ������ �����ϰ� �ʱ�ȭ�ϴ� �Լ�
DisjointSet* DS_MakeSet(void* NewData) {
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet)); // ��� �޸� �Ҵ�
    NewNode->Data = NewData; // ������ ����
    NewNode->Parent = NULL; // �θ� ��� �ʱ�ȭ
    return NewNode;
}

// ������ �Ҹ��Ű�� �Լ�
void DS_DestroySet(DisjointSet* Set) {
    free(Set); // ��� �޸� ����
}
