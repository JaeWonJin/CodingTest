// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_INT 0x7FFFFFFF

int N;
int EdgeNum;
vector<tuple<int, int, int>> vecEdges;
vector<long long> vecDist;

bool BellmanFord()
{
	bool bUpdate = false;
	for (int i = 0; i < vecEdges.size(); ++i)
	{
		int u = get<0>(vecEdges[i]);
		int v = get<1>(vecEdges[i]);
		int w = get<2>(vecEdges[i]);

		if (vecDist[u] == MAX_INT) continue;
		if (vecDist[v] > vecDist[u] + w)
		{
			vecDist[v] = vecDist[u] + w;
			if (!bUpdate) bUpdate = true;
		}
	}


	return bUpdate;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> EdgeNum;
	vecDist.assign(N + 1, MAX_INT);
	vecDist[1] = 0;
	vecEdges.assign(EdgeNum, make_tuple(0, 0, 0));
	for (int i = 0; i < EdgeNum; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		get<0>(vecEdges[i]) = u;
		get<1>(vecEdges[i]) = v;
		get<2>(vecEdges[i]) = w;
	}

	for (int i = 0; i < N - 1; ++i)
	{
		BellmanFord();
	}

	if (BellmanFord()) cout << "-1";
	else
	{
		for (int i = 2; i <= N; ++i)
		{
			if (vecDist[i] == MAX_INT) cout << "-1\n";
			else cout << vecDist[i] << "\n";
		}
	}

	return 0;
}