// https://www.acmicpc.net/problem/12738
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecTails;
vector<vector<int>> vecIdxCandidates;

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
	for (int i = 0; i < N; ++i) cin >> vecNums[i];

	for (int i = 0; i < N; ++i)
	{
		int Num = vecNums[i];
		int TailIdx = LowerBound(vecTails, Num);
		if (TailIdx >= vecTails.size())
		{
			vecTails.push_back(Num);
			vecIdxCandidates.push_back(vector<int>(1, i));
		}
		else
		{
			vecTails[TailIdx] = Num;
			vecIdxCandidates[TailIdx].push_back(i);
		}
	}

	cout << vecTails.size();


	return 0;
}