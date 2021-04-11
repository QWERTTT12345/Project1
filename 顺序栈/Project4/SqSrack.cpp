#include<iostream>
using namespace std;
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
	ElemType elem[20];
	int top;
} SqStack;

void initStack(SqStack&s)//初始化栈
{
	s.top=0;
}
Status isEmptyStack(SqStack&s)//判断栈是否为空
{
	if (s.top == 0)
		return SUCCESS;
	else return ERROR;
}
Status getTopStack(SqStack&s, ElemType e) //得到栈顶元素
{
	if (isEmptyStack(s))
	{
		return ERROR;
	}
    else e=s.elem[s.top];
	return SUCCESS;
}
void clearStack(SqStack&s)//清空栈
{
	s.top=-1;
}
void destroyStack(SqStack*s)//销毁栈
{
	free(s);
}
int stackLength(SqStack&s)//检测栈长度
{
	return s.top;
}
Status pushStack(SqStack&s, ElemType data)//入栈
{
	s.top++;
	s.elem[s.top] = data;
	return SUCCESS;
}
Status popStack(SqStack&s, ElemType &data)//出栈
{
	data = s.elem[s.top];
	s.top--;
	return SUCCESS;
   
}
//Menu()
//{
//	cout << ******************************<< endl;
//	cout << **********1.得栈顶元素 ********<< endl;
//	cout << **********2.检测栈长度 ********<< endl;
//	cout << **********3.入栈 *************<< endl;
//	cout << **********4.出栈 *************<< endl;
//	cout << **********5.清空栈 ***********<< endl;
//	cout << **********6.销毁栈 ***********<< endl;
//
//}
void print(SqStack&s)
{
	cout << "栈里的数据为:";
	while (s.top != 0)
	{
		cout << s.elem[s.top]<<"  ";
		s.top--;
	}
}
int main()
{
	SqStack s;
	initStack(s);
	int e,x;
	cout << "请输入一个要入栈的数(0为结束)" << endl;
	cin >> e;
	while (e != 0)
	{
		pushStack(s, e);
		cout << "请输入一个要入栈的数(0为结束)" << endl;
		cin >> e;
	}
	int length=stackLength(s);
	cout << "此时栈长度为:" << length<< endl;
	print(s);
	cout << endl;
	s.top = length;
	cout << "请输入要出栈的数" << endl;
	cin >> x;
	popStack(s, x);
	print(s);
	cout << endl;
	cout << "清空栈选1" << endl;
	cout << "销毁栈选2" << endl;
	cout << "不做任何操作3" << endl;
	int order=0;
	switch (order)
	{
	case 1:clearStack(s); break;
	case 2:destroyStack(&s); break;
	case 3:break;
	}
	system("pause");
	return 0;
	


}
#endif