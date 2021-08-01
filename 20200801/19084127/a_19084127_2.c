#include <stdio.h>
// ���� bool ��ͷ�ļ�
#include <stdbool.h>

// ����һ��Ԫ��Ϊÿ�¶�Ӧ����������
int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    //�ж��Ƿ�������
    if (year % 100 != 0)
    {
        if (year % 4 == 0)
        {
            // �������⣬������4��Ϊ����
            return true;
        }
    }
    else if (year % 400 == 0)
    {
        // ������Ҫ����400��Ϊ����
        return true;
    }
    // ����֮�����������
    return false;
}

bool is_at_range(int year, int month, int day)
{
    // �ж��Ƿ�������ȷ������
    if (is_leap_year(year))
    {
        // �������꣬2����29��
        month_day[1] = 29;
    }

    if (month >= 1 && month <= 12 && day >= 1 && day <= month_day[month - 1])
    {
        // �º��վ��ڷ�Χ�ڣ�Ϊ��ȷ������
        return true;
    }
    // ������ȷ������
    return false;
}

int sum_day(int year, int month, int day)
{
    // �����ǵڼ���
    if (is_at_range(year, month, day))
    {
        // ����ȷ������
        int days;

        // ѭ������ÿ�¶�Ӧ����
        for (int i = 0; i < month - 1; i++)
        {
            days += month_day[i];
        }
        // ÿ�¶�Ӧ�����������ڵ��գ��õ�����������һ��ĵڼ���
        return days + day;
    }
    // ������ȷ�����ڣ���ֹ����
    printf("��������һ����������ڣ��޷�����");
    exit(1);
}

int main(int argc, char const *argv[])
{
    printf("����������Ҫ��������ڣ�����2001.1.1\n :");
    int year, month, day;
    // ��������
    scanf("%d.%d.%d", &year, &month, &day);
    // ���ú���������
    int days = sum_day(year, month, day);
    // ������
    printf("������һ��ĵ�%d��", days);

    return 0;
}
