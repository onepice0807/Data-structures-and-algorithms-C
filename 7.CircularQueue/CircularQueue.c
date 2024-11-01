#include "CircularQueue.h"

// ť ���� �Լ�
void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
    // ť�� ���� �޸� �Ҵ�
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

    // Capacity+1 ũ���� ��� �迭�� ���� �Ҵ��Ͽ� ���� ť�� ����
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

    // ť�� �뷮 �� �ε��� �ʱ�ȭ
    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

// ť ���� �Լ�
void CQ_DestroyQueue(CircularQueue* Queue) {
    free(Queue->Nodes);  // ��� �迭 �޸� ����
    free(Queue);         // ť ����ü �޸� ����
}

// ť�� ������ �߰� (Enqueue)
void CQ_Enqueue(CircularQueue* Queue, ElementType Data) {
    int Position = Queue->Rear;

    if (Queue->Rear == Queue->Capacity) // Rear�� �迭�� ���� �����ߴ��� Ȯ��
        Queue->Rear = 0; // Rear�� �迭�� ���� �����ϸ� ó������ �ǵ���
    else
        Queue->Rear++;

    Queue->Nodes[Position].Data = Data; // ������ ��ġ�� ������ ����
}

// ť���� ������ ���� (Dequeue)
ElementType CQ_Dequeue(CircularQueue* Queue) {
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity) // Front�� �迭 ���� �����ߴ��� Ȯ��
        Queue->Front = 0; // ���� �����ϸ� ó������ �ǵ���
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data; // ���ŵ� ������ ��ȯ
}

// ���� ť�� ũ�⸦ ��ȯ
int CQ_GetSize(CircularQueue* Queue) {
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front; // Rear�� Front �ڿ� ���� ��
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1; // Rear�� Front �տ� ���� ��
}

// ť�� ����ִ��� Ȯ��
int CQ_IsEmpty(CircularQueue* Queue) {
    return (Queue->Front == Queue->Rear);
}

// ť�� ���� á���� Ȯ��
int CQ_IsFull(CircularQueue* Queue) {
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear + 1) == Queue->Front;
}