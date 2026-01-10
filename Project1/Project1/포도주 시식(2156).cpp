// https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecDP;
int Best = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N + 1, 0);
	vecDP.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> vecNums[i];
	}

	vecDP[1] = vecNums[1];
	Best = vecDP[1];
	if (N >= 2) 
	{
		vecDP[2] = vecDP[1] + vecNums[2];
		Best = max(Best, vecDP[2]);
	}
	for (int i = 3; i <= N; ++i)
	{
		vecDP[i] = max( vecDP[i - 1], max(vecDP[i - 2] + vecNums[i], vecDP[i - 3] + vecNums[i - 1] + vecNums[i]));
	}

	cout << vecDP[N];
}