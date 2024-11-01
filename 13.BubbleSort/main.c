#include <stdio.h>

int main(void) {
    // 정렬할 배열 정의
    int DataSet[] = { 10, 8, 7, 1 };
    int Length = sizeof(DataSet) / sizeof(DataSet[0]); // 배열의 길이 계산
    int i = 0;
    int j = 0;
    int temp = 0; // 두 값을 교환하기 위한 임시 변수

    // 버블 정렬 로직 시작
    for (i = 0; i < Length - 1; i++) { // 배열의 각 요소를 반복
        for (j = 0; j < Length - 1 - i; j++) { // 이미 정렬된 마지막 요소는 제외하고 반복
            if (DataSet[j] > DataSet[j + 1]) { // 인접한 두 요소 비교
                // 요소를 교환하여 정렬 순서 유지
                temp = DataSet[j];
                DataSet[j] = DataSet[j + 1];
                DataSet[j + 1] = temp;
            }
        }
    }

    // 정렬된 배열 출력
    for (i = 0; i < Length; i++) {
        printf("%d ", DataSet[i]); // 정렬된 요소 출력
    }
    printf("\n"); // 줄바꿈

    return 0;
}
