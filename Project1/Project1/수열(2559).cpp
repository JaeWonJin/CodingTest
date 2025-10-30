// https://www.acmicpc.net/problem/1940
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> vecNums;
int MaxSum = static_cast<int>(-(1 << 31));

void SlidingWindow()
{
	int Left = 0;
	int Right = K - 1;
	int CurSum = 0;
	for (int i = 0; i < K; ++i)
	{
		CurSum += vecNums[i];
	}
	MaxSum = CurSum;

	while (Right < N - 1)
	{
		CurSum -= vecNums[Left];
		++Left;
		++Right;
		CurSum += vecNums[Right];
		if (CurSum > MaxSum)
		{
			MaxSum = CurSum;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];


	SlidingWindow();

	cout << MaxSum;
	return 0;
}