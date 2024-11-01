#include <stdio.h> 
#include "Score.h"
#include <time.h>

void BubbleSort(Score DataSet[], int Length)
{
    int i = 0; // 외부 반복문 제어 변수
    int j = 0; // 내부 반복문 제어 변수
    Score temp = { 0, 0.0f }; // 요소를 교환하기 위한 임시 변수

    // 버블 정렬 알고리즘: 외부 반복문은 배열의 모든 요소를 순회
    for (i = 0; i < Length - 1; i++)
    {
        // 내부 반복문: 인접 요소를 비교하여, 큰 요소가 뒤로 가도록 배열을 정렬
        for (j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j].score > DataSet[j + 1].score) // 현재 요소가 다음 요소보다 클 경우
            {
                // 두 요소를 교환하여 정렬 순서 유지
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}

int main(void)
{
    int Length = sizeof(DataSet) / sizeof(DataSet[0]); // DataSet 배열의 길이 계산
    int i = 0; // 반복문 제어 변수

    clock_t startTime, endTime; // 시간 측정을 위한 변수 선언
    float resultTime = 0.0f; // 정렬 수행 시간 저장 변수

    startTime = clock(); // 정렬 시작 시간 기록
    BubbleSort(DataSet, Length); // BubbleSort 함수 호출하여 정렬 수행
    endTime = clock(); // 정렬 종료 시간 기록

    resultTime = (float)(endTime - startTime) / CLOCKS_PER_SEC; // 정렬 수행 시간 계산

    // 정렬된 배열의 앞 10개 요소 출력
    for (int i = 0; i < 10; i++) {
        printf("DataSet[%d].number = %d, score = %lf\n", i, DataSet[i].number, DataSet[i].score);
    }

    printf("\n\n");

    // 정렬된 배열의 뒤 10개 요소 출력
    for (int i = Length - 10; i < Length; i++) {
        printf("DataSet[%d].number = %d, score = %lf\n", i, DataSet[i].number, DataSet[i].score);
    }

    // 정렬에 소요된 시간 출력
    printf("버블소트 3만개 데이터 소팅 시간: %f\n", resultTime);

    printf("\n");

    return 0;
}
