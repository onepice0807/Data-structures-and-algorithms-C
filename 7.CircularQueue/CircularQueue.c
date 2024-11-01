#include "CircularQueue.h"

// 큐 생성 함수
void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
    // 큐를 동적 메모리 할당
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

    // Capacity+1 크기의 노드 배열을 동적 할당하여 원형 큐를 구현
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

    // 큐의 용량 및 인덱스 초기화
    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

// 큐 해제 함수
void CQ_DestroyQueue(CircularQueue* Queue) {
    free(Queue->Nodes);  // 노드 배열 메모리 해제
    free(Queue);         // 큐 구조체 메모리 해제
}

// 큐에 데이터 추가 (Enqueue)
void CQ_Enqueue(CircularQueue* Queue, ElementType Data) {
    int Position = Queue->Rear;

    if (Queue->Rear == Queue->Capacity) // Rear이 배열의 끝에 도달했는지 확인
        Queue->Rear = 0; // Rear이 배열의 끝에 도달하면 처음으로 되돌림
    else
        Queue->Rear++;

    Queue->Nodes[Position].Data = Data; // 지정된 위치에 데이터 저장
}

// 큐에서 데이터 제거 (Dequeue)
ElementType CQ_Dequeue(CircularQueue* Queue) {
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity) // Front가 배열 끝에 도달했는지 확인
        Queue->Front = 0; // 끝에 도달하면 처음으로 되돌림
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data; // 제거된 데이터 반환
}

// 현재 큐의 크기를 반환
int CQ_GetSize(CircularQueue* Queue) {
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front; // Rear가 Front 뒤에 있을 때
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1; // Rear가 Front 앞에 있을 때
}

// 큐가 비어있는지 확인
int CQ_IsEmpty(CircularQueue* Queue) {
    return (Queue->Front == Queue->Rear);
}

// 큐가 가득 찼는지 확인
int CQ_IsFull(CircularQueue* Queue) {
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear + 1) == Queue->Front;
}