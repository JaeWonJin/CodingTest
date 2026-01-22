//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> vecBoard;

void Draw(int _N, int _X, int _Y)
{
	if (_N == 1)
	{
		vecBoard[_Y][_X] = '*';
		return;
	}

	int Step = (_N / 3);
	for (int dy = 0; dy < _N; dy += Step)
	{
		for (int dx = 0; dx < _N; dx += Step)
		{
			if (dx == Step && dy == Step) continue;

			Draw(Step, _X + dx, _Y + dy);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecBoard.assign(N, vector<char>(N, ' '));

	Draw(N, 0, 0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << vecBoard[i][j];
		}
		cout << '\n';
	}

}