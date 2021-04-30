#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

typedef int DataType;
typedef struct Node
{
    DataType _data;
    struct Node* _next;
}LinkQueueNode;

typedef struct
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
}LinkQueue;

//初始化队列
void InitLinkQueue(LinkQueue* LQ)
{
    //创建一个头结点
    LinkQueueNode* pHead = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pHead);
    LQ->front = LQ->rear = pHead; //队头和队尾指向头结点
    LQ->front->_next = NULL;
}

//判断队列是否为空

int IsEmpty(LinkQueue* LQ)
{
    if (LQ->front->_next == NULL)
    {
        return 1;
    }
    return 0;
}

//入队操作

void EnterLinkQueue(LinkQueue* LQ, DataType data)
{
    //创建一个新结点
    LinkQueueNode* pNewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pNewNode);
    pNewNode->_data = data;  //将数据元素赋值给结点的数据域
    pNewNode->_next = NULL;  //将结点的指针域置空
    LQ->rear->_next = pNewNode;   //将原来队列的队尾指针指向新结点
    LQ->rear = pNewNode;      //将队尾指针指向新结点
}

//出队操作

void DeleteLinkQueue(LinkQueue* LQ, DataType* data)
{
    if (IsEmpty(LQ))
    {
        printf("队列为空！\n");
        return;
    }
    //pDel指向队头元素，由于队头指针front指向头结点，所以pDel指向头结点的下一个结点
    LinkQueueNode* pDel = LQ->front->_next;
    *data = pDel->_data;   //将要出队的元素赋给data
    LQ->front->_next = pDel->_next;  //使指向头结点的指针指向pDel的下一个结点
    //如果队列中只有一个元素,将队列置空
    if (LQ->rear = pDel)
    {
        LQ->rear = LQ->front;
    }
    free(pDel);   //释放pDel指向的空间
}

//取队头元素

int GetHead(LinkQueue* LQ, DataType* data)
{
    if (IsEmpty(LQ))
    {
        printf("队列为空!\n");
        return 0;
    }
    LinkQueueNode* pCur;
    pCur = LQ->front->_next;  //pCur指向队列的第一个元素，即头结点的下一个结点
    *data = pCur->_data;      //将队头元素值赋给data
    return *data;             //返回队头元素值
}

//清空队列

void ClearQueue(LinkQueue* LQ)
{
    while (LQ->front != NULL)
    {
        LQ->rear = LQ->front->_next;  //队尾指针指向队头指针的下一个结点
        free(LQ->front);              //释放队头指针指向的结点
        LQ->front = LQ->rear;         //队头指针指向队尾指针
    }
}

//打印队列中的元素

void PrintLinkQueue(LinkQueue* LQ)
{
    assert(LQ);
    LinkQueueNode* pCur;
    pCur = LQ->front->_next;
    while (pCur)
    {
        printf("%-3d", pCur->_data);
        pCur = pCur->_next;
    }
    printf("\n");
}
int main()
{
    LinkQueue LQ;
    DataType data,a;
    //初始化队列
    InitLinkQueue(&LQ);
    //入队
    cout << "输入入队的元素(以-1结束):" << endl;
    cin >> a;
    while (a != -1)
    {
        cout << "输入入队的元素(以-1结束):" << endl;
        cin >> a;
        EnterLinkQueue(&LQ, a);
    }
    printf("队列中的元素为：");
    //打印队列中元素
    PrintLinkQueue(&LQ);
    printf("\n");
    //取队头元素
    data = GetHead(&LQ, &data);
    printf("队头元素为：%d\n", data);
    printf("\n");
    //出队
    DeleteLinkQueue(&LQ, &data);
    printf("出队的元素为：%d\n", data);
    printf("\n");
    printf("队列中的元素为：");
    PrintLinkQueue(&LQ);
    printf("\n");
    data = GetHead(&LQ, &data);
    printf("队头元素为：%d\n", data);
    printf("\n");
    ClearQueue(&LQ);
    system("pause");
    return 0;
}