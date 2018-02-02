#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//深度优先遍历（递归）
void DFS(int map[5][5], int m)
{
	cout << m << endl;
	for (int i = 0; i < 5; i++){
		map[i][m] = -1;
	}
	for (int i = 0; i < 5; i++){
		if (map[m][i] == 1){
			DFS(map, i);
		}
	}

}

//深度优先遍历（非递归，用栈）

void DFSstack(int map[5][5], int m)
{
	int visit[5] = { 0 };
	int i = 0;
	stack<int>s;
	s.push(m);
	while (!s.empty()){
		int k = s.top();
		if (visit[k] == 0){
			cout << k << endl;
			visit[k] = 1;
		}

		for (i = 0; i < 5; i++){
			if (map[k][i] == 1 && visit[i] == 0){
				s.push(i);
				break;
			}
		}
		if (i == 5){
			s.pop();
		}

	}


}


//广度优先遍历(用队列)

void BFS(int map[5][5], int m)
{
	queue<int>a;
	a.push(m);
	while (!a.empty()){
		int k = a.front();
		a.pop();
		for (int i = 0; i < 5; i++){
			if (map[k][i] == 1){
				a.push(i);
				map[i][k] = -1;
			}
		}
		cout << k << endl;
	}
}





int main()
{
	char MapNode[5] = { 'A', 'B', 'C', 'D', 'E'};
	int map[5][5] = { 0 };
	map[0][1] = 1;
	map[0][2] = 1;
	map[1][0] = 1;
	map[2][0] = 1;
	map[3][4] = 1;
	map[4][3] = 1;
	map[1][4] = 1;
	map[4][1] = 1;
	DFSstack(map, 0);
	system("pause");
	return 0;
}


