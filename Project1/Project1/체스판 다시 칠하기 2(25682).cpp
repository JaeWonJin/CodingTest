// https://www.acmicpc.net/problem/25682
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, K;
vector<string> vecBoard;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	vecBoard.assign(N, "");
	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
	}
	return 0;
}