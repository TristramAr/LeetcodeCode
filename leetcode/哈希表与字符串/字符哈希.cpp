#include<iostream>
#include<string>
using namespace std;

int main()
{
    //ASC2码从0-127,
    int char_map[128] = {0};
    string str = "aabbssscccddee";
    //统计字符串中各字符的个数
    for (int i = 0; i < str.length();i++)
    {
        char_map[str[i]]++;
    }
    for (int i = 0; i < 128;i++)
    {
        if(char_map[i]>0)
        {
            char str = i;
            cout <<str<<'['<< i<<']' << char_map[i] << endl;
           
        }
    }
}