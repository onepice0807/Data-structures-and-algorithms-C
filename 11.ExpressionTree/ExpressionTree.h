#pragma once

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����� ������ Ÿ��
typedef char ElementType;

// ���� Ʈ�� ��� ����ü ����
typedef struct tagETNode {
    struct tagETNode* Left;  // ���� �ڽ� ��带 ����Ű�� ������
    struct tagETNode* Right; // ������ �ڽ� ��带 ����Ű�� ������
    ElementType Data; // ��忡 ����� ������ (������ �Ǵ� �ǿ�����)
} ETNode;

// �Լ� ���� ����
ETNode* ET_CreateNode(ElementType NewData); // ��� ���� �Լ�
void ET_DestroyNode(ETNode* Node); // ��� �Ҹ� �Լ�
void ET_DestroyTree(ETNode* Root); // Ʈ�� ��ü �Ҹ� �Լ�
void ET_PreorderPrintTree(ETNode* Node); // ���� ��ȸ ��� �Լ�
void ET_InorderPrintTree(ETNode* Node); // ���� ��ȸ ��� �Լ�
void ET_PostorderPrintTree(ETNode* Node); // ���� ��ȸ ��� �Լ�
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node); // ���� ǥ������� ���� Ʈ�� ����
double ET_Evaluate(ETNode* Tree);  // ���� Ʈ�� �� �Լ�

#endif