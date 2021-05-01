#include <iostream>
using namespace std;
#include <stack>
//#define true 1
//#define false 0
//#define succeed 1
//#define failed 0
//#define Status int
//
//typedef int ElemType;
//
//typedef struct Node {
//	ElemType value;
//	struct Node* left, * right;
//}Node, * NodePtr;
//
//typedef struct BinarySortTree {
//	NodePtr root = 0;
//} BinarySortTree, * BinarySortTreePtr;
//
//Status BST_init(BinarySortTreePtr Tree, ElemType val)
//{
//	NodePtr NewNode = new Node;
//	NewNode->value = val;
//	NewNode->left = NULL;
//	NewNode->right = NULL;
//	if (Tree->root == NULL)
//	{
//		Tree->root = NewNode;
//	}
//	else
//	{
//		NodePtr t = Tree->root;
//		while (t != NULL)
//		{
//			if (val < t->value)
//			{
//				if (t->left == NULL)
//				{
//					t->left = NewNode;
//					return 1;
//				}
//
//				else t = t->left;
//			}
//			else {
//				if (t->left == NULL)
//				{
//					t->right = NewNode;
//					return 1;
//				}
//				else t = t->right;
//			}
//		}
//	}
//	return 1;
//}
////Status BST_insert(BinarySortTreePtr Tree, ElemType val)
////{
////
////}
//void Menu()
//{
//	cout << "二叉顺序树:" << endl;
//	cout << "1.插入数字" << endl;
//}
//int main()
//{
//	int a[6] = { 64,84,23,49,98,12 };
//	BinarySortTree Tree;
//	Tree.root = NULL;
//	int i=0;
//	int len = sizeof(a) / sizeof(int);
//	for (i = 0; i < len; i++)
//	{
//		BST_init(&Tree, a[i]);
//	}
//	
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
	struct tree* lchild, * rchild;
	int data;
}*BiTree, BiNode;

void Insert(BiTree bt, int data)
{
	BiTree p, s, parent=0;
	p = bt;
	while (p)
	{
		if (data < p->data)
		{
			parent = p;
			p = p->lchild;
		}

		else if (data > p->data)
		{
			parent = p;
			p = p->rchild;
		}
		else
			return;
	}

	s = (BiTree)malloc(sizeof(BiNode));
	s->data = data;
	s->lchild = s->rchild = NULL;
	if (s->data < parent->data)
		parent->lchild = s;
	else
		parent->rchild = s;
}

void InitTree(BiTree& bt, int n)
{ 
	int data, i;
	cin >> data;
	//scanf("%d", &data);
	bt = (BiTree)malloc(sizeof(BiNode));
	bt->data = data;
	bt->lchild = bt->rchild = NULL;
	for (i = 1; i < n; i++)
	{
		cin >> data;
		//scanf("%d", &data);
		Insert(bt, data);
	}
}
void preOrder(BiTree bt)
{
	if (!bt)
		return;
	preOrder(bt->lchild);
	printf("%d ", bt->data);
	preOrder(bt->rchild);
}

void InOrder(BiTree bt)
{ 
	if (!bt)
		return;

	InOrder(bt->lchild);
	printf("%d ", bt->data);
	InOrder(bt->rchild);
}
void postOrder(BiTree bt) 
{
	if (!bt)
		return;
	postOrder(bt->lchild);
    printf("%d ", bt->data);
	postOrder(bt->rchild);
	
}

int Search(BiTree bt, int key)
{
	BiTree p;
	p = bt;
	while (p)
	{
		if (key < p->data)
			p = p->lchild;
		else if (key > p->data)
			p = p->rchild;
		else
		{
			printf("数字%d查找成功。\n", key);
			return 1;
		}
	}
	printf("未找到数据%d。\n", key);
	return 0;
}

void Delete_BiTree(BiTree& bt, int key)
{
	BiTree p, cur, par=0;
	p = bt;
	while (p) {
		if (key == p->data)
			break;
		else if (key < p->data) {
			par = p;
			p = p->lchild;
		}
		else {
			par = p;
			p = p->rchild;
		}
	}

	if (!p) {
		printf("该数据不存在.\n");
		return;
	}

	if (!p->lchild)		
	{
		if (p == bt)
			bt = p->rchild;
		else if (par->lchild == p)
			par->lchild = p->rchild;
		else
			par->rchild = p->rchild;
		free(p);
	}


	else
	{
		cur = p->lchild;
		par = cur;
		while (cur->rchild)
		{
			par = cur;
			cur = cur->rchild;
		}

		if (par == p->lchild)			
		{
			p->data = par->data;
			p->lchild = par->lchild;
			free(par);
		}
		else						
		{
			while (par->lchild) {
				par = par->lchild;
			}
			p->data = par->data;
			free(par);
		}
	}
	printf("删除成功.\n");
}
void levelorder(BiTree bt)

{
	BiTree q[100];

	int front = 0, rear = 0;

	BiTree p;

	if (bt == NULL)

		return;

	q[rear] = bt;

	rear = (rear + 1) % 100;

	while (front != rear)

	{

		p = q[front];

		front = (front + 1) % 100;

		printf("%4d", p->data);

		if (p->lchild)

		{

			q[rear] = p->lchild;

			rear = (rear + 1) % 100;

		}

		if (p->rchild)

		{

			q[rear] = p->rchild;

			rear = (rear + 1) % 100;

		}

	}

}

int main()
{
	BiTree bt=0;
	int n=0, key=0, selet=0;
	while (1)
	{
		printf("------------------\n");
		printf("1、建立二叉排序树\n");
		printf("2、递归中序遍历结果\n");
		printf("3、搜索数据\n");
		printf("4、删除数据\n");
		printf("5、插入数据\n");
		printf("6、递归先序遍历结果\n");
		printf("7、递归后序遍历结果\n");
		printf("8、迭代先序遍历结果\n");
		printf("9、迭代中序遍历结果\n");
		printf("10、迭代后序遍历结果\n");
		printf("11、层序遍历结果\n");
		printf("12、退出\n");
		printf("------------------\n");
		cin >> selet;
		//scanf("%d", &selet);
		switch (selet)
		{
		case 1:
			printf("输入数字的个数:");
			cin >> n;
			//scanf("%d", &n);
			printf("请输入每个数字:");
			InitTree(bt, n);
			break;
		case 2:
			printf("递归中序遍历结果为：");
			InOrder(bt);
			putchar('\n');
			break;
		case 3:
			printf("请输入查找的关键字：");
			cin >> key;
			//scanf("%d", &key);
			Search(bt, key);
			break;
		case 4:
			printf("请输入删除的关键字：");
			cin >> key;
			//scanf("%d", &key);
			Delete_BiTree(bt, key);
			break;
		case 5:
			printf("请输入要插入的数据：");
			cin >> key;
			//scanf("%d", &key);
			Insert(bt, key);
			printf("插入成功.\n");
			break;
		case 6:
			printf("递归先序遍历结果为：");
			preOrder(bt);
			putchar('\n');
			break;
		case 7:
			printf("递归后序遍历结果为：");
			postOrder(bt);
			putchar('\n');
			break;
		case 8:
			printf("迭代先序遍历结果为：");
			preOrder(bt);
			putchar('\n');
			break;
		case 9:
			printf("迭代中序遍历结果为：");
			InOrder(bt);
			putchar('\n');
			break;
		case 10:
			printf("迭代后序遍历结果为：");
			postOrder(bt);
			putchar('\n');
			break;
		case 11:
			printf("按层次遍历二叉排序树结果为:\n");
			levelorder(bt);
			putchar('\n');
			break;
		default:
			return 0;
		}
	}
}
