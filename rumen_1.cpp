#include <iostream>
//在日常练习中，不在乎跟库命名冲突，可以把整个std展开，也可以单独展开某个东西
//常用的库里面的一些对象或者类型可以展出来，工程中用这种方式更好
using std::cout;
using std::endl;

//using namespace std;    //c++库中所有东西都是放放到std命名空间中的
void func(int a=0)    
{
    cout<<"a="<<a<<endl;
}

//全缺省参数
void func1(int a = 10,int b = 20)
{
    cout<<"a="<<a<<",b="<<b<<endl;
}

//半缺省（缺省部分参数），必须从右向左依次缺省
void func2(int a ,int b = 20)
{
    cout<<"a="<<a<<",b="<<b<<endl;
}

//函数重载，函数名相同，参数列表不同（参数个数不同0个也行，参数类型不同，参数顺序不同）
int func3(int i,int  ch)
{}
double func3(double i,double ch)
{}
void func3()
{}
//函数重载与返回值类型无关，只是返回值不同不能构成重载
/* void func3()
{}

int func3()
{} */

int main()
{
    //cout可以自动识别类型
    cout<<"hello world\n";    //\n表示换行符
    cout<<"hello world"<<endl;    //<<endl;表示输入一个换行符到cout,endl也属于std工作空间里
    int a=10;
    double b=3.14;
    std::cin >> a >> b;
    cout<<"a="<<a<<",b="<<b<<endl;

    //缺省参数
    func(100);//调用函数时传参数，必须从左往右依次传参
    func(); //调用函数时如果没有传参数，就使用缺省参数
    //全缺省
    func1();
    func1(50);
    func1(50,60);
    //半缺省
    func2(30);
    func2(30,40);

    return 0;
}

//c++如何支持函数重载的，为什么c语言不支持?
//1.预处理->展开头文件  2.编译->处理语法错误，将代码转化为汇编代码  3.汇编->将生成的汇编代码转化成二进制的机器指令  4.链接->将多个源文件链接起来
//c++编译器在编译阶段会对函数名进行改造（name mangling），把函数名和参数类型，参数个数等信息结合在一起，生成一个独一无二的函数标识符
//c语言编译器不会对函数名进行改造，所以不支持函数重载



//引用,给已有的变量取别名，共用一块空间
//int a=10;
//int &ra=a; //ra是a的引用，ra是a的别名,a再取了一个名称ra
//int &rb=a; //rb也是a的引用
//int &rc=ra; //rc是ra的引用，rc也是a的引用，即一个变量可以有多个引用
//类型后加&表示引用，变量前加&表示取地址
//引用必须初始化，引用一旦初始化后，就不能再改变引用的对象
//引用本质上是一个指针常量，指针常量在定义时必须初始化，且不能改变指向
//const int a =10; int &b=a; //编译不通过，原因是a是只读，b的类型是int 是可读可写的，要写成const int &b=a;
//int c = 1; int &d = c; const int &e = c; //可行，d可以修改c的值，e不可以通过e修改c的值，但可以通过c修改c的值
//总结：权限的缩小是允许的，放大是不允许的


//int i = 0;double d = i;隐式类型转换
//double &rd = i;
//float &rf = i;            不允许

//int i = 0;double d = i;
//const double &rd = i;
//const float &rf = i;           允许
//原因是隐式类型转换时，并没有把i直接赋值给d，而是构造了一个d的临时变量，然后把i的值赋值给这个临时变量，而临时变量具有常性，发生了权限的扩大