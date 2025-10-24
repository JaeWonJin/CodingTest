// https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> vecCoins;
int CoinCnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	vecCoins.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecCoins[i];
	}


	for (int i = N - 1; i >= 0; --i)
	{
		if(K >= vecCoins[i])
		{
			CoinCnt += (K / vecCoins[i]);
			K %= vecCoins[i];
		}
	}

	cout << CoinCnt;

	return 0;
}