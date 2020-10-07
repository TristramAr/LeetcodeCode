#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class CStudent
{
private:
    string name;
    string id;   //学号
    char gender; //性别
    int age;

public:
    void PrintInfo();
    void SetInfo(const string &name_, const string &id_, int age_, char gender_);
    string GetName() { return name; }
};

void CStudent::PrintInfo()
{
    cout<<"name:"<<name<<endl;
    cout<<"id:"<<id<<endl;
    cout<<"gender:"<<gender<<endl;
    cout<<"age:"<<age<<endl;
}

void CStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_)
{
    name=name_;
    id = id_;
    age = age_;
    gender = gender_;

}


class CUndergraduateStudent : public CStudent
{
private:
    string department;             //学生所属系
public:
    void QualifiedForBaoyan()      //给与保研资格
    {
        cout << "qualified for baoyan" << endl;
    }
    void PrintInfo()
    {
        CStudent::PrintInfo();     //调用基类的PrintInfo
        cout << "Department；" << department << endl;
    }
    void SetInfo(const string &name_, const string &id_,
                 int age_, char gender_, const string &department_)
    {
        CStudent::SetInfo(name_, id_, age_, gender_);  // 调用基类的SetInfo 
        department = department_;   
    }
};


int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("feng","123456",18,'M',"computer science");
    cout<<s2.GetName()<<endl;
    s2.QualifiedForBaoyan();
    s2.PrintInfo();
    return 0;
}