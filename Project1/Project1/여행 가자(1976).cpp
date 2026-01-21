// https://www.acmicpc.net/problem/1976
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> vecBoard;
vector<int> vecParents;
vector<int> vecRanks;
vector<int> vecCityList;

int Find(int _X)
{
	if (_X == vecParents[_X])
		return _X;

	vecParents[_X] = Find(vecParents[_X]);
	return vecParents[_X];
}

void Union(int _A, int _B)
{
	_A = Find(_A);
	_B = Find(_B);

	if (_A == _B) return;

	if (_B > _A)
	{
		int Temp = _A;
		_A = _B;
		_B = Temp;
	}

	vecParents[_B] = _A;

	if (vecRanks[_A] == vecRanks[_B])
		vecRanks[_A] += 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> M;

	vecBoard.assign(N + 1, vector<int>(N + 1, 0));
	vecParents.assign(N + 1, 0);
	vecRanks.assign(N + 1, 1);
	vecCityList.assign(M, 0);
	for (int i = 1; i <= N; ++i) vecParents[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> vecBoard[i][j];
		}
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> vecCityList[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			if (vecBoard[i][j]) Union(i, j);
		}
	}

	int Root = Find(vecCityList[0]);
	bool bLinked = true;
	for (int i = 0; i < vecCityList.size(); ++i)
	{
		if (Root != Find(vecCityList[i]))
		{
			bLinked = false;
			break;
		}
	}

	if (bLinked)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}


	return 0;
}