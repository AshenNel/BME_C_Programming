# 2020年8月1日
**请用Git提交你的回答**  
>将你的源文件按照"a_学号_题目编号"命名，并将此次问题放入命名为你学号的文件夹，提交到对应的日期文件夹内。  
>例如：19084127文件夹内包含有 a_19084127_1.c，将其上传到20200802文件夹内。  

**问题：**
## 1. 计算$\pi$的值
>请编写一个**C语言函数 fun**，它的功能是：根据下面的公式求得$\pi$的值。

$$
    \dfrac{\pi}{2}\,=\,1\,+\,\dfrac{1\times2}{3\times5}\,+\,\dfrac{1\times2\times3}{3\times5\times7}\,+\,\dfrac{1\times2\times3\times4}{3\times5\times7\times9}\,+\,\ldots\,+\,\dfrac{1\times2\times\ldots\times n}{3\times5\times\ldots\times\left(2n+1\right)}
$$

>要求满足精度0.0005，即某项小于0.005时停止迭代。  
>程序运行后，如果输入精度0.0005, 则程序输出为3.140578。  
>该程序其他部分将在下面给出:
```c
#include <stdio.h>
#include <math.h>

double fun(double eps)
{
    
}

int main(int argc, char const *argv[])
{
    printf("Input eps:");
    double x;
    scanf("%lf", &x);
    printf("\neps = %lf, PI = %lf\n", x, fun(x));

    return 0;
}
```
>注意事项:
>1.**程序其他部分已给出**，你仅需要编写`fun`函数  
>2.你编写的`fun`函数需要包括必要的注释，但不必处处注释  
>3.请勿改动程序其他部分中的任何内容，仅在`fun`函数的花括号内填入你编写的若干语句  
>4.请在编写完成后上传包含有**完整程序**的源文件