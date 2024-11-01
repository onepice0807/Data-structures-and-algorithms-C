#include "CircularQueue.h"

int main(void) {
    int i;
    CircularQueue* Queue;

    // 큐 생성 및 초기화 (용량 10)
    CQ_CreateQueue(&Queue, 10);

    // 큐에 데이터 추가
    CQ_Enqueue(Queue, 1);
    CQ_Enqueue(Queue, 2);
    CQ_Enqueue(Queue, 3);
    CQ_Enqueue(Queue, 4);

    // 큐에서 데이터 제거 및 상태 출력
    for (i = 0; i < 3; i++) {
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }

    // 큐가 가득 찰 때까지 데이터 추가
    i = 100;
    while (!CQ_IsFull(Queue)) {
        CQ_Enqueue(Queue, i++);
    }

    printf("Capacity: %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

    // 큐가 빌 때까지 데이터 제거 및 상태 출력
    while (!CQ_IsEmpty(Queue)) {
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }

    // 큐 해제
    CQ_DestroyQueue(Queue);

    return 0;
}