// https://www.acmicpc.net/problem/3273
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> vecNums;
int AnsCnt = 0;

void TwoPointers()
{
	int Left = 0;
	int Right = vecNums.size() - 1;

	while (Left < Right)
	{
		int Result = vecNums[Left] + vecNums[Right];
		if (Result > x)
		{
			--Right;
		}
		else if (Result < x)
		{
			++Left;
		}
		else if (Result == x)
		{
			++Left;
			--Right;
			++AnsCnt;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];
	cin >> x;
	sort(vecNums.begin(), vecNums.end(), less<int>());

	TwoPointers();

	cout << AnsCnt;

	return 0;
}