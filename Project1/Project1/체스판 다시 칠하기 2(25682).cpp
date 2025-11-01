// https://www.acmicpc.net/problem/25682
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, K;
vector<string> vecBoard;
vector<vector<int>> vecIfStartBlack, vecIfStartWhite;
int Best = static_cast<int>((1U << 31) - 1);

// _Row, _Col이 둘중 하나라도 -1일 경우 0 반환
int GetPSumSafe(const vector<vector<int>>& _vecSums, int _Row, int _Col)
{
	if (_Row < 0 || _Col < 0)
	{
		return 0;
	}
	return _vecSums[_Row][_Col];
}

void CalcNeedPaintCnt(int _Row, int _Col)
{
	int BlackValue = 
		GetPSumSafe(vecIfStartBlack, _Row + K - 1, _Col + K - 1) 
		+ GetPSumSafe(vecIfStartBlack, _Row - 1, _Col - 1) 
		- GetPSumSafe(vecIfStartBlack, _Row + K - 1, _Col - 1) 
		- GetPSumSafe(vecIfStartBlack, _Row - 1, _Col + K - 1);
	int WhiteValue = 
		GetPSumSafe(vecIfStartWhite, _Row + K - 1, _Col + K - 1) 
		+ GetPSumSafe(vecIfStartWhite, _Row - 1, _Col - 1) 
		- GetPSumSafe(vecIfStartWhite, _Row + K - 1, _Col - 1) 
		- GetPSumSafe(vecIfStartWhite, _Row - 1, _Col + K - 1);
	if (Best > BlackValue)
	{
		Best = BlackValue;
	}
	if (Best > WhiteValue)
	{
		Best = WhiteValue;
	}
}

void Prefix2D()
{
	int BlackPrevVal, WhitePrevVal;
	for (int Row = 0; Row < N; ++Row)
	{
		for (int Col = 0; Col < M; ++Col)
		{
			char c = vecBoard[Row][Col];
			bool NeedPaint_Black = false;
			bool NeedPaint_White = false;
			if ((Row + Col) % 2 == 0)
			{
				if (c == 'B')
				{
					NeedPaint_White = true;
				}
				else
				{
					NeedPaint_Black = true;
				}
			}
			else
			{
				if (c == 'B')
				{
					NeedPaint_Black = true;
				}
				else
				{
					NeedPaint_White = true;
				}
			}

			vecIfStartBlack[Row][Col] = 
				GetPSumSafe(vecIfStartBlack, Row - 1, Col) 
				+ GetPSumSafe(vecIfStartBlack, Row, Col - 1) 
				- GetPSumSafe(vecIfStartBlack, Row - 1, Col - 1);
			vecIfStartWhite[Row][Col] = 
				GetPSumSafe(vecIfStartWhite, Row - 1, Col) 
				+ GetPSumSafe(vecIfStartWhite, Row, Col - 1) 
				- GetPSumSafe(vecIfStartWhite, Row - 1, Col - 1);
			if (NeedPaint_Black)
			{
				vecIfStartBlack[Row][Col] += 1;
			}
			if (NeedPaint_White)
			{
				vecIfStartWhite[Row][Col] += 1;
			}
		}
	}


	for (int Row = 0; Row <= N - K; ++Row)
	{
		for (int Col = 0; Col <= M - K; ++Col)
		{
			CalcNeedPaintCnt(Row, Col);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	vecBoard.assign(N, "");
	vecIfStartBlack.assign(N, vector<int>(M, 0));
	vecIfStartWhite.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
	}

	Prefix2D();

	cout << Best;

	return 0;
}