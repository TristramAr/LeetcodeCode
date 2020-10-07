#include <iostream>
#include <map>
#include <string>
using namespace std;

class CStudent
{
public:
    struct CInfo
    {
        int id;
        string name;
    };
    int score;
    CInfo info;
};

typedef multimap<int, CStudent::CInfo> MAP_STD;   // 定义multimap容器，并实例化
int main()
{
    MAP_STD mp;   // 定义MAP_STD对象
    CStudent st;
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "Add")
        {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(MAP_STD::value_type(st.score, st.info));   // 插入学生信息，pair模板类对象
            // mp.insert(make_pair(st.score, st.info));     和上一行同样的操作
        }
        else if (cmd == "Query")
        {
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);        // 查找比score小的最高分 
            if (p != mp.begin())
            {
                --p;
                score = p->first;          
                MAP_STD::iterator maxp = p;
                int maxld = p->second.id;
                for (; p != mp.begin() && p->first == score; --p)
                {
                    //遍历所有成绩和score相等的学生，判断学号大小进行更新
                    if (p->second.id > maxld)
                    {
                        maxp = p;
                        maxld = p->second.id;
                    }
                }
                if (p->first == score)
                {
                    if (p->second.id > maxld)
                    {
                        maxld = p->second.id;
                    }
                }
                cout << maxp->second.name << " " << maxp->second.id << " " << maxp->first << endl;
            }
            else
            {
                cout << "Nobody" << endl;
            }
            
        }
    }
    return 0;
}
