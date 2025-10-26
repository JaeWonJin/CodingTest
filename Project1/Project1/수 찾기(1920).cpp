// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vecNums;
vector<int> vecKeys;

bool LowerBound(int _Key)
{
	int Left = 0;
	int Right = vecNums.size();

	while (Left < Right)
	{
		int Mid = Left + (Right - Left) / 2;	// overflow 방지: (l+r)/2 대신
		if (vecNums[Mid] >= _Key)
		{
			// Mid도 후보가 될 수 있음 -> 오른쪽을 버림
			Right = Mid;
		}
		else
		{
			// Mid는 정답이 아님 -> 왼쪽을 버림
			Left = Mid + 1;
		}
	}

	if (Left >= vecNums.size()) return false;
	return (vecNums[Left] == _Key);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecNums.assign(N, 0);
	for (int i = 0; i < N; ++i) cin >> vecNums[i];
	sort(vecNums.begin(), vecNums.end(), less<int>());
	cin >> M;
	vecKeys.assign(M, 0);
	for (int i = 0; i < M; ++i) cin >> vecKeys[i];

	for (int i = 0; i < vecKeys.size(); ++i)
	{
		bool IsKeyExist = LowerBound(vecKeys[i]);
		cout << (int)IsKeyExist << "\n";
	}

	return 0;
}