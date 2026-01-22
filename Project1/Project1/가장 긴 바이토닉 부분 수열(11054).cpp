//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecDP;
vector<int> vecRevDP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0); vecDP.assign(N, 1); vecRevDP.assign(N, 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNums[i];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (vecNums[i] > vecNums[j])
			{
				vecDP[i] = max(vecDP[i], vecDP[j] + 1);
			}
		}
	}
	for (int i = N - 2; i >= 0; --i)
	{
		for (int j = N - 1; j > i; --j)
		{
			if (vecNums[i] > vecNums[j])
			{
				vecRevDP[i] = max(vecRevDP[i], vecRevDP[j] + 1);
			}
		}
	}
	int Ans = 1;
	for (int i = 0; i < N; ++i) Ans = max(Ans, vecDP[i] + vecRevDP[i] - 1);

	cout << Ans;

}