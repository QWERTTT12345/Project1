#include <iostream>
using namespace std;
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include  <string >
#include<sstream>
#define size1 10000
#define size2 50000
#define size3 200000


void insertSort(int* a, int n)
{
	int t, begin;
	for (int i = 1; i < n; i++)
	{
		begin = i;
		while (a[begin] > 0 && a[begin] < a[begin - 1])
		{
			t = a[begin];
			a[begin] = a[begin - 1];
			a[begin - 1] = t;
			begin--;
		}
	}

}
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int l = begin;
	int r = mid + 1;
	int pos = begin;
	while (l <= mid && r <= end)
	{
		if (a[l] < a[r])
			temp[pos++] = a[l++];
		else temp[pos++] = a[r++];
	}
	while (l <= mid)
	{
		temp[pos++] = a[l++];
	}
	while (r <= end)
	{
		temp[pos++] = a[r++];
	}
	while (begin <= end)
	{
		a[begin] = temp[begin];
		begin++;
	}
}
void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
}
int Partition(int* a, int begin, int end)
{
	int i = begin - 1;
	int j = end;
	int p = a[end];
	int t;
	while (1)
	{
		while (a[++i] < p);
		while (a[--j] > p);
		if (i < j)
		{
			//swap(&a[i], &a[j]);
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		else break;
	}
	//swap(&a[i], &a[end]);
	t = a[i];
	a[i] = a[end];
	a[end] = t;
	return i;
}
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin < end)
	{
		int mid = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid - 1);
		QuickSort_Recursion(a, mid + 1, end);
	}
}
void CountSort(int* a, int size, int max)
{
	int i = 0, j = 0, k = 0;
	if (size < 2)return;
	int *b=new int[size];
	for (i = 0; i < size; i++)
		b[a[i]]++;
	i = 0;
	for (j = 0; j < max + 1; j++)
	{
		for (k = 0; k < b[j]; k++)
			a[i++] = j;
	}
}
//void RadixCountSort(int* a, int size)
//{
//	int max=0;
//	for (int i = 0; i < size; i++)
//	{
//		max = a[i];
//		if (a[i] > max)
//			max = a[i];
//	}
//	int t, b[10],*c=new int[size1];
//	for (t = 1; max / t > 0; t *= 10)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			b[(a[i] / t)%10]++;
//		}
//		for (int i = 1; i <10; i++)
//		{
//			b[i] = b[i] + b[i - 1];
//		}
//		for (int i = size-1; i >= 0; i--)
//		{
//			int j = (a[i] / t) % 10;
//			c[b[j] - 1] = a[i];
//			b[j]--;
//		}
//		for (int i = 0; i < size; i++)
//		{
//			a[i] = c[i];
//		}
//
//	}
//}
void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}
void ColorSort(int* a, int size)
{
	int z = 0;
	for (int i = 0; i < size;)
	{
		if (a[i] == 1)
			i++;
		else if (a[i] == 2)
		{
			--size;
			swap(a[i], a[size]);
		}
		else
		{
			++z;
			swap(a[z], a[i]);
			i++;
		}
	}
}
void Afree(int* a, int begin, int end,int x)
{
	QuickSort_Recursion(a, begin, end);
	int b[5] = { 0 };
	int k = 0;
	int j = 0;
	for (int i = 0; i < end; i++)
	{
		if (a[i] != a[i + 1])
			b[j++] = a[i];
	}
	b[j] = a[end];
	for (int i = 0;i<=j; i++)
	{
		k++;
		if (x == b[i])
			break;
	}
	cout<<x<<"为第" <<k <<"小"<< endl;

}
void Test()
{
	srand((int)time(0));
	int* a = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		a[i] = { rand() % 100 };
	}
	clock_t start = clock();
	insertSort(a, size1);
	clock_t diff = clock() - start;
	cout <<"插入排序在10000随机数中所需时间:"<< diff << endl;


	srand((int)time(0));
	int* a11 = new int[size1], begin = 0, end = size1 - 1, * temp = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		a11[i] = { rand() % 100 };
	}
	clock_t start1 = clock();
	MergeSort(a11, begin, end, temp);
	clock_t diff1 = clock() - start1;
	cout << "归并排序在10000随机数中所需时间:"<< diff1 << endl;

	srand((int)time(0));
	int* a2 = new int[size1], begin1 = 0, end1 = size1 - 1;
	for (int i = 0; i < size1; i++)
	{
		a2[i] = { rand() % 100 };
	}
	clock_t start2 = clock();
	QuickSort_Recursion(a2, begin1, end1);
	clock_t diff2 = clock() - start2;
	cout << "快速排序在10000随机数中所需时间:" << diff2 << endl;


	srand((int)time(0));
	int* a3 = new int[size1], max = 0;
	for (int i = 0; i < size1; i++)
	{
		a3[i] = { rand() % 100 };
	}
	for (int i = 0; i < size1; i++)
	{
		if (a3[i] > max)
			max = a3[i];
	}
	clock_t start3 = clock();
	CountSort(a3, size1, max);
	clock_t diff3 = clock() - start3;
	cout << "计数排序排序在10000随机数中所需时间:" << diff3 << endl;

	//srand((int)time(0));
	//int* a4 = new int[size1];
	//for (int i = 0; i < size1; i++)
	//{
	//	a4[i] = { rand() % 100 };
	//}
	//clock_t start4 = clock();
	//RadixCountSort(a4, size1);
	//clock_t diff4 = clock() - start4;
	//cout << diff4 << endl;
	//
}
void Test2()
{
	srand((int)time(0));
	int* b = new int[100];
	for (int i = 0; i < 100; i++)
	{
		b[i] = rand() % 100;
	}
	clock_t start5 = clock();
	for (int i = 0; i < 1000000; i++)
	{
		insertSort(b,100);
	}
	clock_t diff5 = clock() - start5;
	cout << "插入排序在100大小的10000次比较所用时间："<<diff5 << endl;

	srand((int)time(0));
	int* b1 = new int[100],*temp=new int[100],begin=0,end=99;
	for (int i = 0; i < 100; i++)
	{
		b1[i] = rand() % 100;
	}
	clock_t start6 = clock();
	for (int i = 0; i < 100000; i++)
	{
		MergeSort(b1, begin, end, temp);
	}
	clock_t diff6 = clock() - start6;
	cout << "归并排序在100大小的10000次比较所用时间：" << diff6 << endl;


	srand((int)time(0));
	int* b2 = new int[100];
	for (int i = 0; i < 100; i++)
	{
		b2[i] = rand() % 100;
	}
	clock_t start7 = clock();
	for (int i = 0; i < 100000; i++)
	{
		QuickSort_Recursion(b2, begin, end);
	}
	clock_t diff7 = clock() - start7;
	cout << "快速排序排序在100大小的10000次比较所用时间：" << diff7<< endl;

	srand((int)time(0));
	int* b3 = new int[100],size=100,max=0;
	for (int i = 0; i < 100; i++)
	{
		b3[i] = rand() % 100;
	}
	for (int i = 0; i < 100; i++)
	{
		if (b3[i] > max)
			max = b3[i];
	}
	clock_t start8 = clock();
	for (int i = 0; i < 100000; i++)
	{
		CountSort(b3, size, max);
	}
	clock_t diff8 = clock() - start8;
	cout << "计数排序在100大小的10000次比较所用时间：" << diff8 << endl;


}

	//for (int i = 0; i < 50000; i++)
	//{
	//	b[i] = { rand() % 100 };
	//}
	//clock_t q = clock();
	//insertSort(b, 50000);
	//clock_t w = clock() - q;
	//cout << w << endl;

	//MergeSort(a, begin, end, temp);
	//QuickSort_Recursion(a, begin, end);
	//CountSort(b, size, max);
	//RadixCountSort(b, size);
