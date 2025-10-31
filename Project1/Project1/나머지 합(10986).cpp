// https://www.acmicpc.net/problem/10986
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> vecNums, vecRemainderCnts;
long long AnsCnt = 0;

void PrefixSum()
{
	long long Remainder = 0;
	for (int i = 1; i < vecNums.size(); ++i)
	{
		Remainder += vecNums[i];
		Remainder %= M;

		if (Remainder == 0) ++AnsCnt;
		AnsCnt += vecRemainderCnts[Remainder];
		vecRemainderCnts[Remainder] += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecNums.assign(N + 1, 0);
	vecRemainderCnts.assign(M, 0);
	for (int i = 1; i <= N; ++i) cin >> vecNums[i];

	PrefixSum();
	cout << AnsCnt;

	return 0;
}