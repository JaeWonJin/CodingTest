#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> g_vecComb;
vector<int> g_vecIsPicked;

void CalcComb(int _RemainCnt)
{
	if (_RemainCnt == 0)
	{
		for (int i = 0; i < g_vecComb.size(); ++i)
		{
			cout << g_vecComb[i] << " ";
		}
		cout << "\n";

		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (g_vecIsPicked[i]) continue;

		g_vecIsPicked[i] = 1;
		g_vecComb.push_back(i);
		CalcComb(_RemainCnt - 1);
		g_vecIsPicked[i] = 0;
		g_vecComb.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	g_vecIsPicked.resize(N + 1);

	CalcComb(M);


	return 0;
}