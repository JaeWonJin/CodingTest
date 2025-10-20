#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsValidIdx(int _MaxIdx, int _X, int _Y)
{
	if (_X >= 0 && _X < _MaxIdx && _Y >= 0 && _Y < _MaxIdx) return true;

	return false;
}

void CalcBestSeqCol(vector<string>& _vecStr, int& _Best, int _MaxIdx, int _Col)
{
	int Stack = 0;
	char CurColor = '\0';
	// 열고정
	for (int Row = 0; Row < _MaxIdx; ++Row)
	{
		if (_vecStr[Row][_Col] != CurColor)
		{
			CurColor = _vecStr[Row][_Col];
			if (Stack > _Best)
			{
				_Best = Stack;
			}
			Stack = 1;
		}
		else
		{
			++Stack;
		}
	}
	if (Stack > _Best)
	{
		_Best = Stack;
	}
}

void CalcBestSeqRow(vector<string>& _vecStr, int& _Best, int _MaxIdx, int _Row)
{
	int Stack = 0;
	char CurColor = '\0';
	// 행고정
	for (int Col = 0; Col < _MaxIdx; ++Col)
	{
		if (_vecStr[_Row][Col] != CurColor)
		{
			CurColor = _vecStr[_Row][Col];
			if (Stack > _Best)
			{
				_Best = Stack;
			}
			Stack = 1;
		}
		else
		{
			++Stack;
		}
	}
	if (Stack > _Best)
	{
		_Best = Stack;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<string> vecStr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecStr[i];
	}

	int Best = 0;

	// 우하단으로 증가하는 방향으로만 검사하여 중복 교환 피하기
	int dx[2] = { 1, 0, };
	int dy[2] = { 0, 1, };

	// 교환 이전의 초기 최장값 검사
	for (int i = 0; i < N; ++i)
	{
		// 모든 열 관련 검사
		CalcBestSeqCol(vecStr, Best, N, i);
		// 모든 행 관련 검사
		CalcBestSeqRow(vecStr, Best, N, i);
	}

	for (int Row = 0; Row < N; ++Row)
	{
		for (int Col = 0; Col < N; ++Col)
		{
			for (int i = 0; i < 2; ++i)
			{

				int NextCol = Col + dx[i];
				int NextRow = Row + dy[i];
				// 유효하지 않은 인덱스 제외
				if (IsValidIdx(N, NextCol, NextRow) == false) continue;
				// 서로 같은 문자면 제외
				if (vecStr[Row][Col] == vecStr[NextRow][NextCol]) continue;

				// 서로 문자를 교환한 후, 가능한 가장 긴 조합 체크
				char Temp = vecStr[NextRow][NextCol];
				vecStr[NextRow][NextCol] = vecStr[Row][Col];
				vecStr[Row][Col] = Temp;

				CalcBestSeqCol(vecStr, Best, N, Col);
				CalcBestSeqRow(vecStr, Best, N, Row);
				CalcBestSeqCol(vecStr, Best, N, NextCol);
				CalcBestSeqRow(vecStr, Best, N, NextRow);

				// 교환했던 문자 복구
				Temp = vecStr[NextRow][NextCol];
				vecStr[NextRow][NextCol] = vecStr[Row][Col];
				vecStr[Row][Col] = Temp;
			}
		}
	}

	cout << Best;

	return 0;
}