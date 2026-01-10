// https://www.acmicpc.net/problem/21736
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;
int Ans = 0;
vector<string> vecBoard;
vector<vector<char>> vecVisited;

bool IsValid(int _Row, int _Col)
{
	return (_Row >= 0 && _Row < N && _Col >= 0 && _Col < M);
}

void BFS(const pair<int, int>& _Pos)
{
	queue<pair<int, int>> q;
	q.push(_Pos);
	vecVisited[_Pos.first][_Pos.second] = 1;

	while (!q.empty())
	{
		pair<int, int> Pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Pos.first + dy[i], Pos.second + dx[i]);
			if (!IsValid(Next.first, Next.second)) continue;
			if (vecVisited[Next.first][Next.second]) continue;
			if (vecBoard[Next.first][Next.second] == 'X') continue;
			switch (vecBoard[Next.first][Next.second])
			{
			case 'X':
				break;
			case 'P':
				++Ans;
			case 'O':
				q.push(Next);
				vecVisited[Next.first][Next.second] = 1;
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pair<int, int> StartPos;

	cin >> N >> M;
	vecBoard.assign(N, "");
	vecVisited.assign(N, vector<char>(M, 0));
	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
		for (int j = 0; j < M; ++j)
		{
			if (vecBoard[i][j] == 'I')
			{
				StartPos = make_pair(i, j);
			}
		}
	}



	BFS(StartPos);

	if (Ans) cout << Ans;
	else cout << "TT";

	return 0;
}