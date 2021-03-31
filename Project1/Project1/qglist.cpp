#include <iostream>
using namespace std;

typedef int ElemType;
struct Node {
	ElemType data;
	struct Node* next;
};
//创建链表
void QGForwardList(Node* head)
{
	int data;
	Node* p = head;
	cout << "输入数据创建链表,以0结束：" << endl;
	while (1)
	{
		cin >> data;
		if (data == 0)break;
		Node* q = new Node;
		q->next = NULL;
		q->data = data;
		p->next = q;
		p = q;
	}
}
//输出链表
void print(Node* head)
{
	Node* p1 = head->next;
	cout << "链表中的数据为:";
	cout << endl;
	while (p1)
	{
		cout << p1->data << "  ";
		p1 = p1->next;
	}
	cout << endl;

}
//统计个数,得出位置
int count(Node* head)
{
	int i = 1;
	Node* p = head->next;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}
//链表插入
void InsertList(Node* head)
{
	int w;
	cout << "请输入要插入的位置:";
	cin >> w;
	if (w <= 0 || w > count(head))
	{
		cout << "输入的位置有误!";
		return;
	}
	Node* p = head;
	for (int i = 0; i < w - 1; i++)
	{
		p = p->next;
	}
	Node* n = new Node;
	cout << "输入要插入的值:";
	cin >> n->data;
	n->next = p->next;
	p->next = n;
	system("pause");
	system("cls");
}
//链表删除
void DeleteList(Node* head)
{
	int w;
	cout << "请输入要删除数据的位置:";
	cin >> w;
	if (w <= 0 || w > count(head) - 1)
	{
		cout << "输入位置有误!";
		return;
	}
	Node* p = head;
	for (int i = 0; i < w - 1; i++)
	{
		p = p->next;
	}
	Node* d = p->next;
	p->next = d->next;
	system("pause");
	system("cls");
}
//链表查找
void LookList(Node* head)
{
	int data;
	int i = 0;
	cout << "输入要查找的数据:";
	cin >> data;
	Node* p = head;
	while (p)
	{
		if (p->data == data)
		{
			cout << "该数据在第" << i << "位" << endl;
			system("pause");
			system("cls");
			return;
		}
		i++;
		p = p->next;
	}
	cout << "没有该数据!" << endl;
	system("pause");
	system("cls");
}
//链表定位
void LocalList(Node* head)
{
	int w;
	cout << "输入想要获取的数据位置:";
	cin >> w;
	Node* p = head;
	for (int i = 0; i < w; i++)
		p = p->next;
	cout << "当前位置上的数据为:" << p->data << endl;
	system("pause");
	system("cls");
}
void Menu()
{
	cout << "********** 0.退出链表 **********" << endl;
	cout << "********** 1.链表插入 **********" << endl;
	cout << "********** 2.链表删除 **********" << endl;
	cout << "********** 3.链表查找 **********" << endl;
	cout << "********** 4.链表定位 **********" << endl;
}
int main()
{
	Node* head = new Node;
	QGForwardList(head);
	system("cls");
	print(head);
	int x;
	while (1)
	{
		Menu();
		cout << "输入想要进行的操作:";
		cin >> x;
		switch (x)
		{
		case 1:InsertList(head); print(head);
			break;
		case 2:DeleteList(head); print(head);
			break;
		case 3:LookList(head); print(head);
			break;
		case 4:LocalList(head); print(head);
			break;
		case 0:return 0; break;
		defult:cout << "操作错误:" << endl; break;
		}
	}
	system("pause");
	return 0;
}