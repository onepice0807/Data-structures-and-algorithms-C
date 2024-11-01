#include "ArrayStack.h"

// ���� ���� �Լ�
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    // ������ ���� �޸� �Ҵ�
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    // �Էµ� �뷮��ŭ ��� �迭�� ���� �Ҵ�
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

    // ������ �뷮 �� Top �ʱ�ȭ
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

// ���� ���� �Լ�
void AS_DestroyStack(ArrayStack* Stack) {
    // ������ ��� �迭�� ���� �޸𸮿��� ����
    free(Stack->Nodes);

    // ���� ����ü�� ���� �޸𸮿��� ����
    free(Stack);
}

// ���ÿ� ������ �߰� (Push)
void AS_Push(ArrayStack* Stack, ElementType Data) {
    Stack->Top++; // Top ��ġ�� ����
    Stack->Nodes[Stack->Top].Data = Data; // ������ ����
}

// ���ÿ��� ������ ���� (Pop)
ElementType AS_Pop(ArrayStack* Stack) {
    int Position = Stack->Top--; // ���� Top ��ġ ���� �� ����
    return Stack->Nodes[Position].Data; // ���ŵ� ������ ��ȯ
}

// ������ �ֻ��� ������ Ȯ�� (Top)
ElementType AS_Top(ArrayStack* Stack) {
    return Stack->Nodes[Stack->Top].Data; // �ֻ��� ������ ��ȯ
}

// ���� ���� ũ�� ��ȯ
int AS_GetSize(ArrayStack* Stack) {
    return Stack->Top + 1; // Top �ε��� + 1�� ������ ���� ũ��
}

// ������ ����ִ��� Ȯ��
int AS_IsEmpty(ArrayStack* Stack) {
    return (Stack->Top == -1); // Top�� -1�̸� ������ �������
}

#include "ArrayStack.h"
#include <stdio.h>

int main(void) {
    int i = 0;
    ArrayStack* Stack = NULL;

    // �뷮�� 50�� ���� ����
    AS_CreateStack(&Stack, 50);

    // ������ �뷮��ŭ ä���
    while (i < Stack->Capacity) {
        AS_Push(Stack, i + 1); // 1���� 50���� �߰�
        i++;
    }

    // ������ ���� ���
    printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    // ������ ������� ������ pop�ϰ� �� ���� ���
    while (!AS_IsEmpty(Stack)) {
        printf("Popped: %d", AS_Pop(Stack));

        if (!AS_IsEmpty(Stack))
            printf(" Current Top: %d\n", AS_Top(Stack));
        else
            printf(" Stack Is Empty.\n");
    }

    // ���� ����
    AS_DestroyStack(Stack);

    return 0;
}