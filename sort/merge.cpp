#include<stdio.h>
#include <iostream>
using namespace std;
//time O（nlogn）
//space O（n）

void merge(int A[], int left, int mid, int right)
{
	int len = right - left + 1;
	int *temp = new int[len];
	int i = left;
	int j = mid + 1;
	int index = 0;
	while (i <= mid&&j <= right){
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
	}
	while (i <= mid){
		temp[index++] = A[i++];
	}
	while (j <= right){
		temp[index++] = A[j++];
	}
	for (int k = 0; k < len; k++){
		A[left++] = temp[k];
	}
}
void mergesort(int A[], int left, int right)
{
	if (left == right){
		return;
	}
	int mid = (right + left) / 2;
	mergesort(A, left, mid);
	mergesort(A, mid + 1, right);
	merge(A, left, mid, right);

}
int main()
{
	int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	mergesort(A1, 0, 7);
	for (int i = 0; i < 8; i++){
		cout << A1[i] << endl;;
	}
	system("pause");
}