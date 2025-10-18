// https://www.acmicpc.net/problem/2798
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void KSum(vector<int>& _vecSorted, int _Start, int& _Best, int _Target, int _Sum, int _Cnt)
{
	if (_Cnt == 0)
	{
		if (_Sum >= _Best)
		{
			_Best = _Sum;
		}
		return;
	}
	for (int i = _Start; i < _vecSorted.size(); ++i)
	{
		// 남은 개수로 조합 불가 → 더 큰 i에서도 불가이므로 break
		if (i + _Cnt > _vecSorted.size())
		{
			break;
		}
		// 정렬되어 있는 배열이므로, i보다 큰 인덱스의 배열값은 현재 i의 배열값보다 크거나 같다
		// 따라서 뒤에 있는 조합은 고려할 필요가 없다
		if (_Sum + _vecSorted[i] > _Target)
		{
			return;
		}

		KSum(_vecSorted, i + 1, _Best, _Target, _Sum + _vecSorted[i], _Cnt - 1);

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> vecInt(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecInt[i];
	}

	sort(vecInt.begin(), vecInt.end(), less<int>());

	int Best = 0;
	KSum(vecInt, 0, Best, M, 0, 3);

	cout << Best;

	return 0;
}