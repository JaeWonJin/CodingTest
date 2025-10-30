// https://www.acmicpc.net/problem/1940
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vecNums;
int AnsCnt = 0;

void TwoPointers()
{
	int Left = 0;
	int Right = vecNums.size() - 1;

	while (Left < Right)
	{
		int Result = vecNums[Left] + vecNums[Right];
		if (Result > M)
		{
			--Right;
		}
		else if (Result < M)
		{
			++Left;
		}
		else if (Result == M)
		{
			--Right;
			++Left;
			++AnsCnt;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];
	sort(vecNums.begin(), vecNums.end(), less<int>());

	TwoPointers();
	cout << AnsCnt;
}