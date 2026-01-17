// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <vector>

using namespace std;

#define INF 100000000

int N, E;
vector<vector<int>> vecDist;

int main()
{
	int m1, m2;
	cin >> N >> E;
	vecDist.assign(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		vecDist[u][v] = w;
		vecDist[v][u] = w;
	}
	cin >> m1 >> m2;
	for (int u = 1; u <= N; ++u)
	{
		vecDist[u][u] = 0;
	}

	for (int m = 1; m <= N; ++m)
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int e = 1; e <= N; ++e)
			{
				if (vecDist[s][m] == INF) continue;
				if (vecDist[s][e] > vecDist[s][m] + vecDist[m][e])
				{
					vecDist[s][e] = vecDist[s][m] + vecDist[m][e];
					vecDist[e][s] = vecDist[s][e];
				}
			}
		}
	}


	long long path1 = (long long)vecDist[1][m1] + vecDist[m1][m2] + vecDist[m2][N];
	long long path2 = (long long)vecDist[1][m2] + vecDist[m2][m1] + vecDist[m1][N];

	long long Ans = min(path1, path2);

	if (Ans >= INF) cout << -1;
	else cout << Ans;

	return 0;
}