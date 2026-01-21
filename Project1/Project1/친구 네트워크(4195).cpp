// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int T, N;
vector<int> vecParents;
vector<int> vecSizes;
unordered_map<string, int> um;
int Index = 0;

int MapNameToNum(const string& _Name)
{
	unordered_map<string, int>::iterator iter = um.find(_Name);
	if (iter == um.end())
	{
		um.insert(make_pair(_Name, Index));
		vecParents.push_back(Index);
		vecSizes.push_back(1);
		++Index;
		iter = um.find(_Name);
	}

	return iter->second;
}

int Find(int _X)
{
	if (_X == vecParents[_X])
		return _X;

	vecParents[_X] = Find(vecParents[_X]);
	return vecParents[_X];
}

int Union(int _A, int _B)
{
	_A = Find(_A);
	_B = Find(_B);

	if (_A == _B) return _A;

	if (_A > _B)
	{
		int Temp = _A;
		_A = _B;
		_B = Temp;
	}

	vecParents[_B] = _A;
	vecSizes[_A] += vecSizes[_B];

	return _A;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string Name1, Name2;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vecParents.clear();
		vecSizes.clear();
		um.clear();
		Index = 0;

		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			cin >> Name1 >> Name2;
			int u = MapNameToNum(Name1);
			int v = MapNameToNum(Name2);
			int Node = Union(u, v);
			cout << vecSizes[Node] << "\n";
		}
	}


	return 0;
}