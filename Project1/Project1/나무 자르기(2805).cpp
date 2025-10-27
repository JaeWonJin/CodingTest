// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long M;
vector<long long> vecHeights;

int UpperBound(long long _Key)
{
	int Left = 0;
	int Right = vecHeights.size();
	while (Left < Right)
	{
		int Mid = Left + (Right - Left) / 2;
		if (vecHeights[Mid] > _Key)
		{
			Right = Mid;
		}
		else
		{
			Left = Mid + 1;
		}
	}

	return Left;
}

long long GetRemainHeight(int _Idx, long long _Height)
{
	long long Sum = 0;
	for (int i = _Idx; i < vecHeights.size(); ++i)
	{
		Sum += (vecHeights[i] - _Height);
	}
	return Sum;
}

int main()
{
	cin >> N >> M;
	vecHeights.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecHeights[i];
	}
	sort(vecHeights.begin(), vecHeights.end(), less<long long>());

	long long MinH = 0;
	long long MaxH = vecHeights.back();
	long long SumHeight = 0;
	long long Ans = 0;
	while (MinH <= MaxH)
	{
		long long MidH = MinH + (MaxH - MinH) / 2;
		int Idx = UpperBound(MidH);
		SumHeight = GetRemainHeight(Idx, MidH);
		if (SumHeight >= M)
		{
			MinH = MidH + 1;
			Ans = MidH;
		}
		else
		{
			MaxH = MidH - 1;
		}
	}

	cout << Ans;

	return 0;
}