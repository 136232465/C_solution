#include <stdio.h>
#include <iostream>
using namespace std;


void inset(int p[],int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		int temp = p[i];
		while (j>=0&&temp<p[j])
		{
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = temp;
	}
}


int main()
{
	int p[5] = { 1, 5, 8, 4, 2 };
	inset(p, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}
	system("pause");

}
