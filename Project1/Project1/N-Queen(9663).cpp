// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
int CombCnt = 0;
vector<pair<int, int>> vecCurComb;
vector<int> vecColCheck, vecDiagDownRightCheck, vecDiagDownLeftCheck;

bool CheckPosValid(int _Row, int _Col)
{
	if (vecColCheck[_Col]) return false;
	int DiagDR = (N - 1) - _Col + _Row;
	if (vecDiagDownRightCheck[DiagDR]) return false;
	int DiagDL = _Row + _Col;
	if (vecDiagDownLeftCheck[DiagDL]) return false;

	return true;
}


void PushComb(int _Row, int _Col)
{
	int DiagDR = (N - 1) - _Col + _Row;
	int DiagDL = _Row + _Col;
	vecColCheck[_Col] = 1; vecDiagDownRightCheck[DiagDR] = 1; vecDiagDownLeftCheck[DiagDL] = 1;
	vecCurComb.push_back(make_pair(_Row, _Col));
}

void PopComb()
{
	int Row = vecCurComb.back().first;
	int Col = vecCurComb.back().second;
	int DiagDR = (N - 1) - Col + Row;
	int DiagDL = Row + Col;
	vecColCheck[Col] = 0; vecDiagDownRightCheck[DiagDR] = 0; vecDiagDownLeftCheck[DiagDL] = 0;
	vecCurComb.pop_back();
}

void CalcNQueenComb(int _Row)
{
	if (_Row >= N)
	{
		++CombCnt;
		return;
	}

	for (int Col = 0; Col < N; ++Col)
	{
		if (CheckPosValid(_Row, Col))
		{
			PushComb(_Row, Col);
			CalcNQueenComb(_Row + 1);
			PopComb();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vecColCheck.resize(N);
	vecDiagDownLeftCheck.resize(2 * N - 1);
	vecDiagDownRightCheck.resize(2 * N - 1);

	CalcNQueenComb(0);

	cout << CombCnt;

	return 0;
}