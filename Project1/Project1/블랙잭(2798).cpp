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
		// ���� ������ ���� �Ұ� �� �� ū i������ �Ұ��̹Ƿ� break
		if (i + _Cnt > _vecSorted.size())
		{
			break;
		}
		// ���ĵǾ� �ִ� �迭�̹Ƿ�, i���� ū �ε����� �迭���� ���� i�� �迭������ ũ�ų� ����
		// ���� �ڿ� �ִ� ������ ����� �ʿ䰡 ����
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