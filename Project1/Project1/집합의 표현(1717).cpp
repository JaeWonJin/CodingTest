// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vecParents;
vector<int> vecRanks;

int Find(int _x)
{
	if (_x == vecParents[_x])
		return _x;

	vecParents[_x] = Find(vecParents[_x]);
	return vecParents[_x];
}

void Union(int _A, int _B)
{
	_A = Find(_A);
	_B = Find(_B);

	if (_A == _B) return;

	if (vecRanks[_B] > vecRanks[_A])
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
	cin >> N >> M;
	vecParents.assign(N + 1, 0);
	vecRanks.assign(N + 1, 1);
	for (int i = 0; i <= N; ++i) vecParents[i] = i;
	int Type, A, B;
	for (int i = 0; i < M; ++i)
	{
		cin >> Type >> A >> B;
		if (Type == 0)
		{
			Union(A, B);
		}
		else
		{
			if (Find(A) == Find(B))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}