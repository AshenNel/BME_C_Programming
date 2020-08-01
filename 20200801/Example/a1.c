#include <stdio.h>

int max_com_div(int num1, int num2)
{
    // �����Լ��
    int temp;

    while (num2 != 0)
    {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }

    return num1;
}

int min_com_mul(int num1, int num2)
{
    // ������С������
    // ������˳������Լ�����õ���С������
    return (num1 * num2) / (max_com_div(num1, num2));
}

int main(int argc, char const *argv[])
{
    printf("����������Ҫ�õ���С��������������:");
    int input1, input2;
    // ��������
    scanf("%d %d", &input1, &input2);
    // ���ú���������
    int com_mul = min_com_mul(input1, input2);
    // ������
    printf("��С�������ǣ�%d", com_mul);

    return 0;
}