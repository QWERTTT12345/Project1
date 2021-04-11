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

void initStack(SqStack&s)//��ʼ��ջ
{
	s.top=0;
}
Status isEmptyStack(SqStack&s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s.top == 0)
		return SUCCESS;
	else return ERROR;
}
Status getTopStack(SqStack&s, ElemType e) //�õ�ջ��Ԫ��
{
	if (isEmptyStack(s))
	{
		return ERROR;
	}
    else e=s.elem[s.top];
	return SUCCESS;
}
void clearStack(SqStack&s)//���ջ
{
	s.top=-1;
}
void destroyStack(SqStack*s)//����ջ
{
	free(s);
}
int stackLength(SqStack&s)//���ջ����
{
	return s.top;
}
Status pushStack(SqStack&s, ElemType data)//��ջ
{
	s.top++;
	s.elem[s.top] = data;
	return SUCCESS;
}
Status popStack(SqStack&s, ElemType &data)//��ջ
{
	data = s.elem[s.top];
	s.top--;
	return SUCCESS;
   
}
//Menu()
//{
//	cout << ******************************<< endl;
//	cout << **********1.��ջ��Ԫ�� ********<< endl;
//	cout << **********2.���ջ���� ********<< endl;
//	cout << **********3.��ջ *************<< endl;
//	cout << **********4.��ջ *************<< endl;
//	cout << **********5.���ջ ***********<< endl;
//	cout << **********6.����ջ ***********<< endl;
//
//}
void print(SqStack&s)
{
	cout << "ջ�������Ϊ:";
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
	cout << "������һ��Ҫ��ջ����(0Ϊ����)" << endl;
	cin >> e;
	while (e != 0)
	{
		pushStack(s, e);
		cout << "������һ��Ҫ��ջ����(0Ϊ����)" << endl;
		cin >> e;
	}
	int length=stackLength(s);
	cout << "��ʱջ����Ϊ:" << length<< endl;
	print(s);
	cout << endl;
	s.top = length;
	cout << "������Ҫ��ջ����" << endl;
	cin >> x;
	popStack(s, x);
	print(s);
	cout << endl;
	cout << "���ջѡ1" << endl;
	cout << "����ջѡ2" << endl;
	cout << "�����κβ���3" << endl;
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