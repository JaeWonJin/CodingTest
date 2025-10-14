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
			// ���� ������� ���� �Űܴ��
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
		// ���ĵǾ� �ִ� �迭�̹Ƿ�, i���� ū �ε����� �迭���� ���� i�� �迭������ ũ�ų� ����
		// ���� �ڿ� �ִ� ������ ����� �ʿ䰡 ����
		if (_Sum + _vecSorted[i].first > _Target)
		{
			return;
		}

		// ���ÿ� ���� �־��ֱ�
		_vecCurComb.push_back(_vecSorted[i].second);
		KSum_Comb(_vecSorted, _vecCurComb, _vecBestComb, i + 1, _Best, _Target, _Sum + _vecSorted[i].first, _Cnt - 1);
		// �־��� ���� ���ֱ�
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