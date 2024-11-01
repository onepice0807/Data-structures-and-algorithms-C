#pragma once

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// ��� ����ü ���� (������ �� ��Ҹ� ����)
typedef struct tagNode {
	ElementType Data; // ����� ������
} Node;

// �迭 ��� ���� ����ü ����
typedef struct tagArrayStack {
	int Capacity; // ������ �ִ� �뷮
	int Top; // ������ ���� �ֻ��� ��� �ε���
	Node* Nodes; // �����͸� �����ϴ� ��� �迭 ������
} ArrayStack;

// �Լ� ���� ����
void AS_CreateStack(ArrayStack** Stack, int Capacity); // ���� ���� �Լ�
void AS_DestroyStack(ArrayStack* Stack); // ���� ���� �Լ�
void AS_Push(ArrayStack* Stack, ElementType Data); // ���ÿ� ������ �߰�
ElementType AS_Pop(ArrayStack* Stack); // ���ÿ��� ������ ����
ElementType AS_Top(ArrayStack* Stack); // ���� �ֻ��� ������ ��ȯ
int AS_GetSize(ArrayStack* Stack); // ���� ũ�� ��ȯ
int AS_IsEmpty(ArrayStack* Stack); // ������ ����ִ��� Ȯ��

#endif 