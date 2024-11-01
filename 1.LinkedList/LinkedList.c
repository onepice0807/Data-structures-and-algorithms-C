#include "LinkedList.h"

// 새로운 노드를 생성하고 초기화하는 함수
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node)); // 메모리 할당

	NewNode->Data = NewData; // 데이터를 저장
	NewNode->NextNode = NULL; // 다음 노드 포인터 초기화

	return NewNode; // 생성된 노드 반환
}

// 노드 소멸
void SLL_DestroyNode(Node* Node) {
	free(Node); // 노드 메모리 해제
}

// 리스트 끝에 새 노드를 추가하는 함수
void SLL_AppendNode(Node** Head, Node* NewNode) {
	// 헤드가 NULL이면 새로운 노드가 헤드가 됨
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		// 마지막 노드를 찾아서 새 노드를 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// 특정 노드 뒤에 새 노드를 삽입하는 함수
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode; // 새 노드의 다음을 현재 노드의 다음으로 설정
	Current->NextNode = NewNode;           // 현재 노드의 다음을 새 노드로 설정
}

// 리스트의 시작 부분에 새 노드를 삽입하는 함수
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	NewHead->NextNode = (*Head); // 새 노드의 다음을 기존 헤드로 설정
	(*Head) = NewHead;           // 헤드를 새 노드로 업데이트
}

// 특정 노드를 리스트에서 삭제하는 함수
void SLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode; // 삭제할 노드가 헤드라면, 다음 노드를 헤드로 설정
	}
	else {
		// 삭제할 노드의 이전 노드를 찾아서 다음 노드 연결 변경
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// 리스트에서 특정 위치의 노드를 반환하는 함수
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	// 지정된 위치까지 반복해서 이동
	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

// 리스트의 노드 개수를 세는 함수
int SLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}