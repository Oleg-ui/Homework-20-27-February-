#include <iostream>
#include <vector>
using namespace std;

void show(vector<vector<int>> listG) //Выводит на консоль список смежности
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
	cout << "Матрица смежности:" << endl;
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



int main()
{
	setlocale(LC_ALL, "RUS");
	vector<vector<int>> tmp = vector<vector<int>>(5);
	vector<vector<bool>> matrix;
	tmp[0] = { 1, 2, 3, 4 };
	tmp[1] = { 0, 2, 4 };
	tmp[2] = { 1 };
	tmp[3] = { 0, 4 };
	tmp[4] = { 0, 1, 3 };

	
	show(tmp);
	matrix = f(tmp);
	show(matrix);
	tmp = f(matrix);
	show(tmp);
}