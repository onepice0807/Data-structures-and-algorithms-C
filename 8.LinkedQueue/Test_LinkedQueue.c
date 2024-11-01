#include "LinkedQueue.h"

int main(void) {
    Node* Popped;
    LinkedQueue* Queue;

    // 큐 생성
    LQ_CreateQueue(&Queue);

    // 큐에 데이터 추가
    LQ_Enqueue(Queue, LQ_CreateNode("abc"));
    LQ_Enqueue(Queue, LQ_CreateNode("def"));
    LQ_Enqueue(Queue, LQ_CreateNode("efg"));
    LQ_Enqueue(Queue, LQ_CreateNode("hij"));

    // 큐 크기 출력
    printf("Queue Size : %d\n", Queue->Count);

    // 큐가 비어있을 때까지 데이터 제거
    while (!LQ_IsEmpty(Queue)) {
        Popped = LQ_Dequeue(Queue);
        printf("Dequeue: %s \n", Popped->Data);
        LQ_DestroyNode(Popped);
    }

    // 큐 해제
    LQ_DestroyQueue(Queue);

    return 0;
}