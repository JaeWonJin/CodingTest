#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> g_vecComb;
vector<int> g_vecIsPicked;

void CalcComb(int _Start, int _RemainCnt)
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
	for (int i = _Start; i <= N; ++i)
	{
		g_vecComb.push_back(i);
		CalcComb(i, _RemainCnt - 1);
		g_vecComb.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	g_vecIsPicked.resize(N + 1);

	CalcComb(1, M);


	return 0;
}