#include <stdio.h>

int main(void) {
    // ������ �迭 ����
    int DataSet[] = { 10, 8, 7, 1 };
    int Length = sizeof(DataSet) / sizeof(DataSet[0]); // �迭�� ���� ���
    int i = 0;
    int j = 0;
    int temp = 0; // �� ���� ��ȯ�ϱ� ���� �ӽ� ����

    // ���� ���� ���� ����
    for (i = 0; i < Length - 1; i++) { // �迭�� �� ��Ҹ� �ݺ�
        for (j = 0; j < Length - 1 - i; j++) { // �̹� ���ĵ� ������ ��Ҵ� �����ϰ� �ݺ�
            if (DataSet[j] > DataSet[j + 1]) { // ������ �� ��� ��
                // ��Ҹ� ��ȯ�Ͽ� ���� ���� ����
                temp = DataSet[j];
                DataSet[j] = DataSet[j + 1];
                DataSet[j + 1] = temp;
            }
        }
    }

    // ���ĵ� �迭 ���
    for (i = 0; i < Length; i++) {
        printf("%d ", DataSet[i]); // ���ĵ� ��� ���
    }
    printf("\n"); // �ٹٲ�

    return 0;
}
