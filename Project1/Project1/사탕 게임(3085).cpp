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
	// ������
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
	// �����
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

	// ���ϴ����� �����ϴ� �������θ� �˻��Ͽ� �ߺ� ��ȯ ���ϱ�
	int dx[2] = { 1, 0, };
	int dy[2] = { 0, 1, };

	// ��ȯ ������ �ʱ� ���尪 �˻�
	for (int i = 0; i < N; ++i)
	{
		// ��� �� ���� �˻�
		CalcBestSeqCol(vecStr, Best, N, i);
		// ��� �� ���� �˻�
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
				// ��ȿ���� ���� �ε��� ����
				if (IsValidIdx(N, NextCol, NextRow) == false) continue;
				// ���� ���� ���ڸ� ����
				if (vecStr[Row][Col] == vecStr[NextRow][NextCol]) continue;

				// ���� ���ڸ� ��ȯ�� ��, ������ ���� �� ���� üũ
				char Temp = vecStr[NextRow][NextCol];
				vecStr[NextRow][NextCol] = vecStr[Row][Col];
				vecStr[Row][Col] = Temp;

				CalcBestSeqCol(vecStr, Best, N, Col);
				CalcBestSeqRow(vecStr, Best, N, Row);
				CalcBestSeqCol(vecStr, Best, N, NextCol);
				CalcBestSeqRow(vecStr, Best, N, NextRow);

				// ��ȯ�ߴ� ���� ����
				Temp = vecStr[NextRow][NextCol];
				vecStr[NextRow][NextCol] = vecStr[Row][Col];
				vecStr[Row][Col] = Temp;
			}
		}
	}

	cout << Best;

	return 0;
}