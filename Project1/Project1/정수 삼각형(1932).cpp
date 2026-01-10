// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> vecDP;
vector<vector<int>> vecTriangle;

bool IsValid(int _Depth, int _Idx)
{
	return (_Depth > 0 && _Depth < N&& _Idx >= 0 && _Idx < N);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecDP.assign(N + 1, vector<int>());
	vecTriangle.assign(N + 1, vector<int>());

	for (int i = 1; i <= N; ++i)
	{
		vecTriangle[i].assign(N, 0);
		vecDP[i].assign(N, 0);
		for (int j = 0; j < i; ++j)
		{
			cin >> vecTriangle[i][j];
		}
	}
	vecDP[1][0] = vecTriangle[1][0];

	for (int Depth = 2; Depth <= N; ++Depth)
	{
		for (int Idx = 0; Idx < N; ++Idx)
		{
			int ThisValue = vecTriangle[Depth][Idx];
			if(IsValid(Depth - 1, Idx - 1))
			{
				vecDP[Depth][Idx] = max(vecDP[Depth][Idx], vecDP[Depth - 1][Idx - 1] + ThisValue);
			}
			if (IsValid(Depth - 1, Idx))
			{
				vecDP[Depth][Idx] = max(vecDP[Depth][Idx], vecDP[Depth - 1][Idx] + ThisValue);
			}
		}
	}

	int Best = 0;
	for (int i = 0; i < N; ++i)
	{
		Best = max(vecDP[N][i], Best);
	}

	cout << Best;

	return 0;
}