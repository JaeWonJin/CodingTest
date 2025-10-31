// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vecNums, vecSums;
vector<int> vecAns;

void PrefixSum()
{
	int Sum = 0;
	for (int i = 1; i < vecNums.size(); ++i)
	{
		Sum += vecNums[i];
		vecSums[i] = Sum;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecNums.assign(N + 1, 0);
	vecSums.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i) cin >> vecNums[i];

	PrefixSum();

	int Start, End;
	for (int i = 0; i < M; ++i)
	{
		cin >> Start >> End;
		vecAns.push_back(vecSums[End] - vecSums[Start - 1]);
	}

	for (int i = 0; i < M; ++i)
	{
		cout << vecAns[i] << "\n";
	}

	return 0;
}