// https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vecParents;
vector<vector<int>> vecPartys;
vector<char> vecParyKnowsTrue;

int Find(int _X)
{
	if (vecParents[_X] == _X)
		return _X;

	vecParents[_X] = Find(vecParents[_X]);
	return vecParents[_X];
}

void Union(int _A, int _B)
{
	_A = Find(_A);
	_B = Find(_B);

	if (_A == _B) return;

	if (_A > _B)
	{
		int Temp = _A;
		_A = _B;
		_B = Temp;
	}

	vecParents[_B] = _A;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecParents.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i) vecParents[i] = i;
	vecPartys.assign(M, vector<int>());
	vecParyKnowsTrue.assign(M, 0);

	int KnowTrueCnt;
	cin >> KnowTrueCnt;
	int Node = 0;
	for (int i = 0; i < KnowTrueCnt; ++i)
	{
		cin >> Node;
		Union(0, Node);
	}
	int PartySize = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> PartySize;
		vecPartys[i].assign(PartySize, 0);
		for (int j = 0; j < PartySize; ++j)
		{
			cin >> vecPartys[i][j];
			Union(vecPartys[i][0], vecPartys[i][j]);
		}
	}

	int Ans = M;
	for (int i = 0; i < M; ++i)
	{
		if (0 == Find(vecPartys[i][0])) --Ans;
	}

	cout << Ans;

	return 0;
}