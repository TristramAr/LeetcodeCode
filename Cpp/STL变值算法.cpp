#include<vector>
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<numeric>

using namespace std;

class CLessThen9{
    public:
        bool operator()(int n) { return n < 9; }
};

void outputSquare(int value) { cout << value * value<<" "; }
int calculateCube(int value) { return value * value * value; }

int main()
{
    const int SIZE = 10;
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {100, 2, 8, 1, 50, 3, 8, 9, 10, 2};
    vector<int> v(a1, a1 + SIZE);
    ostream_iterator<int> output(cout, " ");
    random_shuffle(v.begin(), v.end());     
    cout << endl << "1)";
    copy(v.begin(), v.end(), output);     //用copy实现输出应用
    copy(a2, a2 + SIZE, v.begin());
    cout << endl << "2)";
    cout << count(v.begin(), v.end(), 8);                 //输出某一个值的个数
    cout << endl << "3)";
    cout << count_if(v.begin(), v.end(), CLessThen9());   //输出满足条件的值的个数
    cout << endl << "4)";
    cout << *(min_element(v.begin(), v.end()));           //输出区间内元素的最小值
    cout << endl << "5)";
    cout << *(max_element(v.begin(), v.end()));
    cout << endl << "6)";
    cout << accumulate(v.begin(), v.end(), 0);    //求和，初始值0
    cout << endl << "7)";
    for_each(v.begin(), v.end(), outputSquare);   //对每一个元素进行平方操作
    vector<int> cubes(SIZE);
    transform(a1, a1 + SIZE, cubes.begin(), calculateCube);
    cout << endl << "8)";
    copy(cubes.begin(), cubes.end(), output);
    return 0;

}
