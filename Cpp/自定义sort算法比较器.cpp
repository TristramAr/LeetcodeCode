#include<iostream>
#include<algorithm>
using namespace std;

class MyLess{
    public:
        bool operator()(int n1, int n2)   
        {
            return (n1 % 10) < (n2 % 10);  //比较个位数大小，小为true
        }
};
// sort 默认按照从小到大排序
int main()
{
    int a[] = {14, 2, 9, 111, 78};
    sort(a, a + 5, MyLess());           //按个位数大小排序
    int i;
    for (i = 0; i < 5;i++)
    {
        cout << a[i] << " ";
    }
    cout<< endl;
    sort(a, a + 5, greater<int>());   //按大到小的排序
    for (i = 0; i < 5;i++)
    {
        cout << a[i] << " ";
    }
}