#pragma once

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// ����� ������ Ÿ��
typedef char ElementType;

// ���� Ʈ�� ��� ����ü ����
typedef struct tagSBTNode {
    struct tagSBTNode* Left; // ���� �ڽ� ��带 ����Ű�� ������
    struct tagSBTNode* Right; // ������ �ڽ� ��带 ����Ű�� ������
    ElementType Data; // ��忡 ����� ������
} SBTNode;

// �Լ� ���� ����
SBTNode* SBT_CreateNode(ElementType NewData); // ��� ���� �Լ�
void SBT_DestroyNode(SBTNode* Node); // ��� �Ҹ� �Լ�
void SBT_DestroyTree(SBTNode* Root); // Ʈ�� ��ü �Ҹ� �Լ�
void SBT_PreorderPrintTree(SBTNode* Node); // ���� ��ȸ ��� �Լ�
void SBT_InorderPrintTree(SBTNode* Node); // ���� ��ȸ ��� �Լ�
void SBT_PostorderPrintTree(SBTNode* Node); // ���� ��ȸ ��� �Լ�

#endif // ! BINARY_TREE_H