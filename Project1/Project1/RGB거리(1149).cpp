// https://www.acmicpc.net/problem/1149
#include <iostream>
#include <vector>

using namespace std;

#define COLOR_NUM 3

int N;
vector<vector<int>> vecCosts;
vector<vector<int>> vecDP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;

	vecCosts.assign(N + 1, vector<int>(COLOR_NUM, 0));
	vecDP.assign(N + 1, vector<int>(COLOR_NUM, 0));
	for (int Row = 1; Row <= N; ++Row)
	{
		for (int Col = 0; Col < COLOR_NUM; ++Col)
		{
			cin >> vecCosts[Row][Col];
			vecDP[Row][Col] = 0x7FFFFFFF;
		}
	}

	for (int Col = 0; Col < COLOR_NUM; ++Col) { vecDP[1][Col] = vecCosts[1][Col]; }
	for (int Row = 2; Row <= N; ++Row)
	{
		for(int Col = 0; Col < COLOR_NUM; ++Col)
		{
			int OtherCol = Col;
			for (int i = 0; i < COLOR_NUM - 1; ++i)
			{
				++OtherCol;
				if (OtherCol >= COLOR_NUM) OtherCol = 0;
				vecDP[Row][Col] = min(vecCosts[Row][Col] + vecDP[Row - 1][OtherCol], vecDP[Row][Col]);
			}
		}
	}

	int Best = 0x7FFFFFFF;
	for (int Col = 0; Col < COLOR_NUM; ++Col)
	{
		Best = min(vecDP[N][Col], Best);
	}

	cout << Best;

	return 0;
}