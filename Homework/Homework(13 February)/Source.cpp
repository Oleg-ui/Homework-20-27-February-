#include <iostream>
#include <vector>
#include <stack>
#include <queue> 
using namespace std;

void show(vector<vector<int>> listG) //¬ыводит на консоль список смежности
{
	cout << "Cписок смежности:" << endl;
	for (int i = 0; i < listG.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < listG[i].size(); j++)
		{
			cout << listG[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<bool>> f(vector<vector<int>> listG) //преобразует список смежности в матрицу смежности
{
	
	vector<vector<bool>> tmp = vector<vector<bool>>(listG.size(), vector<bool>(listG.size()));

	for (int i = 0; i < listG.size(); i++)
	{
		for (int j = 0; j < listG[i].size(); j++)
		{
			tmp[i][j] = false;
		}
	}
	
	for (int i = 0; i < listG.size(); i++)
	{
		for (int j = 0; j < listG[i].size(); j++)
		{
			
			for (int k = 0; k < listG.size(); k++)
			{
				if (listG[i][j] == k)
				{
					tmp[i][k] = true;
				}
			}
		}
	}
	
	return tmp;
}

void show(vector<vector<bool>> matrixG) //выводит на консоль матрицу смежности
{
	cout << "ћатрица смежности:" << endl;
	for (int i = 0; i < matrixG.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < matrixG.size(); j++)
		{
			cout << matrixG[i][j] << " ";
		}
		cout << endl;
	}
	cout<<endl;
}

vector<vector<int>> f(vector<vector<bool>> matrixG) //преобразует матрицу смежности в список смежности
{
	
	vector<vector<int>> tmp = vector<vector<int>>(matrixG.size());
	
	for (int i = 0; i < matrixG.size(); i++)
	{
		for (int j = 0; j < matrixG.size(); j++)
		{
			if (matrixG[i][j] == true)
			{
				tmp[i].push_back(j);
			}
		}
	}
	return tmp;
}

void dfs(vector<vector<int>> listG, int start)         //ѕоиск в глубину. ѕроходит через каждую вершину
{
	cout << "ѕоиск в глубину: ";
	stack<int> Stack;
	vector<bool> used = vector<bool>(listG.size());

	Stack.push(start);

	while (!Stack.empty())
	{
		int v = Stack.top();

		if (used[v] == false)
		{
			used[v] = true;
			cout << v << " ";
		}

		Stack.pop();

		for (int i = 0; i < listG[v].size(); i++)
		{
			if (used[listG[v][i]]==false)
			{
				Stack.push(listG[v][i]);
			}
		}
	}
	cout << endl;
		
}

void bfs(vector<vector<int>> listG, int start)      //ѕоиск в ширину. ѕроходит по вершинам, но рассматривает именно каждый подуровень графа
{
	cout << "ѕоиск в ширину: ";
	vector<bool> used = vector<bool>(listG.size());
	int* dist = new int[listG.size()];
	int* p = new int[listG.size()];

	p[start] = start;
	dist[start] = 0;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int u = q.front();
		cout << q.front() << " ";
		q.pop();
		for (int i = 0; i < (int)listG[u].size(); i++) {
			int v = listG[u][i];
			if (!used[v] && listG[u][i] != start) {
				used[v] = true;
				p[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	cout << endl;
	for (int i = 0; i < (int)listG.size(); i++)
	{
		cout << "–ассто€ние до " << i << "-ой верины: " << dist[i] << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "RUS");
	vector<vector<int>> tmp = vector<vector<int>>(5);
	vector<vector<bool>> matrix;
	tmp[0] = { 1, 2, 3, 4 };
	tmp[1] = { 0, 2, 4 };
	tmp[2] = { 0, 1 };
	tmp[3] = { 0, 4 };
	tmp[4] = { 0, 1, 3 };

	
	show(tmp);
	matrix = f(tmp);
	show(matrix);
	tmp = f(matrix);
	show(tmp);
	dfs(tmp, 0);
	bfs(tmp, 0);
}