#include "CircularQueue.h"

int main(void) {
    int i;
    CircularQueue* Queue;

    // ť ���� �� �ʱ�ȭ (�뷮 10)
    CQ_CreateQueue(&Queue, 10);

    // ť�� ������ �߰�
    CQ_Enqueue(Queue, 1);
    CQ_Enqueue(Queue, 2);
    CQ_Enqueue(Queue, 3);
    CQ_Enqueue(Queue, 4);

    // ť���� ������ ���� �� ���� ���
    for (i = 0; i < 3; i++) {
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }

    // ť�� ���� �� ������ ������ �߰�
    i = 100;
    while (!CQ_IsFull(Queue)) {
        CQ_Enqueue(Queue, i++);
    }

    printf("Capacity: %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

    // ť�� �� ������ ������ ���� �� ���� ���
    while (!CQ_IsEmpty(Queue)) {
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }

    // ť ����
    CQ_DestroyQueue(Queue);

    return 0;
}