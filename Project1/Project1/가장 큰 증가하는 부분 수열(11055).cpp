//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecDP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0); vecDP.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNums[i];
		vecDP[i] = vecNums[i];
	}

	int MaxVal = vecDP[0];
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (vecNums[i] > vecNums[j])
			{
				vecDP[i] = max(vecDP[i], vecDP[j] + vecNums[i]);
				MaxVal = max(vecDP[i], MaxVal);
			}
		}
	}

	cout << MaxVal;
	return 0;
}