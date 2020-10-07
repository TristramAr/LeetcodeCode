#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long ans = 0;
    string s="ABZ";
    // cin >> s;

    int len = s.size();
    for (int i = 0, j = 1; i < s.size(); i++, j *= 26)
    {
        ans += (s[len - i - 1] - 64) * j;    //其实值A为1，并不是从0开始，所以这边是字符的asc码减去64
    }
    cout << ans << endl; //26进制转十进制

    string str = "";
    while (ans > 0)
    {
        int m = ans % 26;
        if (m == 0)
            m = 26;
        str += (char)(m + 64);
        ans = (ans - m) / 26;
    }
    reverse(str.begin(), str.end()); //反序
    cout << str << endl;             //	十进制转26进制
    return 0;
}