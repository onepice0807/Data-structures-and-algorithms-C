# Data-structures-and-algorithms-C
C언어를 통한 자료구조 및 알고리즘 공부내용 정리

---

### LinkedList (단일 연결 리스트) - C 구현

1. **노드 생성 및 리스트 끝에 추가**
   - `Node` 구조체는 데이터를 저장하고 `NextNode`로 다음 노드를 참조
   - `SLL_CreateNode(ElementType data)`로 새로운 노드를 생성
   - `SLL_AppendNode(Node** head, Node* newNode)`로 리스트의 끝에 노드를 추가

2. **특정 위치 또는 리스트 시작에 노드 삽입**
   - `SLL_InsertAfter(Node* current, Node* newNode)`로 지정된 노드 뒤에 새 노드를 삽입
   - `SLL_InsertNewHead(Node** head, Node* newHead)`로 리스트의 시작 부분에 새 노드를 삽입

3. **특정 노드 제거 및 리스트 관리**
   - `SLL_RemoveNode(Node** head, Node* removeNode)`로 리스트에서 지정된 노드를 삭제
   - `SLL_GetNodeAt(Node* head, int location)`으로 특정 위치의 노드를 찾음

4. **노드 개수 세기 및 리스트 소멸**
   - `SLL_GetNodeCount(Node* head)`로 리스트의 모든 노드 수를 반환
   - `SLL_DestroyNode(Node* node)`로 노드를 메모리에서 해제
	
---

### DoublyLinkedList (이중 연결 리스트) - C 구현

1. **노드 생성 및 리스트 끝에 추가**
   - `Node` 구조체는 데이터를 저장하고 `PrevNode`, `NextNode`로 양쪽 노드를 참조
   - `DLL_CreateNode(ElementType data)`로 새로운 노드를 생성
   - `DLL_AppendNode(Node** head, Node* newNode)`로 리스트의 끝에 노드를 추가

2. **특정 위치 또는 리스트 시작에 노드 삽입**
   - `DLL_InsertAfter(Node* current, Node* newNode)`로 지정된 노드 뒤에 새 노드를 삽입

3. **특정 노드 제거**
   - `DLL_RemoveNode(Node** head, Node* removeNode)`로 리스트에서 지정된 노드를 삭제

4. **노드 개수 세기 및 특정 노드 탐색**
   - `DLL_GetNodeCount(Node* head)`로 리스트의 모든 노드를 카운트하여 반환
   - `DLL_GetNodeAt(Node* head, int location)`으로 특정 위치의 노드 탐색

5. **리스트 초기화**
   - `DLL_DestroyNode(Node* node)`로 노드를 제거하고 메모리를 해제
   
---

### CircularDoublyLinkedList (원형 이중 연결 리스트) - C 구현

1. **노드 생성 및 리스트 끝에 추가**
   - `Node` 구조체는 데이터를 저장하고 `PrevNode`, `NextNode`로 양쪽 노드를 참조
   - `CDLL_CreateNode(ElementType data)`로 새로운 노드를 생성
   - `CDLL_AppendNode(Node** head, Node* newNode)`로 리스트 끝에 노드를 추가하며 원형 연결

2. **특정 위치 또는 리스트 시작에 노드 삽입**
   - `CDLL_InsertAfter(Node* current, Node* newNode)`로 지정된 노드 뒤에 새 노드를 삽입

3. **특정 노드 제거**
   - `CDLL_RemoveNode(Node** head, Node* removeNode)`로 리스트에서 지정된 노드를 삭제

4. **노드 개수 세기 및 특정 노드 탐색**
   - `CDLL_GetNodeCount(Node* head)`로 원형 리스트의 모든 노드를 카운트하여 반환
   - `CDLL_GetNodeAt(Node* head, int location)`으로 특정 위치의 노드 탐색

5. **리스트 초기화**
   - `CDLL_DestroyNode(Node* node)`로 노드를 제거하고 메모리를 해제
