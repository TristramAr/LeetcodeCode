#include <iostream>
#include <vector>
using namespace std;

void help(int n, int m, vector<int> a)
{
    cout << "n: " << n << endl;
    cout << "m: " << m << endl;
    for (auto i : a)
    {
        cout << i << " ";
        
    }
    cout << endl;
    cout << "----------" << endl;
}

int main()
{
    int k, n, m;
    vector<int> a;
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        cin >> n >> m;
        for (int j = 0; j < n;j++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        help(n, m, a);
        a.clear();
    }
        return 0;
}