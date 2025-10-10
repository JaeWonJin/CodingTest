#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> vecPoints(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPoints[i].first >> vecPoints[i].second;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << vecPoints[i].first << ' ' << vecPoints[i].second << "\n";
	}

	return 0;
}