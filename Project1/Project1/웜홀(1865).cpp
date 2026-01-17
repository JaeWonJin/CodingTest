// https://www.acmicpc.net/problem/1865
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_INT 0x7FFFFFFF

int TC;
int N, M, W;
vector<tuple<int, int, int>> vecEdges;
vector<long long> vecDist;

bool BellmanFord()
{
	bool bUpdate = false;

	int u, v, w;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < vecEdges.size(); ++j)
		{
			u = get<0>(vecEdges[j]);
			v = get<1>(vecEdges[j]);
			w = get<2>(vecEdges[j]);

			if (vecDist[v] > vecDist[u] + w)
			{
				vecDist[v] = vecDist[u] + w;
			}
		}
	}

	for (int j = 0; j < vecEdges.size(); ++j)
	{
		u = get<0>(vecEdges[j]);
		v = get<1>(vecEdges[j]);
		w = get<2>(vecEdges[j]);

		if (vecDist[v] > vecDist[u] + w)
		{
			vecDist[v] = vecDist[u] + w;
			if (!bUpdate) bUpdate = true;
		}
	}

	return bUpdate;
}


void SolveTC()
{
	cin >> N >> M >> W;
	vecDist.assign(N + 1, MAX_INT);
	vecEdges.clear();

	int u, v, w;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		vecEdges.push_back(make_tuple(u, v, w));
		vecEdges.push_back(make_tuple(v, u, w));
	}
	for (int i = 0; i < W; ++i)
	{
		cin >> u >> v >> w;
		vecEdges.push_back(make_tuple(u, v, -w));
	}

	bool bHasNegativeCycle = BellmanFord();
	if (bHasNegativeCycle) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	for (int i = 0; i < TC; ++i)
	{
		SolveTC();
	}

	return 0;
}