// mycopy src.dat dest.dat
#include<iostream>
#include<fstream>
using namespace std;

int main (int argc, char *argv[])    // argc参数个数 argv 参数字串
{
    if(argc!=3)
    {
        cout << "File name missing!" << endl;
        return 0;
    }
    ifstream inFile(argv[1], ios::binary | ios::in);    //打开文件用于读
    if(!inFile){
        cout << "source file open error" << endl;
        return 0;
    }
    ofstream outFile(argv[2], ios::binary | ios::out);  //打开文件用于写
    if(!outFile){
        cout << "new file open error" << endl;
        inFile.close();
        return 0;
    }
    char c;
    while(inFile.get(c))
    {
        outFile.put(c);
    }
    outFile.close();
    inFile.close();
    return 0;
}