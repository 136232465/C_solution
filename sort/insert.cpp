#include <stdio.h>
#include <iostream>
using namespace std;



void insertsort(int A[], int n)

{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		int get = A[i];
		while (j > 0&&get < A[j - 1])
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = get;
	}
}


int main()
{

	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
	int n = sizeof(A) / sizeof(int);
	insertsort(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}

	system("pause");
	return 0;

}