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

### LinkedQueue (연결 리스트 큐) - C 구현

1. **큐 생성 및 초기화**
   - `LinkedQueue` 구조체는 `Front`, `Rear`, `Count` 필드를 통해 큐를 정의
   - `LQ_CreateQueue` 함수로 큐를 초기화하여 생성

2. **큐 데이터 추가 및 제거**
   - `LQ_Enqueue`로 큐의 끝에 데이터 추가, `LQ_Dequeue`로 큐의 앞에서 데이터 제거

3. **큐 상태 확인**
   - `LQ_IsEmpty`로 큐가 비어있는지 확인

4. **큐 해제**
   - `LQ_DestroyQueue`로 큐와 저장된 노드를 메모리에서 해제
   
---

### LCRS Tree (좌측 자식, 우측 형제 트리) - C 구현

1. **LCRS 트리 구조**
   - `LCRSNode` 구조체는 `LeftChild`와 `RightSilbling` 포인터로 트리를 정의
   - `Data` 필드로 각 노드에 저장된 데이터를 나타냄

2. **트리 생성 및 소멸 함수**
   - `LCRS_CreateNode`로 노드를 생성, `LCRS_DestroyTree`로 트리 전체 소멸

3. **노드 추가 및 출력**
   - `LCRS_AddChildNode`로 부모 노드에 자식 노드 추가
   - `LCRS_PrintTree`로 트리를 들여쓰기 형태로 출력하여 구조 시각화

4. **트리 해제**
   - `LCRS_DestroyTree`로 트리와 저장된 노드를 메모리에서 해제

---

### BinaryTree (이진 트리) - C 구현

1. **이진 트리 구조**
   - `SBTNode` 구조체는 `Left`, `Right` 포인터로 자식 노드를 연결
   - `Data` 필드로 각 노드의 데이터를 저장

2. **트리 생성 및 소멸 함수**
   - `SBT_CreateNode`로 노드를 생성하고, `SBT_DestroyTree`로 트리 전체를 소멸

3. **트리 순회 및 출력**
   - `SBT_PreorderPrintTree`, `SBT_InorderPrintTree`, `SBT_PostorderPrintTree`로 전위, 중위, 후위 순회로 출력

4. **트리 해제**
   - `SBT_DestroyTree`로 트리와 저장된 노드를 메모리에서 해제

---

### ExpressionTree (수식 트리) - C 구현

1. **수식 트리 구조**
   - `ETNode` 구조체는 `Left`, `Right` 포인터로 자식 노드를 연결
   - `Data` 필드로 연산자 또는 피연산자를 저장하여 수식 트리를 구성

2. **트리 생성 및 소멸 함수**
   - `ET_CreateNode`로 노드를 생성, `ET_DestroyTree`로 트리 전체 소멸

3. **수식 트리 순회 및 출력**
   - `ET_PreorderPrintTree`, `ET_InorderPrintTree`, `ET_PostorderPrintTree`로 전위, 중위, 후위 순회 출력

4. **수식 트리 생성 및 평가**
   - `ET_BuildExpressionTree`로 후위 표기식에서 트리 생성, `ET_Evaluate`로 수식 평가

---

### DisjointSet (분리 집합) - C 구현

1. **분리 집합 구조**
   - `DisjointSet` 구조체는 `Parent` 포인터로 부모 노드를 연결하며, 분리 집합을 나타냄
   - `Data` 필드로 각 노드에 저장된 데이터를 보관

2. **집합 생성 및 소멸 함수**
   - `DS_MakeSet`로 새로운 집합을 생성하고, `DS_DestroySet`로 집합 소멸

3. **집합 연산 함수**
   - `DS_UnionSet`로 두 집합을 합치고, `DS_FindSet`로 대표 노드를 찾아 집합을 확인

4. **사용 예제**
   - `main` 함수에서 집합 생성, 합치기, 비교 예제를 포함

---

### Bubble Sort (버블 정렬) - C 구현

1. **정렬할 배열 초기화**
   - `DataSet` 배열에 정렬할 숫자 데이터 저장

2. **버블 정렬 구현**
   - 외부 반복문으로 각 배열 요소를 순회하며, 내부 반복문을 통해 인접한 두 요소를 비교
   - 작은 요소를 앞으로 이동시켜 배열을 오름차순으로 정렬

3. **배열 출력**
   - 정렬된 배열을 출력하여 결과 확인

4. **정렬 결과**
   - 버블 정렬로 배열을 오름차순으로 정렬하여 출력

---

### 버블 정렬을 이용한 점수 데이터 정렬

1. **Score 구조체 및 데이터 배열**
   - `Score.h` 파일에 `Score` 구조체 정의와 데이터 배열이 포함

2. **버블 정렬 함수 구현**
   - `BubbleSort` 함수는 `Score` 구조체 배열을 `score` 필드를 기준으로 오름차순 정렬

3. **정렬 시간 측정**
   - `clock()` 함수를 사용하여 정렬에 소요된 시간을 측정

4. **메인 함수에서의 작업**
   - 데이터 배열의 길이를 계산하고, `BubbleSort` 함수를 호출하여 데이터 정렬 실행
   - 정렬된 배열의 첫 10개와 마지막 10개의 데이터를 출력
   - 전체 정렬 시간 출력
