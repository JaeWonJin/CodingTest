// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vecNums;
vector<int> vecAns(2);
int BestSum;
int BestAbs;

void TwoPointers()
{
	int Left = 0; 
	int Right = vecNums.size() - 1;
	BestSum = vecNums[Right] + vecNums[Left];
	BestAbs = abs(BestSum);
	vecAns[0] = vecNums[Left]; vecAns[1] = vecNums[Right];
	while (Left < Right)
	{
		int Result = vecNums[Right] + vecNums[Left];
		int ResultAbs = abs(Result);
		if (ResultAbs < BestAbs)
		{
			BestSum = Result;
			BestAbs = ResultAbs;
			vecAns[0] = vecNums[Left]; vecAns[1] = vecNums[Right];
		}
		if (Result >= 0)
		{
			--Right;
		}
		else
		{
			++Left;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];
	sort(vecNums.begin(), vecNums.end(), less<int>());

	TwoPointers();
	cout << vecAns[0] << " " << vecAns[1];

	return 0;
}