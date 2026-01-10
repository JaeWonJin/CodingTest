#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vecScores;
vector<int> vecDP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecScores.assign(N + 1, 0);
	vecDP.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> vecScores[i];
	}

	vecDP[1] = vecScores[1]; vecDP[2] = vecDP[1] + vecScores[2];
	for (int i = 3; i <= N; ++i)
	{
		vecDP[i] = max(vecDP[i - 2] + vecScores[i], vecDP[i - 3] + vecScores[i - 1] + vecScores[i]);
	}

	cout << vecDP[N];

	return 0;
}