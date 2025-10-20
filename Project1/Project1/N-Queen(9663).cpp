// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
int CombCnt = 0;
vector<pair<int, int>> vecCurComb;

bool CheckPosValid(int _Row, int _Col)
{
	for (const auto& point : vecCurComb)
	{
		int CmpRow = point.first;
		int CmpCol = point.second;

		if (_Row != CmpRow
			&& _Col != CmpCol
			&& abs(_Row - CmpRow) != abs(_Col - CmpCol))
		{
			continue;
		}

		return false;
	}

	return true;
}

void GetNextPos(int _Row, int _Col, int& _NextRow, int& _NextCol)
{
	_NextRow = _Row;
	_NextCol = _Col + 1;
	if (_NextCol >= N)
	{
		_NextCol = 0;
		++_NextRow;
	}
}

void CalcNQueenComb(int _Row, int _Col, int _RemainCnt)
{
	if (_RemainCnt == 0)
	{
		++CombCnt;
		return;
	}
	if (_Row >= N)
	{
		return;
	}

	int NextRow, NextCol;
	int StartCol = _Col;
	for (int Row = _Row; Row < N; ++Row)
	{
		if (Row > _Row) StartCol = 0;
		for (int Col = StartCol; Col < N; ++Col)
		{
			if (CheckPosValid(Row, Col))
			{
				GetNextPos(Row, Col, NextRow, NextCol);
				vecCurComb.push_back(make_pair(Row, Col));
				CalcNQueenComb(NextRow, NextCol, _RemainCnt - 1);
				vecCurComb.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	CalcNQueenComb(0, 0, N);

	cout << CombCnt;

	return 0;
}