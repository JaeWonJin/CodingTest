#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> vecAdj(N + 1);
	int A, B;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		vecAdj[A].push_back(B);
		vecAdj[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << i << ": ";
		for (int j = 0; j < vecAdj[i].size(); ++j)
		{
			cout << vecAdj[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}