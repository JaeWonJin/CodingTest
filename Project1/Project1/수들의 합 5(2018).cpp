	// https://www.acmicpc.net/problem/2018
	#include <iostream>
	#include <vector>

	using namespace std;

	int N;
	int AnsCnt = 0;

	void SlidingWindow()
	{
		int Sum = 1;
		int Left = 1;
		int Right = 1;

		while (Left <= Right)
		{
			if (Sum >= N)
			{
				if (Sum == N) 
				{
					++AnsCnt;
				}
				Sum -= Left;
				++Left;
			}
			else if (Sum < N)
			{
				++Right;
				Sum += Right;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		cin >> N;

		SlidingWindow();

		cout << AnsCnt;

		return 0;
	}