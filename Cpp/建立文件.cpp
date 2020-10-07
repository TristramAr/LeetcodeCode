#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class CStudent{
    public:
    char szName[20];
    int nScore;
};

int main()
{
    //写入文件，不要包含中文路径
    CStudent s;
    ofstream OutFile("E:\\VS-Code\\VS-Code-C\\student.dat",ios::out|ios::binary);
    while(cin>>s.szName>>s.nScore)
    {
        if(stricmp(s.szName,"exit")==0)    //如果输入为exit 则break
        {
            break;
        }
        OutFile.write((char*)&s,sizeof(s));
    }
    OutFile.close();
// 读取文件
    // CStudent s;
    // ifstream inFile("E:\\VS-Code\\VS-Code-C\\student.dat",ios::in|ios::binary);
    // if(!inFile){
    //     cout<<"error"<<endl;
    //     return 0;
    // }
    // while(inFile.read((char*)&s,sizeof(s)))
    // {
    //     int nReadedBytes= inFile.gcount();
    //     cout<<s.szName<<""<<s.nScore<<endl;
    // }
    // inFile.close();


    return 0;
}