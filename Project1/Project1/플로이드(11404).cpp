// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <vector>

using namespace std;

#define INF 100000000

int N, M;
vector<vector<int>> vecDist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecDist.assign(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i)
	{
		vecDist[i][i] = 0;
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if(vecDist[u][v] > w) vecDist[u][v] = w;
	}

	for (int m = 1; m <= N; ++m)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (vecDist[i][m] == INF || vecDist[m][j] == INF) continue;

				if (vecDist[i][j] > vecDist[i][m] + vecDist[m][j])
				{
					vecDist[i][j] = vecDist[i][m] + vecDist[m][j];
				}
			}
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (vecDist[i][j] == 0 || vecDist[i][j] == INF) cout << "0 ";
			else cout << vecDist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}