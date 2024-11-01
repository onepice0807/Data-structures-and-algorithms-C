#include "LinkedQueue.h"

int main(void) {
    Node* Popped;
    LinkedQueue* Queue;

    // ť ����
    LQ_CreateQueue(&Queue);

    // ť�� ������ �߰�
    LQ_Enqueue(Queue, LQ_CreateNode("abc"));
    LQ_Enqueue(Queue, LQ_CreateNode("def"));
    LQ_Enqueue(Queue, LQ_CreateNode("efg"));
    LQ_Enqueue(Queue, LQ_CreateNode("hij"));

    // ť ũ�� ���
    printf("Queue Size : %d\n", Queue->Count);

    // ť�� ������� ������ ������ ����
    while (!LQ_IsEmpty(Queue)) {
        Popped = LQ_Dequeue(Queue);
        printf("Dequeue: %s \n", Popped->Data);
        LQ_DestroyNode(Popped);
    }

    // ť ����
    LQ_DestroyQueue(Queue);

    return 0;
}