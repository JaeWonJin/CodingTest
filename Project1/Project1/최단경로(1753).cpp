// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_INT 0x7FFFFFFF

int V, E;
int K;
vector<vector<pair<int, int>>> vecAdj;
vector<int> vecDist;

struct tCmp
{
	bool operator()(const pair<int, int>& _A, const pair<int, int>& _B)
	{
		return _A.second > _B.second;
	}
};

void Dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, tCmp> pq;
	pq.push(make_pair(K, 0));
	while (!pq.empty())
	{
		int u = pq.top().first;
		int u_w = pq.top().second;
		pq.pop();

		for (int i = 0; i < vecAdj[u].size(); ++i)
		{
			int v = vecAdj[u][i].first;
			int v_w = vecAdj[u][i].second;

			int Dist = u_w + v_w;
			if (Dist < vecDist[v])
			{
				vecDist[v] = Dist;
				pq.push(make_pair(v, Dist));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;
	cin >> K;

	vecAdj.assign(V + 1, vector<pair<int, int>>());
	vecDist.assign(V + 1, MAX_INT);
	vecDist[K] = 0;

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vecAdj[u].push_back(make_pair(v, w));
	}

	Dijkstra();

	for (int i = 1; i <= V; ++i)
	{
		if (vecDist[i] == MAX_INT)
		{
			cout << "INF";
		}
		else
		{
			cout << vecDist[i];
		}
		cout << "\n";
	}
}