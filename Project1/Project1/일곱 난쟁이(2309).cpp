// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DWARFNUM 9
#define EXTRACTED_DWARFNUM 7
#define TARGET_SUM 100

void KSum(int* _arrSorted, vector<int>& _vecCurComb, vector<int>& _vecAnsComb, int _StartIdx, int _Target, int _Sum, int _Cnt)
{
	// 답을 구했으면 더 구하지 않고 함수 종료
	if (_vecAnsComb.size() > 0)
	{
		return;
	}

	if (_Cnt == 0)
	{
		if (_Sum == _Target)
		{
			_vecAnsComb = _vecCurComb;
		}
		return;
	}

	for (int i = _StartIdx; i < DWARFNUM; ++i)
	{
		// 남은 개수로 조합을 꾸릴 경우의 수가 없을 경우 break
		if (i + _Cnt > DWARFNUM)
		{
			break;
		}

		if (_arrSorted[i] + _Sum > _Target)
		{
			return;
		}

		_vecCurComb.push_back(_arrSorted[i]);
		KSum(_arrSorted, _vecCurComb, _vecAnsComb, i + 1, _Target, _Sum + _arrSorted[i], _Cnt - 1);
		_vecCurComb.pop_back();

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arrHeight[DWARFNUM] = {};
	vector<int> vecCurComb, vecAnsComb;

	for (int i = 0; i < DWARFNUM; ++i)
	{
		cin >> arrHeight[i];
	}

	sort(arrHeight, arrHeight + DWARFNUM, less<int>());

	KSum(arrHeight, vecCurComb, vecAnsComb, 0, TARGET_SUM, 0, EXTRACTED_DWARFNUM);

	for (int i = 0; i < 7; ++i)
	{
		cout << vecAnsComb[i] << "\n";
	}

	return 0;
}