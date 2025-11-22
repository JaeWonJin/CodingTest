#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> vecNums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int TestCase = 1; TestCase <= T; ++TestCase)
	{
		cin >> N;
		long long Ans = 0;
		int CurMaxVal = 0;
		vecNums.assign(N, 0);

		for (int j = 0; j < N; ++j) cin >> vecNums[j];

		CurMaxVal = vecNums[N - 1];
		for (int j = N - 1; j >= 0; --j)
		{
			if (CurMaxVal <= vecNums[j])
			{
				CurMaxVal = vecNums[j];
			}
			else
			{
				Ans += (CurMaxVal - vecNums[j]);
			}
		}

		cout << "#" << TestCase << " " << Ans << "\n";
	}
	return 0;
}