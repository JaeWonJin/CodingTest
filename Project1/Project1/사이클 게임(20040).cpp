// https://www.acmicpc.net/problem/20040
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vecParents;

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
	vecParents.assign(N, 0);
	for (int i = 0; i < N; ++i) vecParents[i] = i;
	int Ans = 0;
	int u, v;
	vector<pair<int, int>> vecEdges;
	for (int i = 1; i <= M; ++i)
	{
		cin >> u >> v;
		vecEdges.push_back(make_pair(u, v));
		if (Find(u) == Find(v))
		{
			if(Ans == 0) Ans = i;
		}
		Union(u, v);
	}

	cout << Ans;

	return 0;
}