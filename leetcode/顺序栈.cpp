/*
    Project: sequence_stack (数据结构-顺序栈)
    Date:    2018/09/14
    Author:  Frank Yu
	InitStack(SqStack &s) 参数：顺序栈s 功能：初始化  时间复杂度O(1)
	Push(SqStack &s,SElemType e) 参数：顺序栈s,元素e 功能：将e入栈 时间复杂度:O(1)
	Pop(SqStack &s,SElemType &e) 参数：顺序栈s,元素e 功能：出栈,e接收出栈元素值 时间复杂度O(1)
	GetTop(SqStack s,SElemType &e) 参数：顺序栈s,元素e 功能：得到栈顶元素 时间复杂度O(1)
	注意：严蔚敏版没有判断栈空函数，在入栈、出栈函数里面判断栈是否空，与王道的不同 尤其是top指针在base之上(有元素时)
	      另外，严蔚敏版 59页取栈顶有误
	
*/
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int
#define MaxSize 100
//栈数据结构
typedef struct Stack
{
	SElemType *base;//栈底指针 不变
	SElemType *top;//栈顶指针 一直在栈顶元素上一个位置
	int stacksize;//栈可用的最大容量
}SqStack;
//**************************************基本操作函数************************************//
//初始化函数
Status InitStack(SqStack &s)
{
	s.base=new SElemType[MaxSize];//申请一个数组长度为MaxSize的动态数组
	if(!s.base)
	{
		cout<<"分配失败\n"<< endl;
		return 0;
	}
	s.top=s.base;//栈顶指针与栈底相同 王道上top起初在base下面，感觉很别扭，top应该高于或等于base
	s.stacksize=MaxSize;
	return 1;
}
//入栈
Status Push(SqStack &s,SElemType e)
{
	if(s.top-s.base==s.stacksize) return 0;//栈满
	*(s.top++)=e;//先入栈，栈顶指针再上移 注意与王道上的不同，具体问题具体分析
	return 1;	
}
//出栈 用e返回值
Status Pop(SqStack &s,SElemType &e)
{
	if(s.top==s.base) return 0;//栈空
	e=*--s.top;//先减减 指向栈顶元素，再给e
	return 1;	
}
//得到栈顶元素，不修改指针
bool GetTop(SqStack s,SElemType &e) //严蔚敏版59页有问题，应该用e去获得，函数返回bool类型去判断
{
	if(s.top==s.base) return false;//栈空			
	else e=*--s.top;
	return true;
		
}
