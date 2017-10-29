#include <stdio.h>
#include <iostream>
using namespace  std;


void swap(int a[], int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}







void bubblesort(int p[],int n)
{
	for (int height = n; height > 0; height--)
	{
		for (int i = 0; i < height-1; i++)
		{
			if (p[i]>p[i + 1])
			{
				swap(p, i,i+1);
			}
		}
	}

}


int main()
{
	int num[10] = {1,20,5,6,40,2,5,42,9,10};

	bubblesort(num, 10);
	for (int i = 0; i < 10;i++)
	{
		cout << num[i] << endl;
	}

	system("pause");


}