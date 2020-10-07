#include<iostream>
#include<algorithm>

#include<vector>

using namespace std;
int main()
{
    vector<int> vec1;
    vector<int> vec2;
    srand(time(NULL));
    for (int i = 0; i < 10000;i++)
    {
        int num = (rand() * rand() % 100003);
        vec1.push_back(num);
        vec2.push_back(num);
    }
}
