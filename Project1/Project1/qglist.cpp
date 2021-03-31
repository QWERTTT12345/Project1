#include <iostream>
using namespace std;

typedef int ElemType;
struct Node {
	ElemType data;
	struct Node* next;
};
//��������
void QGForwardList(Node* head)
{
	int data;
	Node* p = head;
	cout << "�������ݴ�������,��0������" << endl;
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
//�������
void print(Node* head)
{
	Node* p1 = head->next;
	cout << "�����е�����Ϊ:";
	cout << endl;
	while (p1)
	{
		cout << p1->data << "  ";
		p1 = p1->next;
	}
	cout << endl;

}
//ͳ�Ƹ���,�ó�λ��
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
//�������
void InsertList(Node* head)
{
	int w;
	cout << "������Ҫ�����λ��:";
	cin >> w;
	if (w <= 0 || w > count(head))
	{
		cout << "�����λ������!";
		return;
	}
	Node* p = head;
	for (int i = 0; i < w - 1; i++)
	{
		p = p->next;
	}
	Node* n = new Node;
	cout << "����Ҫ�����ֵ:";
	cin >> n->data;
	n->next = p->next;
	p->next = n;
	system("pause");
	system("cls");
}
//����ɾ��
void DeleteList(Node* head)
{
	int w;
	cout << "������Ҫɾ�����ݵ�λ��:";
	cin >> w;
	if (w <= 0 || w > count(head) - 1)
	{
		cout << "����λ������!";
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
//�������
void LookList(Node* head)
{
	int data;
	int i = 0;
	cout << "����Ҫ���ҵ�����:";
	cin >> data;
	Node* p = head;
	while (p)
	{
		if (p->data == data)
		{
			cout << "�������ڵ�" << i << "λ" << endl;
			system("pause");
			system("cls");
			return;
		}
		i++;
		p = p->next;
	}
	cout << "û�и�����!" << endl;
	system("pause");
	system("cls");
}
//����λ
void LocalList(Node* head)
{
	int w;
	cout << "������Ҫ��ȡ������λ��:";
	cin >> w;
	Node* p = head;
	for (int i = 0; i < w; i++)
		p = p->next;
	cout << "��ǰλ���ϵ�����Ϊ:" << p->data << endl;
	system("pause");
	system("cls");
}
void Menu()
{
	cout << "********** 0.�˳����� **********" << endl;
	cout << "********** 1.������� **********" << endl;
	cout << "********** 2.����ɾ�� **********" << endl;
	cout << "********** 3.������� **********" << endl;
	cout << "********** 4.����λ **********" << endl;
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
		cout << "������Ҫ���еĲ���:";
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
		defult:cout << "��������:" << endl; break;
		}
	}
	system("pause");
	return 0;
}