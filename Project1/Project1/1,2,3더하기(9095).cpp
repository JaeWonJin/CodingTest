// https://www.acmicpc.net/problem/9095
#include <iostream>
#include <vector>

using namespace std;
#define MAX_NUM 11

int T;
vector<int> vecDP;
vector<int> vecAns;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	vecDP.assign(MAX_NUM + 1, 0);
	vecAns.reserve(T);
	vecDP[1] = 1; vecDP[2] = 2; vecDP[3] = 4;
	for (int i = 4; i <= MAX_NUM; ++i)
	{
		vecDP[i] = vecDP[i - 3] + vecDP[i - 2] + vecDP[i - 1];
	}
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		vecAns.push_back(vecDP[N]);
	}
	for (int i = 0; i < T; ++i)
	{
		cout << vecAns[i] << "\n";
	}

	return 0;
}