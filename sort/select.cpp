#include <stdio.h>
#include<iostream>
using namespace std;
time O（n²）


void swap(int p[],int i,int j)
{
	int temp= p[i];
	p[i] = p[j];
	p[j] = temp;

}



void select(int p[],int n)
{
	for (int i = 0; i < n;i++)
	{
		int min=i;
		for (int j = i; j < n;j++)
		{
			if (p[min]>p[j])
			{
				//swap(p, min, j);
				min = j;
			}
		}
		swap(p, min, i);
	}
}



int main()
{
	int p[5] = { 1, 5, 8, 4, 2 };
	select(p,5);
	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}
	system("pause");

}
