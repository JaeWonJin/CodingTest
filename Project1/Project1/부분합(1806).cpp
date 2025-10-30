// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> vecNums;
int Best;

void SlidingWindow()
{
	int Left = 0;
	int Right = 0;
	int Sum = vecNums[Left];
	Best = N + 1;

	while (Left <= Right)
	{
		if (Sum >= S)
		{
			int Length = Right - Left + 1;
			if (Length < Best)
			{
				Best = Length;
			}
			Sum -= vecNums[Left];
			++Left;
		}
		else
		{
			++Right;
			if (Right >= N)
			{
				break;
			}
			Sum += vecNums[Right];
		}
	}

	if (Best > N)
	{
		Best = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];

	SlidingWindow();

	cout << Best;

	return 0;
}