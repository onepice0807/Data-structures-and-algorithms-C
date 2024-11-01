#pragma once

#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

// ����� ������ Ÿ��
typedef char ElementType;

// LCRS Ʈ�� ��� ����ü ����
typedef struct tagLCRSNode {
    struct tagLCRSNode* LeftChild; // �ڽ� ��带 ����Ű�� ������
    struct tagLCRSNode* RightSilbling; // ���� ��带 ����Ű�� ������
    ElementType Data; // ��尡 �����ϴ� ������
} LCRSNode;

// �Լ� ���� ����
LCRSNode* LCRS_CreateNode(ElementType NewData); // ��� ���� �Լ�
void LCRS_DestroyNode(LCRSNode* Node); // ��� ���� �Լ�
void LCRS_DestroyTree(LCRSNode* Root); // Ʈ�� ��ü ���� �Լ�
void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode); // �ڽ� ��� �߰� �Լ�
void LCRS_PrintTree(LCRSNode* Node, int Depth); // Ʈ�� ��� �Լ�

#endif // !LCRS_TREE_H