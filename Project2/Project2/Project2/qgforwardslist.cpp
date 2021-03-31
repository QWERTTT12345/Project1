#include <iostream>
using namespace std;
//创建结构体
struct DoubleList
{
	DoubleList* front;
	int data;
	DoubleList* tail;
};
//创建双向链表
DoubleList* CreateList()
{
	DoubleList* headNode = new DoubleList;
	headNode->front = headNode->tail = headNode;
	return headNode;
}
//创建双向链表新节点
DoubleList* CreatNode(int data)
{
	DoubleList* newNode = new DoubleList;
	newNode->data = data;
	newNode->front = newNode->tail = NULL;
	return newNode;
}
//表尾插入
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
//链表删除
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
			cout << "不存在该位置！" << endl;
			system("pause");
			return;
		}
	}
	posNodeFront->tail = posNode->tail;
	posNode->tail->front = posNodeFront;
}
//输出链表
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
	cout << "输入数据:" << endl;
	cin >> a;
	cout << "输入数据:" << endl;
	cin >> b;
	cout << "输入数据:" << endl;
	cin >> c;
	cout << "输入数据:" << endl;
	cin >> d;
	Inser(list, a);
	Inser(list, b);
	Inser(list, c);
	Inser(list, d);
	print(list);
	cout << "请选择要删除的数据位置:";
	cin >> t;
	Delete(list, t);
	print(list);
	cout << "请选择在末尾要插入的数据:";
	cin >> w;
	Inser(list, w);
	print(list);
	system("pause");
	return 0;

}