#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CmpFunc(const pair<int, int>& _A, const pair<int, int>& _B)
{
	if (_A.first < _B.first) return true;

	return false;
}

void KSum_Comb(vector<pair<int, int>>& _vecSorted, vector<int>& _vecCurComb, vector<int>& _vecBestComb, int _Start, int& _Best, int _Target, int _Sum, int _Cnt)
{
	if (_Cnt == 0)
	{
		if (_Sum >= _Best)
		{
			_Best = _Sum;
			// 현재 사용중인 조합 옮겨담기
			_vecBestComb = _vecCurComb;
		}
		return;
	}
	for (int i = _Start; i < _vecSorted.size(); ++i)
	{
		if (i + _Cnt > _vecSorted.size())
		{
			break;
		}
		// 정렬되어 있는 배열이므로, i보다 큰 인덱스의 배열값은 현재 i의 배열값보다 크거나 같다
		// 따라서 뒤에 있는 조합은 고려할 필요가 없다
		if (_Sum + _vecSorted[i].first > _Target)
		{
			return;
		}

		// 스택에 조합 넣어주기
		_vecCurComb.push_back(_vecSorted[i].second);
		KSum_Comb(_vecSorted, _vecCurComb, _vecBestComb, i + 1, _Best, _Target, _Sum + _vecSorted[i].first, _Cnt - 1);
		// 넣었던 조합 빼주기
		_vecCurComb.pop_back();

	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> vecPair(N), vecPairSorted;
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPair[i].first;
		vecPair[i].second = i;
	}
	vecPairSorted = vecPair;
	sort(vecPairSorted.begin(), vecPairSorted.end(), &CmpFunc);

	int Best = 0;
	vector<int> vecCurComb, vecBestComb;

	KSum_Comb(vecPairSorted, vecCurComb, vecBestComb, 0, Best, M, 0, 3);

	cout << Best << "\n";
	for (int i = 0; i < vecBestComb.size(); ++i)
	{
		cout << vecPair[vecBestComb[i]].first << " ";
	}

	return 0;
}