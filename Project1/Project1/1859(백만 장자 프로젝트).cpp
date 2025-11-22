// https://swexpertacademy.com/main/main.do
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> vecNums;
vector<pair<int, int>> vecPairs;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		vecPairs.clear();
		vecNums.clear();
		long long Ans = 0;

		vecPairs.assign(N, make_pair(0, 0));
		vecNums.assign(N, 0);
		for (int j = 0; j < N; ++j)
		{
			cin >> vecNums[j];
			vecPairs[j].first = vecNums[j];
			vecPairs[j].second = j;
		}
		sort(vecPairs.begin(), vecPairs.end(), less<pair<int, int>>());
		for (int j = 0; j < N; ++j)
		{
			// 1) 먼저 과거/오늘까지의 날은 전부 제거
			while (!vecPairs.empty() && vecPairs.back().second <= j)
			{
				vecPairs.pop_back();
			}

			// 2) 더 이상 미래에 파는 날이 없다면 끝
			if (vecPairs.empty()) break;

			// 3) 이제 남은 것들 중 "가장 비싼 미래 날"을 사용
			const pair<int, int>& MaxPair = vecPairs.back();

			if (MaxPair.first > vecNums[j])      // future price 가 더 비쌀 때만 사기
			{
				Ans += (MaxPair.first - vecNums[j]);
			}

		}
		cout << "#" << (i + 1) << " " << Ans << "\n";
		

	}

	return 0;
}