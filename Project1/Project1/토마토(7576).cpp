// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
vector<vector<int>> vecBoard, vecDist;
vector<pair<int, int>> vecInitRiped;
queue<pair<int, int>> queueBFS;
int UnRipeCnt = 0;
int Day = -1;

void Push_BFS(const pair<int, int>& _Point, const pair<int, int>& _Prev)
{
	if (_Point == _Prev)
	{
		vecDist[_Point.first][_Point.second] = 0;
	}
	else
	{
		vecDist[_Point.first][_Point.second] = vecDist[_Prev.first][_Prev.second] + 1;
	}
	queueBFS.push(_Point);
	/*
	cout << _Point.first << " " << _Point.second << "\n";
	for (int Row = 0; Row < N; ++Row)
	{
		for (int Col = 0; Col < M; ++Col)
		{
			cout << vecDist[Row][Col];
		}
		cout << "\n";
	}*/

}

bool IsValidPoint(const pair<int, int>& _Point)
{
	if (_Point.first >= 0 && _Point.first < N && _Point.second >= 0 && _Point.second < M) return true;
	return false;
}

void BFS()
{
	for (int i = 0; i < vecInitRiped.size(); ++i)
	{
		Push_BFS(vecInitRiped[i], vecInitRiped[i]);
	}

	while (!queueBFS.empty())
	{
		pair<int, int> Point = queueBFS.front();
		queueBFS.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Point.first + dy[i], Point.second + dx[i]);
			if (!IsValidPoint(Next)) continue;
			if (vecBoard[Next.first][Next.second] != 0) continue;
			vecBoard[Next.first][Next.second] = 1;

			Push_BFS(Next, Point);
			--UnRipeCnt;
			if (UnRipeCnt == 0)
			{
				Day = vecDist[Next.first][Next.second];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;

	vecBoard.assign(N, vector<int>(M, 0));
	vecDist.assign(N, vector<int>(M, 0));

	for (int Row = 0; Row < N; ++Row)
	{
		for (int Col = 0; Col < M; ++Col)
		{
			cin >> vecBoard[Row][Col];
			if (vecBoard[Row][Col] == 0)
			{
				++UnRipeCnt;
			}
			else if (vecBoard[Row][Col] == 1)
			{
				vecInitRiped.push_back(make_pair(Row, Col));
			}
		}
	}

	if (UnRipeCnt == 0) Day = 0;
	BFS();


	cout << Day;
}