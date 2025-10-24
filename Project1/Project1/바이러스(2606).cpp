// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> vecAdj;
vector<bool> vecVisited;
int VirusCnt = 0;

void Push_DFS(int _U)
{
	vecVisited[_U] = true;
	VirusCnt += 1;
}

void DFS(int _U)
{
	Push_DFS(_U);

	for (auto V : vecAdj[_U])
	{
		if (vecVisited[V]) continue;

		DFS(V);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecAdj.assign(N + 1, vector<int>());
	vecVisited.assign(N + 1, false);

	int A, B;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		vecAdj[A].push_back(B);
		vecAdj[B].push_back(A);
	}

	DFS(1);

	// 자기 자신은 제외
	--VirusCnt;

	cout << VirusCnt;
}