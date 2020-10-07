#include<iostream>
#include<string>
using namespace std;
class CPU{
public:
    CPU(int sta,string tp);
    CPU(const CPU &ad);
    ~CPU();
    void details();
private:
    int standard;
    string brand;
};
CPU::CPU(int sta,string tp){
    this->standard = sta;
    this->brand = tp;
}
CPU::CPU(const CPU &ad) {
    cout << endl << "Warnning:This Copy constructors.!!!" << endl;
    this->brand = ad.brand;
    this->standard = ad.standard;
}
CPU::~CPU(){
 
};
void CPU::details(){
    cout << "The details of CPU:" << endl;
    cout << "The brand is " << brand << endl;
    cout << "The standard is " << standard << endl << endl;
}
class RAM{
public:
    RAM(int mem,int bit, string tp);
    RAM(RAM &ad);
    ~RAM();
    void details();
private:
    int memory;
    int bits;
    string brand;
};
RAM::RAM(int mem, int bit, string tp){
    this->memory = mem;
    this->bits = bit;
    this->brand = tp;
}
RAM::RAM(RAM &ad){
    cout << endl << "Warnning:This Copy constructors.!!!" << endl;
    this->memory = ad.memory;
    this->bits =ad.bits;
    this->brand =ad.brand;
}
RAM::~RAM(){
 
}
void RAM::details(){
    cout << "The details of RAM:" << endl;
    cout << "The brand is " << brand << endl;
    cout << "The memory is " << memory<< endl;
    cout << "The bits are " << bits << endl << endl;
}
class CDROM
{
public:
    CDROM(int st, string bra);
    CDROM(CDROM &ad);
    ~CDROM();
    void details();
private:
    int standard;
    string brand;
};
CDROM::CDROM(int st, string bra){
    this->brand = bra;
    this->standard = st;
}
CDROM::CDROM(CDROM &ad) {
    cout << endl << "Warnning:This Copy constructors.!!!" << endl;
    this->brand = ad.brand;
    this->standard = ad.standard;
}
CDROM::~CDROM(){
 
}
void CDROM::details(){
    cout << "The details of CDROM:" << endl;
    cout << "The brand is " << brand << endl;
    cout << "The standard is " << standard << endl << endl;
}
class Computer {
public:
    Computer(CPU cp,RAM ra,CDROM cdro);
    Computer(Computer &ad);
    ~Computer();
    void stop();
    void run();
    void details();
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};
Computer::Computer(CPU cp, RAM ra, CDROM cdro):cpu(cp),ram(ra),cdrom(cdro){
    cout << "Computer is OK!" << endl;
}
Computer::Computer(Computer &ad): cpu(ad.cpu), ram(ad.ram), cdrom(ad.cdrom) {
    cout << endl << "Warnning:This Copy constructors.!!!" << endl;
    cout << "Computer is OK!" << endl;
}
Computer::~Computer() {
 
}
void Computer::run(){
    cout << "Computer is running!" << endl;
}
void Computer::stop(){
    cout << "Computer stoped!" << endl;
}
void Computer::details(){
    cpu.details();
    ram.details();
    cdrom.details();
}
int main(void){
    CPU cp(1,"!@!");
    RAM ra(1024,10,"!#@!$");
    CDROM cd(2561,"$#%$#^");
    Computer cs(cp, ra, cd);
    cs.run();
    cs.details();
    cs.stop();
    return 0;
}
