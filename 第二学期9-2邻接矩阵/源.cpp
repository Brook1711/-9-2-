#include<iostream>
#include<vector>
using namespace std;
int mininum(int n, int lowcost[])
{
	int min = 10000;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (lowcost[i] != 0 && lowcost[i] != -1 && lowcost[i] < min)
		{
			min = lowcost[i];
			k = i;
		}
	}
	return k;
}

void Prim(int **p, int*&adjvex,int*&lowcost,int n,vector<int> &arcWeight)
{
	for (int i = 0; i < n; i++)
	{
		adjvex[i] = 0;
		lowcost[i] = p[0][i];
	}
	lowcost[0] = -1;
	for (int i = 1; i < n; i++)
	{
		int k = mininum(n, lowcost);
//		cout << "V" << adjvex[k] << "->V" << k << endl;
		arcWeight.push_back(lowcost[k]);
		lowcost[k] = -1;
		for (int j = 0; j < n; j++)
		{
			if (lowcost[j] == 0)
			{
				lowcost[j] = p[k][j];
				adjvex[j] = k;
			}
			else if (lowcost[j] != -1 &&p[k][j]!=0 && p[k][j] < lowcost[j])
			{
				lowcost[j] = p[k][j];
				adjvex[j] = k;
			}
		}
	}
}

int main()
{
	int n;
	vector<int> result;
	cin >> n;
	int * adjvex = new int[n];
	int * lowcost = new int[n];
	int **p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	}
	Prim(p, adjvex, lowcost, n, result);
	int sum(0);
	int size = result.size();
	for (int i = 0; i < size; i++)
		sum += result[i];
	cout << sum;
	return 0;
}