# 2020年8月1日
## 1. 最小公倍数  
>请编写一个 **完整的c语言程序** 用于计算两个正整数的最小公倍数。 
>
>注意事项:  
>1.你需要编写出完整的C语言程序  
>2.已指定输入的是正整数，无需再次进行判断  
>3.你编写的程序需要包括必要的注释，但不必处处注释  
  
难点解答：
>两数相乘除以最大公约数得到最小公倍数，难点在于求最大公约数。为了减少代码数量，示例中使用 **辗转相除法求最大公约数**  
>
>辗转相除法求最大公约数:  
>设有两整数 `x` 和 `y` ，  
>1.` x` 除以 `y` 得到余数 `z`  
>2.若 `z` 等于 `0` ，则 `y` 就是 `x` 和 `y` 的最小公倍数   
>3.若 `z` 不等于 `0` ，则 `x = y` , `y = z`， 返回执行第一步  
>
>例如，求27和15的最大公约数过程为：  
>27÷15,余12  
>15÷12,余3  
>12÷3,余0  
>因此，3即为27和15的最大公约数

参考示例：
```c
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
```
## 2. 确定好日子
>请编写一个 **完整的c语言程序** 用于确定某年某月某日是这一年的第几天  
>
>注意事项：  
>1.你需要编写出完整的C语言程序  
>2.你编写的程序需要包括必要的注释，但不必处处注释  
>3.已指定输入的是正整数，但可能输入的不是正确的日期，你需要将其甄别出来  
>4.请注意闰年和平年的区别

参考示例：
```c
#include <stdio.h>
// 包含 bool 的头文件
#include <stdbool.h>

// 定义一个元素为每月对应天数的数组
int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    //判断是否是闰年
    if (year % 100 != 0)
    {
        if (year % 4 == 0)
        {
            // 除百年外，能整除4的为闰年
            return true;
        }
    }
    else if (year % 400 == 0)
    {
        // 百年需要整除400才为闰年
        return true;
    }
    // 除此之外均不是闰年
    return false;
}

bool is_at_range(int year, int month, int day)
{
    // 判断是否输入正确的日期
    if (is_leap_year(year))
    {
        // 如是闰年，2月有29天
        month_day[1] = 29;
    }

    if (month >= 1 && month <= 12 && day >= 1 && day <= month_day[month - 1])
    {
        // 月和日均在范围内，为正确的日期
        return true;
    }
    // 不是正确的日期
    return false;
}

int sum_day(int year, int month, int day)
{
    // 计算是第几天
    if (is_at_range(year, month, day))
    {
        // 是正确的日期
        int days;

        // 循环加入每月对应天数
        for (int i = 0; i < month - 1; i++)
        {
            days += month_day[i];
        }
        // 每月对应天数加上日期的日，得到该日期在这一年的第几天
        return days + day;
    }
    // 不是正确的日期，终止程序
    printf("你输入了一个错误的日期，无法计算");
    exit(1);
}

int main(int argc, char const *argv[])
{
    printf("请输入你想要计算的日期，例如2001.1.1\n :");
    int year, month, day;
    // 输入数据
    scanf("%d.%d.%d", &year, &month, &day);
    // 调用函数，计算
    int days = sum_day(year, month, day);
    // 输出结果
    printf("这是这一年的第%d天", days);

    return 0;
}

```