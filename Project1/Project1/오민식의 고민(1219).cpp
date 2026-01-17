// https://www.acmicpc.net/problem/1219
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

// 최소 비용을 구한 뒤, 부호를 바꿔서 출력한다.
#define MAX_INT 0x7FFFFFFF

int N, M;
int Start, End;
vector<tuple<int, int, int>> vecEdges;
vector<vector<int>> vecRevAdj;
vector<char> vecLinkedWthEnd;
vector<long long> vecWeights;
vector<int> vecEarnMoneys;
vector<int> vecParents;

bool UpdateCost()
{
	bool bUpdate = false;

	int u, v, w;
	for (int i = 0; i < vecEdges.size(); ++i)
	{
		u = get<0>(vecEdges[i]); v = get<1>(vecEdges[i]); w = get<2>(vecEdges[i]);
		w -= vecEarnMoneys[v];

		if (vecWeights[u] == MAX_INT) continue;
		if (vecWeights[v] > vecWeights[u] + w)
		{
			vecWeights[v] = vecWeights[u] + w;
			if(!bUpdate && vecLinkedWthEnd[v]) bUpdate = true;
		}
	}

	return bUpdate;
}

bool BellmanFord()
{
	bool bHasNegativeCycle = false;

	for (int i = 0; i < N - 1; ++i)
	{
		UpdateCost();
	}

	bHasNegativeCycle = UpdateCost();

	return bHasNegativeCycle;
}

void BFS()
{
	queue<int> q;
	q.push(End);
	vecLinkedWthEnd[End] = 1;
	
	while (!q.empty())
	{
		int Node = q.front();
		q.pop();

		for (int i = 0; i < vecRevAdj[Node].size(); ++i)
		{
			int Next = vecRevAdj[Node][i];
			if (vecLinkedWthEnd[Next]) continue;
			q.push(Next);
			vecLinkedWthEnd[Next] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Start >> End >> M;
	vecEarnMoneys.assign(N, 0);
	vecWeights.assign(N, MAX_INT);
	vecLinkedWthEnd.assign(N, 0);
	vecRevAdj.assign(N, vector<int>());
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vecEdges.push_back(make_tuple(u, v, w));
		vecRevAdj[v].push_back(u);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> vecEarnMoneys[i];
	}
	vecWeights[Start] = -vecEarnMoneys[Start];

	BFS();

	bool bHasNegativeCycle = BellmanFord();
	if (vecWeights[End] == MAX_INT)
	{
		cout << "gg\n";
	}
	else
	{
		if (bHasNegativeCycle)
		{
			cout << "Gee\n";
		}
		else
		{
			cout << -vecWeights[End] << "\n";
		}
	}

	return 0;
}