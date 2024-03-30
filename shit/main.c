#include <stdio.h>
#include <locale.h> 

#define errorInput printf("      !!!ERROR!!!\n  !!!������������ ����!!!\n");
#define errorMaxDivisor printf("                 !!!ERROR!!!\n!!!��� ��������� ������ ������������� ��������!!!\n");
#define errorZeroDivision printf("      !!!ERROR!!!\n  !!!������� �� ����!!!\n");



float function1(float a, float b)   // '+' 
{
    return a + b;
}

float function2(float a, float b)   // '-'
{
    return a - b;
}

float function3(float a, float b)   // '*'
{
    return a * b;
}

float function4(float a, float b)   // '/'  
{
    return a / b;
}

float function5(float a, float b)   // '%'
{
    return (int)a % (int)b;
}

float function6(int a, int b)      // ��� (#)
{
    /*                               ~~~�������� ������ ���~~~
    --------------------------------------------------------------------------------------------------
    (1)�� ���� ������ ����� ������� ����� ����� �� �������.
    (2)�����, ������� ����� ����� �� �������, ������������ �� ������� �������� ����� �� �������.
    (3)�����, ������ ������� ����� �� ������ �������, 
    ������� ��������� �� ������� �������� ����� �� ������ �������.
    (4)������ ������� ����� �� ������, ������� ��������� �� ������� ������� ������� �� ������ � �. �.
    (5)����� ������� ������� ������������ �� ��� ���, ���� � ������� �� ��������� ����. 
    ��������� �������� ��� ��� � ����� ���������� ����� ���������.
    --------------------------------------------------------------------------------------------------
    */
 
    if (a < b)
    {
        int aRb;
        aRb = a;
        a = b;
        b = aRb;
    }

    if (b == 0)
    {
        return a;
    }

    return function6(b, a % b);
}

int main()  // ������� ������� 
{
    setlocale(LC_ALL, "Rus");

    int sch = 0;
    float num1, num2; // ���������� ����� 1 � 2
    char operation; // ���������� �������� 

    printf("������ ������������:\n");
    printf("(1)���� ������� ����� -> (2)���� ������� ����� -> (3)���� �������� -> (4)���������\n");
    printf("\n");

    printf("(1)������� ������ �����:\n");
    scanf_s("%f", &num1);

    printf("(2)������� ������ �����:\n");
    scanf_s("%f", &num2);

    printf("(3)������� �������� (+, -, *, / - �������, %% - ������� �� �������, ���(#) - ���������� ����� �������� �� ������):\n ");
    scanf_s(" %c", &operation);

    switch (operation) { // �������� 
    case '+':
        printf("(4) ����� = %.3f\n", function1(num1, num2));
        printf("\n");
        break;
    case '-':
        printf("(4) ����� = %.3f\n", function2(num1, num2));
        printf("\n");
        break;
    case '*':
        printf("(4) ����� = %.3f\n", function3(num1, num2));
        printf("\n");
        break;
    case '/':
        if (num2 != 0)
        {
            printf("(4) ����� = %.3f\n", function4(num1, num2));
            printf("\n");
            break;
        }
        if (num2 == 0)
        {
            sch = 3;  // ��������� ������
            break;
            
        }
    case '%':
        if (num2 != 0)
        {
            printf("(4)����� = %.3f\n", function5(num1, num2));
            printf("\n");
            break;
        }
        if (num2 == 0)
        {
            sch = 3; // ��������� ������
            break;
            
        }
    case '#':
        
        if (num1 < 0) // |num1|
        {
            num1 = -1 * num1;
        }
        
        if (num2 < 0) // |num2|
        {
            num2 = -1 * num2;
        }

        

        if ((num1 == (int)num1) & (num2 == (int)num2) & (num1 != 0) & (num2 != 0)) {
            printf("(4)����� = ���(%.0f � %.0f) = %0.f\n", num1, num2, function6(num1, num2));
            printf("\n");
            break;
        }
        
        if ((num1 != (int)num1) || (num2 != (int)num2) || (num1 == 0) || (num2 == 0)); // ��������� ������
        {
            sch = 2;
            break;

        }
        
        
    default:  // ��������� ������
        sch = 1;
        break;
        
    }
    switch (sch) {  // �������� ������� ���
        case 1:
            errorInput;
            printf("\n");
            printf("�����: ��������� ������������ ��������� ����� � ��������.\n");
            break;
        case 2:
            errorMaxDivisor;
            printf("\n");
            printf("�����: ����������� ����� ������������� ����� ����������\n");
            printf("\n");
            break;
        case 3:
            errorZeroDivision;
            printf("\n");
            printf("�����: �� ���� �� ���� ����");
            printf("\n");
            break;
        default:
            break;
    }

    return 0;
}