// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecDP;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecDP.assign(N + 1, 0);
	vecDP[1] = 0; vecDP[2] = 1;

	for (int i = 2; i <= N; ++i)
	{
		vecDP[i] = vecDP[i - 1] + 1;
		if (i % 3 == 0)
		{
			vecDP[i] = min(vecDP[i], vecDP[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			vecDP[i] = min(vecDP[i], vecDP[i / 2] + 1);
		}
		
	}

	cout << vecDP[N];


	return 0;
}