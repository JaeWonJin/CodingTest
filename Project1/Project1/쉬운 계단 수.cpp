// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>

using namespace std;

#define NUM 1000000000

int N;
vector<vector<long long>> vecDP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecDP.assign(N + 1, vector<long long>(10, 0));

	for (int i = 0; i < 10; ++i) vecDP[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
			{
				vecDP[i][j] = vecDP[i - 1][j + 1];
			}
			else if (j == 9)
			{
				vecDP[i][j] = vecDP[i - 1][j - 1];
			}
			else
			{
				vecDP[i][j] = (vecDP[i - 1][j - 1] + vecDP[i - 1][j + 1]) % NUM;
			}
		}
	}

	long long Ans = 0;
	for (int i = 1; i < 10; ++i)
	{
		Ans += vecDP[N][i];
		Ans = Ans % NUM;
	}
	cout << Ans;

	return 0;
}