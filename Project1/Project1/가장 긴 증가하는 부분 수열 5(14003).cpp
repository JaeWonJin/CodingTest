// https://www.acmicpc.net/problem/14003
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecTails;
vector<int> vecIdxRecord;

int LowerBound(const vector<int>& _vec, int _Key)
{
	int Left = 0;
	int Right = _vec.size();
	while (Left < Right)
	{
		int Mid = Left + (Right - Left) / 2;
		if (_vec[Mid] >= _Key)
		{
			Right = Mid;
		}
		else
		{
			Left = Mid + 1;
		}
	}

	return Left;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0);
	vecIdxRecord.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];

	for (int i = 0; i < N; ++i)
	{
		int Num = vecNums[i];
		int TailIdx = LowerBound(vecTails, Num);
		if (TailIdx >= vecTails.size())
		{
			vecTails.push_back(Num);
		}
		else
		{
			vecTails[TailIdx] = Num;
		}
		vecIdxRecord[i] = TailIdx;
	}

	vector<int> vecAns = vector<int>(vecTails.size(), 0);
	int CurLLSIdx = vecTails.size() - 1;

	for (int i = N - 1; i >= 0; --i)
	{
		if (vecIdxRecord[i] == CurLLSIdx)
		{
			vecAns[CurLLSIdx] = vecNums[i];
			--CurLLSIdx;
		}
	}

	cout << vecAns.size() << "\n";
	for (int i = 0; i < vecAns.size(); ++i) cout << vecAns[i] << " ";

	return 0;
}