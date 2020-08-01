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
