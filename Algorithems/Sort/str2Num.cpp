#include<iostream>
using namespace std;
int main()
{
    string s = "123456";
    int num = 0;
    for (int i =0; i <s.length();i++)
    {
        num = num * 10 + (s[i] - '0');   
    }
    cout << num << endl;
    return 0;
}