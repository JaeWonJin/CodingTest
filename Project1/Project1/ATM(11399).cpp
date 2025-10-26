// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> vecPair;
int Time = 0;

bool CmpFunc(const pair<int, int>& _A, const pair<int, int>& _B)
{
	return _A.second < _B.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecPair.assign(N, make_pair(0, 0));
	for (int i = 0; i < N; ++i)
	{
		vecPair[i].first = i;
		cin >> vecPair[i].second;
	}

	sort(vecPair.begin(), vecPair.end(), &CmpFunc);

	for (int i = 0; i < N; ++i)
	{
		Time += ((N - i) * vecPair[i].second);
	}

	cout << Time;

	return 0;
}