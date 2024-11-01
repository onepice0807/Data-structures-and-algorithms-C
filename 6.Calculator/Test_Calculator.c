#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main(void) {
    char InfixExpression[100];
    char PostfixExpression[100];
    double Result = 0.0;

    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    printf("Enter Infix Expression: ");
    scanf("%99s", InfixExpression); // 사용자로부터 중위 표현식 입력 받기

    // 중위 표현식을 후위 표현식으로 변환
    GetPostfix(InfixExpression, PostfixExpression);

    printf("Infix: %s\nPostfix: %s\n", InfixExpression, PostfixExpression);

    // 후위 표현식을 계산
    Result = Calculate(PostfixExpression);

    printf("Calculation Result: %f\n", Result);

    return 0;
}
