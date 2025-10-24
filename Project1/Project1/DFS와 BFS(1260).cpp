// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> vecAdj;
vector<bool> vecVisited;
vector<int> vecOrders;
queue<int> queueBFS;

void PushNode_DFS(int _Node)
{
	vecVisited[_Node] = true;
	vecOrders.push_back(_Node);
}

void DFS(int _Node)
{
	PushNode_DFS(_Node);

	for (int i = 0; i < vecAdj[_Node].size(); ++i)
	{
		int Next = vecAdj[_Node][i];
		if (vecVisited[Next]) continue;
		DFS(Next);
	}
}

void PushNode_BFS(int _Node)
{
	vecVisited[_Node] = true;
	vecOrders.push_back(_Node);
	queueBFS.push(_Node);
}

void BFS(int _Node)
{
	PushNode_BFS(_Node);

	while (!queueBFS.empty())
	{
		int Cur = queueBFS.front();
		queueBFS.pop();

		for (int i = 0; i < vecAdj[Cur].size(); ++i)
		{
			int Next = vecAdj[Cur][i];
			if (vecVisited[Next]) continue;
			PushNode_BFS(Next);
		}

		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> V;
	vecAdj.assign(N + 1, vector<int>(0));
	vecVisited.assign(N + 1, false);
	
	int A, B;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		vecAdj[A].push_back(B);
		vecAdj[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(vecAdj[i].begin(), vecAdj[i].end(), less<int>());
	}

	DFS(V);
	for (int i = 0; i < vecOrders.size(); ++i)
	{
		cout << vecOrders[i] << " ";
	}
	cout << "\n";

	fill(vecVisited.begin(), vecVisited.end(), false);
	vecOrders.clear();

	BFS(V);
	for (int i = 0; i < vecOrders.size(); ++i)
	{
		cout << vecOrders[i] << " ";
	}
}