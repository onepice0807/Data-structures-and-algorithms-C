#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

// �������� Ȯ���ϴ� �Լ�
int IsNumber(char Cipher) {
    for (int i = 0; i < sizeof(NUMBER); i++) {
        if (Cipher == NUMBER[i]) return 1;
    }
    return 0;
}

// ���Ŀ��� ���� ��ū ����
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE) {
    unsigned int i = 0;
    for (i = 0; Expression[i] != '\0'; i++) {
        Token[i] = Expression[i];
        if (IsNumber(Expression[i])) {
            *TYPE = OPERAND;
            if (!IsNumber(Expression[i + 1])) break;
        }
        else {
            *TYPE = Expression[i];
            break;
        }
    }
    Token[++i] = '\0';
    return i;
}

// ���� ǥ������ ���� ǥ�������� ��ȯ
void GetPostfix(char* InfixExpression, char* PostfixExpression) {
    LinkedListStack* Stack;
    char Token[32];
    int Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    LLS_CreateStack(&Stack);

    while (Position < Length) {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == OPERAND) {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if (Type == RIGHT_PARENTHESIS) {
            while (!LLS_IsEmpty(Stack)) {
                Node* Popped = LLS_Pop(Stack);
                if (Popped->Data[0] == LEFT_PARENTHESIS) {
                    LLS_DestroyNode(Popped);
                    break;
                }
                else {
                    strcat(PostfixExpression, Popped->Data);
                    LLS_DestroyNode(Popped);
                }
            }
        }
        else {
            while (!LLS_IsEmpty(Stack) && IsPrior(LLS_Top(Stack)->Data[0], Token[0])) {
                Node* Popped = LLS_Pop(Stack);
                if (Popped->Data[0] != LEFT_PARENTHESIS)
                    strcat(PostfixExpression, Popped->Data);
                LLS_DestroyNode(Popped);
            }
            LLS_Push(Stack, LLS_CreateNode(Token));
        }
    }

    while (!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack);
        if (Popped->Data[0] != LEFT_PARENTHESIS)
            strcat(PostfixExpression, Popped->Data);
        LLS_DestroyNode(Popped);
    }

    LLS_DestroyStack(Stack);
}

// ���� ǥ���� ��� �Լ�
double Calculate(char* PostfixExpression) {
    LinkedListStack* Stack;
    Node* ResultNode;
    char Token[32];
    int Type = -1;
    unsigned int Read = 0;
    unsigned int Length = strlen(PostfixExpression);
    double Result;

    LLS_CreateStack(&Stack);

    while (Read < Length) {
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        if (Type == SPACE) continue;

        if (Type == OPERAND) {
            LLS_Push(Stack, LLS_CreateNode(Token));
        }
        else {
            Node* OperatorNode = LLS_Pop(Stack);
            double Operator2 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            OperatorNode = LLS_Pop(Stack);
            double Operator1 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            double TempResult;
            switch (Type) {
            case PLUS:     TempResult = Operator1 + Operator2; break;
            case MINUS:    TempResult = Operator1 - Operator2; break;
            case MULTIPLY: TempResult = Operator1 * Operator2; break;
            case DIVIDE:   TempResult = Operator1 / Operator2; break;
            }

            // ����� ���ڿ��� ��ȯ�Ͽ� ���ÿ� �ٽ� ����
            char ResultString[32];
            sprintf(ResultString, "%lf", TempResult);
            LLS_Push(Stack, LLS_CreateNode(ResultString));
        }
    }

    // ���� ��� ��� ����
    ResultNode = LLS_Pop(Stack);
    Result = atof(ResultNode->Data); // ����� �Ǽ������� ��ȯ
    LLS_DestroyNode(ResultNode);     // ��� ��� ����
    LLS_DestroyStack(Stack);         // ���� ����

    return Result;
}
