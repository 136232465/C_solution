#include <stdio.h>
#include <iostream>
using namespace std;
//O（nlogn）~O（n²）
void shellsort(int p[], int n)
{
	int step = n / 2;
	while (step > 0){
		for (int i = step; i < n; i++){
			int m = i - step;
			int temp = p[i];
			while (m >= 0 && p[m] > temp){
				p[m + step] = p[m];
				m = m - step;
			}
			p[m + step] = temp;
		}
		step = step / 2;
	}
}
int main()
{
	int p[5] = { 1, 5, 8, 4, 2 };
	shellsort(p, 5);
	for (int i = 0; i < 5; i++){
		cout << p[i] << endl;
	}
	system("pause");
}

