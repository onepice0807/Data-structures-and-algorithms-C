#pragma once

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의 (스택의 각 요소를 저장)
typedef struct tagNode {
	ElementType Data; // 저장된 데이터
} Node;

// 배열 기반 스택 구조체 정의
typedef struct tagArrayStack {
	int Capacity; // 스택의 최대 용량
	int Top; // 스택의 현재 최상위 요소 인덱스
	Node* Nodes; // 데이터를 저장하는 노드 배열 포인터
} ArrayStack;

// 함수 원형 선언
void AS_CreateStack(ArrayStack** Stack, int Capacity); // 스택 생성 함수
void AS_DestroyStack(ArrayStack* Stack); // 스택 해제 함수
void AS_Push(ArrayStack* Stack, ElementType Data); // 스택에 데이터 추가
ElementType AS_Pop(ArrayStack* Stack); // 스택에서 데이터 제거
ElementType AS_Top(ArrayStack* Stack); // 스택 최상위 데이터 반환
int AS_GetSize(ArrayStack* Stack); // 스택 크기 반환
int AS_IsEmpty(ArrayStack* Stack); // 스택이 비어있는지 확인

#endif 