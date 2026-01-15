#include <iostream>
using namespace std;
//引用的使用场景：函数参数传递，函数返回值
void swap_c(int* p1,int* p2)//C语言要修改函数外部的变量，必须传递变量的地址，通过指针直接操作内存中的值
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_cpp(int &r1,int &r2)//引用跟取地址无关，只是给变量起了一个别名，这里的&是引用符号
{
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}

void swap(int r1,int r2)//这里仅是值传递，无法修改函数外部的变量，相当于开辟新内存空间人r1,r2,把ab的值赋给它们，改变了r1,r2并不影响a,b
{
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}

int count1()//传值返回，返回一个临时变量，多产生一个空间
{
    static int c = 0;//static影响生命周期，不影响存取权限
    c++;
    return c;
}

int &count2()//传引用返回，返回一个变量的别名，可以通过这个别名修改变量的值
{
    static int c = 0;//普通局部变量放在栈中，函数调用结束后就释放了，不能返回局部变量的引用
    c++;            //static修饰的局部变量放在静态区，函数调用结束后依然存在，整个运行周期内都存在
    return c;
}

int main()
{
    int a = 0,b = 1;
    swap_c(&a,&b);//这里的&取地址符号，不是引用符号
    swap_cpp(a,b);
    return 0;
}
