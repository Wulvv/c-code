#include <iostream>
using namespace std;
//引用的使用场景：函数参数传递，函数返回值
void swap_c(int* p1,int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_cpp(int &r1,int &r2)
{
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}

int main()
{
    int a = 0,b = 1;
    swap_cpp(a,b);
    return 0;
}

