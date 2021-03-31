#include <iostream>
using namespace std;
//�����ṹ��
struct DoubleList
{
	DoubleList* front;
	int data;
	DoubleList* tail;
};
//����˫������
DoubleList* CreateList()
{
	DoubleList* headNode = new DoubleList;
	headNode->front = headNode->tail = headNode;
	return headNode;
}
//����˫�������½ڵ�
DoubleList* CreatNode(int data)
{
	DoubleList* newNode = new DoubleList;
	newNode->data = data;
	newNode->front = newNode->tail = NULL;
	return newNode;
}
//��β����
void Inser(DoubleList* headNode, int data)
{
	DoubleList* newNode = CreatNode(data);
	DoubleList* lastNode = headNode;
	while (lastNode->tail != headNode)
	{
		lastNode = lastNode->tail;
	}
	headNode->front = newNode;
	newNode->tail = headNode;
	lastNode->tail = newNode;
	newNode->front = lastNode;
}
//����ɾ��
void Delete(DoubleList* headNode, int posdata)
{
	DoubleList* posNode = headNode->tail;
	DoubleList* posNodeFront = headNode;
	while (posNode->data != posdata)
	{
		posNodeFront = posNode;
		posNode = posNodeFront->tail;
		if (posNode->tail == headNode)
		{
			cout << "�����ڸ�λ�ã�" << endl;
			system("pause");
			return;
		}
	}
	posNodeFront->tail = posNode->tail;
	posNode->tail->front = posNodeFront;
}
//�������
void print(DoubleList* headNode)
{
	DoubleList* p = headNode->tail;
	while (p->front != headNode->front)
	{
		cout << p->data<<"  ";
		p = p->tail;
	}
	cout<<endl;
}
int main()
{
	int a, b, c, d,t,w;
	DoubleList* list = CreateList();
	cout << "��������:" << endl;
	cin >> a;
	cout << "��������:" << endl;
	cin >> b;
	cout << "��������:" << endl;
	cin >> c;
	cout << "��������:" << endl;
	cin >> d;
	Inser(list, a);
	Inser(list, b);
	Inser(list, c);
	Inser(list, d);
	print(list);
	cout << "��ѡ��Ҫɾ��������λ��:";
	cin >> t;
	Delete(list, t);
	print(list);
	cout << "��ѡ����ĩβҪ���������:";
	cin >> w;
	Inser(list, w);
	print(list);
	system("pause");
	return 0;

}