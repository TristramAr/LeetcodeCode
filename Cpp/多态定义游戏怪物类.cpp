#include<iostream>

# define power 100
class CCreature
{
private:
    /* data */
public:
    virtual void Attack(CCreature*pCreature){}       //虚函数
    virtual void Hurted(int nPower){}
    virtual void FightBack(CCreature*pCreature){}
};

//派生类
class CDragon:public CCreature{
    public:
    virtual void Attack(CCreature*pCreature){}
    virtual void Hurted(int nPower){}
    virtual void FightBack(CCreature*pCreature){}
}; 

void  CDragon::Attack(CCreature*p)
{
    // ...表现攻击动作的代码
    p->Hurted(power);
    p->FightBack(this);
}
