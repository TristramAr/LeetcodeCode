#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>

using namespace std;

int main()
{
    // string 类有很多成员函数，在进行字符串的操作是可以回看视频
    string s(8, 'x');
    string s2("hello");
    string s3 = "mike";
    cout << s << endl;
    string s4 = s2 +" "+ s3;
    cout << s4 << endl;
    s4.find_first_not_of("a");

}
