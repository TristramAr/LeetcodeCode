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
    CStudent s;
    fstream iofile("E:\\VS-Code\\VS-Code-C\\student.dat",ios::in|ios::out|ios::binary);
    if(!iofile)
    {
        cout<<"error";
        return 0;
    }
    iofile.seekp(1*sizeof(s),ios::beg);  //定位写指针到修改位置
    iofile.write("mike",strlen("mike")+1);
    iofile.seekg(0,ios::beg);
    while(iofile.read((char*)&s,sizeof(s)))
    {
        cout<<s.szName<<" "<<s.nScore<<endl;
    }
    iofile.close();
    return 0;
}