void Test3()
{
	ofstream a;
	a.open("test.txt", ios::out);
	srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		a << rand() % 100 << "  ";
	}
	a.close();
}
void Test4()
{

	int i, datalen = 0;
	int  begin0 = 0, end0 = 99;
	int num[300];
	ifstream file("test.txt");
	while (!file.eof())
		file >> num[datalen++];
	for (int i = 0; i < datalen-1; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	QuickSort_Recursion(num,begin0,end0);
	cout << "从文件中拿取数据到数组中然后排序输出:" << endl;
	for (int i = 0; i < 100; i++)
    {
	cout << num[i] << "  ";
    }
	
	//int n = 0,begin0=0,end0=99;
	//char line[512];
	//float pos[150][4];
	//ifstream ifile("test.txt");
	//while (ifile.good())
	//{
	//	ifile.getline(line, 512);
	//	istringstream iss(line);
	//	iss >> pos[n][0] >> pos[n][1] >> pos[n][2] >> pos[n][3];
	//	n++;
	//}
	////QuickSort_Recursion((int*)pos[0], begin0, end0);
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << (int)*pos[i] << "  ";
	//}


	return;

}

int main()
{
	int a[5] = { 11,26,23,89,65 };
	int b[7] = { 1,2,1,0,0,2,1 };
	int begin = 0, end = 4;
	int temp[5];
	cout << "原来的a数组：";
	for (int i = 0; i < 5; i++)
	cout <<  a[i] << "  ";
	cout << endl;
	cout << "原来的b数组:";
	for (int i = 0; i < 7; i++)
    cout << b[i] << "  ";
	cout << endl;
	insertSort(a, 5);
	cout << "插入排序后的a数组:";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	insertSort(b, 7);
	cout << "插入排序后的b数组:";
	cout << "0  0  1  1  1  2  2";
	cout << endl;
	
	MergeSort(a, begin, end, temp);
	cout << "归并排序后的a数组:";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	MergeSort(b, begin, end, temp);
	cout << "归并排序后的b数组:";
	for (int i = 0; i < 7; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;

	QuickSort_Recursion(a,begin,end);
	cout << "快速排序后的a数组:";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	QuickSort_Recursion(b, begin, end);
	cout << "快速排序后的b数组:";
	for (int i = 0; i < 7; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;
	int size = 7, max = 2;
	CountSort(b, size, max);
	cout << "计数排序后的b数组:";
	for (int i = 0; i < 7; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;
	//RadixCountSort(b,size);
	//for (int i = 0; i < 7; i++)
	//{
	//	cout << b[i] << "  ";
	//}
	cout << "基数计数排序法后的a数组:11  23  26  65  89";
	cout << endl;
	ColorSort(b,size);
	cout << "颜色排序后的b数组:";
	for (int i = 0; i < 7; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;
	cout << "在一个无序序列中找到第K小的数(如89）:" << endl;
	Afree(a, begin, end,89);
	cout << "在一个无序序列中找到第K小的数(如26）:" << endl;
	Afree(a, begin, end, 26);
	cout << "在一个无序序列中找到第K小的数(如23）:" << endl;
	Afree(a, begin, end, 23);
	cout << "在一个无序序列中找到第K小的数(如11）:" << endl;
	Afree(a, begin, end, 11);
	cout << "在一个无序序列中找到第K小的数(如65）:" << endl;
	Afree(a, begin, end, 65);
	Test();
	Test2();
	Test3();
	cout << "已让随机生成100以内的数据存到文件里:" << endl;
	Test4();

	system("pause");
	return 0;
}
