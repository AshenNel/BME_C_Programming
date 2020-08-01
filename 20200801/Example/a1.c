#include <stdio.h>

int max_com_div(int num1, int num2)
{
    // 求最大公约数
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
    // 计算最小公倍数
    // 两数相乘除以最大公约数，得到最小公倍数
    return (num1 * num2) / (max_com_div(num1, num2));
}

int main(int argc, char const *argv[])
{
    printf("请输入你想要得到最小公倍数的两个数:");
    int input1, input2;
    // 输入数据
    scanf("%d %d", &input1, &input2);
    // 调用函数，计算
    int com_mul = min_com_mul(input1, input2);
    // 输出结果
    printf("最小公倍数是：%d", com_mul);

    return 0;
}