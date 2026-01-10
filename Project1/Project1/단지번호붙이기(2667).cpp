// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N;
vector<vector<char>> vecHouse;
vector<vector<char>> vecVisited;
vector<int> vecRegionAreas;

bool IsValidPos(const pair<int, int>& _Pos)
{
	return (_Pos.first >= 0 && _Pos.first < N && _Pos.second >= 0 && _Pos.second < N);
}

void BFS(int _Row, int _Col)
{
	int Area = 0;
	queue<pair<int, int>> q;
	vecVisited[_Row][_Col] = 1;
	q.push(make_pair(_Row, _Col));
	++Area;

	while (!q.empty())
	{
		pair<int, int> Pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Pos.first + dy[i], Pos.second + dx[i]);
			if (!IsValidPos(Next)) continue;
			if (vecVisited[Next.first][Next.second]) continue;
			if (vecHouse[Next.first][Next.second] == 0) continue;

			vecVisited[Next.first][Next.second] = 1;
			q.push(Next);
			++Area;
		}
	}


	vecRegionAreas.push_back(Area);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecHouse.assign(N, vector<char>(N, 0));
	vecVisited.assign(N, vector<char>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		static string strBuf;
		cin >> strBuf;
		for (int j = 0; j < strBuf.size(); ++j)
		{
			vecHouse[i][j] = (strBuf[j] - '0');
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vecVisited[i][j]) continue;
			if (vecHouse[i][j] == 0) continue;
			BFS(i, j);
		}
	}
	sort(vecRegionAreas.begin(), vecRegionAreas.end());
	cout << vecRegionAreas.size() << "\n";
	for (int i = 0; i < vecRegionAreas.size(); ++i)
	{
		cout << vecRegionAreas[i] << "\n";
	}

}