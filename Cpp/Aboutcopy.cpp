//sample.cpp
/*副本构造器
 * 1。可以把一个对象赋值给一个类型与之相同的变量
 * 2。编译器将生成必要的代码把“源”对象各属性的值分别赋值给“目标”对象的对应成员
 *    这种赋值行为称之为逐位复制（bitwise copy）
 * 3。在绝大多数的情况下这种行为没什么问题，但如果某些成员变量是指针的话，问题是
 *    对象成员逐位复制的结果是你将拥有两个一模一样的实例，而这两个副本里的同名指针会
 *    指向相同的地址。
 *    这样当删除其中一个对象的它包含的指针也将被删除，但万一此时另一个副本（对象）
 *    还在引用这个指针就会出现问题。
 * 那么怎样才能截获这个赋值操作并告诉它应该如何处理那些指针呢？
 *    方法是：拷贝赋值函数--对操作符进行重载，并对其指针进行处理。
 * */
#include <iostream>
#include <string>
class MyClass
{
public:
    MyClass(int *p);
    ~MyClass();
    MyClass(const MyClass &rhs); //拷贝构造函数
    MyClass &operator=(const MyClass &rhs);
    /*类的赋值函数operator=()也是一种拷贝函数，当然也可以重载，如果
   *赋值函数的参数类型就是当前类，那么就是类的拷贝赋值函数.
   *拷贝赋值函数。拷贝构造函数和拷贝赋值函数的输入参数必须是同类对象的
   *引用，而不是对象值。
   */

    void print();

private:
    int *ptr;
};
MyClass::MyClass(int *p)
{
    ptr = p; //构造函数执行初始化动作
}
MyClass::MyClass(const MyClass &rhs) //拷贝构造函数
{
    *this = rhs; //此处等号已经被重载了
}
MyClass::~MyClass()
{
    delete ptr;
}
MyClass &MyClass::operator=(const MyClass &rhs)
{
    if (this != &rhs) //a=b
    {
        delete ptr;      //删除原来的指针a的对象指针ptr占据的空间
        ptr = new int;   //给a的指针重新分配空间
        *ptr = *rhs.ptr; //将b的指针所指的内存空间的值赋给a,而没有将地址赋值给a的指针
                         //这样的结果是a，b指向的地址空间是不一样的，但地址空间所存放的内容是一样
    }
    else //a=a//检查是否是自赋值
    {
        std::cout << "赋值号两边为同个对象，不做处理！\n";
        //obj1=obj1;
    }
    return *this;
}
void MyClass::print()
{
    std::cout << *ptr << std::endl;
}

int main()
{
    MyClass obj1(new int(1));
    MyClass obj2(new int(2));
    obj1.print();
    obj2.print();
    obj1 = obj2;
    obj1.print();
    obj2.print();
    //复习执行上面一步后，开始执行析构函数
    //遵循先构造后析构
    return 0;
}
/*上面的程序还有些bug
 * 例如改写下测试代码
 * MyClass obj1;
 * MyClass obj2=obj1;
 * 这样是先创建一个实例obj1,然后再创建实例obj2的
 * 同时用obj1的值对它进行初始化
 * 这与上面的代码区别很细微，编译器却作出了不一样的动作：
 *编译器将在MyClass类里寻找一个副本构造器，如果找不到，它会自行创建一个。
 换句话说：如果遇到上面这样的代码，即使已经在这个类里重载了赋值操作符，暗含着隐患的“逐位复制”的行为还是会发生。
 方法是拷贝构造函数
 * */
