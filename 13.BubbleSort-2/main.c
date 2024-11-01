#include <stdio.h> 
#include "Score.h"
#include <time.h>

void BubbleSort(Score DataSet[], int Length)
{
    int i = 0; // �ܺ� �ݺ��� ���� ����
    int j = 0; // ���� �ݺ��� ���� ����
    Score temp = { 0, 0.0f }; // ��Ҹ� ��ȯ�ϱ� ���� �ӽ� ����

    // ���� ���� �˰���: �ܺ� �ݺ����� �迭�� ��� ��Ҹ� ��ȸ
    for (i = 0; i < Length - 1; i++)
    {
        // ���� �ݺ���: ���� ��Ҹ� ���Ͽ�, ū ��Ұ� �ڷ� ������ �迭�� ����
        for (j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j].score > DataSet[j + 1].score) // ���� ��Ұ� ���� ��Һ��� Ŭ ���
            {
                // �� ��Ҹ� ��ȯ�Ͽ� ���� ���� ����
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}

int main(void)
{
    int Length = sizeof(DataSet) / sizeof(DataSet[0]); // DataSet �迭�� ���� ���
    int i = 0; // �ݺ��� ���� ����

    clock_t startTime, endTime; // �ð� ������ ���� ���� ����
    float resultTime = 0.0f; // ���� ���� �ð� ���� ����

    startTime = clock(); // ���� ���� �ð� ���
    BubbleSort(DataSet, Length); // BubbleSort �Լ� ȣ���Ͽ� ���� ����
    endTime = clock(); // ���� ���� �ð� ���

    resultTime = (float)(endTime - startTime) / CLOCKS_PER_SEC; // ���� ���� �ð� ���

    // ���ĵ� �迭�� �� 10�� ��� ���
    for (int i = 0; i < 10; i++) {
        printf("DataSet[%d].number = %d, score = %lf\n", i, DataSet[i].number, DataSet[i].score);
    }

    printf("\n\n");

    // ���ĵ� �迭�� �� 10�� ��� ���
    for (int i = Length - 10; i < Length; i++) {
        printf("DataSet[%d].number = %d, score = %lf\n", i, DataSet[i].number, DataSet[i].score);
    }

    // ���Ŀ� �ҿ�� �ð� ���
    printf("�����Ʈ 3���� ������ ���� �ð�: %f\n", resultTime);

    printf("\n");

    return 0;
}
