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
   
---

### ArrayStack (배열 기반 스택) - C 구현

1. **스택 생성 및 초기화**
   - `ArrayStack` 구조체는 `Capacity`, `Top`, `Nodes` 배열을 통해 스택을 정의
   - `AS_CreateStack(ArrayStack** Stack, int Capacity)`로 주어진 용량으로 스택 초기화

2. **스택 데이터 추가 및 제거**
   - `AS_Push(ArrayStack* Stack, ElementType Data)`로 스택의 상단에 데이터 추가
   - `AS_Pop(ArrayStack* Stack)`로 상단 데이터 제거 후 반환

3. **스택 상단 데이터 확인 및 상태 체크**
   - `AS_Top(ArrayStack* Stack)`으로 최상위 데이터 확인
   - `AS_GetSize(ArrayStack* Stack)`로 스택 크기 확인
   - `AS_IsEmpty(ArrayStack* Stack)`으로 스택 비어있는지 확인

4. **스택 해제**
   - `AS_DestroyStack(ArrayStack* Stack)`로 메모리 해제

---

### LinkedListStack (연결 리스트 스택) - C 구현

1. **스택 생성 및 초기화**
   - `LinkedListStack` 구조체는 `Count`, `List`, `Top` 필드를 통해 스택을 정의
   - `LLS_CreateStack(LinkedListStack** Stack)`으로 스택 초기화

2. **스택 데이터 추가 및 제거**
   - `LLS_Push(LinkedListStack* Stack, Node* NewNode)`로 스택의 상단에 데이터 추가
   - `LLS_Pop(LinkedListStack* Stack)`으로 상단 데이터 제거 후 반환

3. **스택 상단 데이터 확인 및 상태 체크**
   - `LLS_Top(LinkedListStack* Stack)`으로 최상위 데이터 확인
   - `LLS_GetSize(LinkedListStack* Stack)`으로 스택 크기 확인
   - `LLS_IsEmpty(LinkedListStack* Stack)`으로 스택이 비어있는지 확인

4. **스택 해제**
   - `LLS_DestroyStack(LinkedListStack* Stack)`로 메모리 해제

---

### LinkedListStack 기반 계산기 프로그램 - C 구현

1. **LinkedListStack 구조**
   - `Node` 구조체는 문자열 데이터를 저장하고 `NextNode`로 다음 노드를 참조
   - `LinkedListStack` 구조체는 `List`와 `Top` 포인터로 스택 정의

2. **스택 연산 함수**
   - `LLS_Push`로 스택에 데이터 추가, `LLS_Pop`로 데이터 제거, `LLS_Top`으로 최상단 데이터 확인

3. **중위 표현식 변환 및 계산**
   - `GetPostfix`로 중위 표현식을 후위 표현식으로 변환
   - `Calculate`로 후위 표현식을 계산하여 최종 결과 반환

4. **유틸리티 함수**
   - `IsNumber`, `GetNextToken`, `IsPrior` 등의 함수로 토큰 판별 및 우선순위 비교

---

### CircularQueue (원형 큐) - C 구현

1. **큐 생성 및 초기화**
   - `CircularQueue` 구조체는 `Capacity`, `Front`, `Rear`와 `Nodes` 배열로 큐를 정의
   - `CQ_CreateQueue` 함수로 지정된 용량의 큐를 생성하고 초기화

2. **큐 데이터 추가 및 제거**
   - `CQ_Enqueue`로 큐의 끝에 데이터 추가, `CQ_Dequeue`로 큐의 앞에서 데이터 제거

3. **큐 상태 확인**
   - `CQ_GetSize`로 현재 큐의 크기 확인
   - `CQ_IsEmpty`로 큐가 비어있는지, `CQ_IsFull`로 큐가 가득 찼는지 확인

4. **큐 해제**
   - `CQ_DestroyQueue`로 큐와 저장된 노드를 메모리에서 해제

---

