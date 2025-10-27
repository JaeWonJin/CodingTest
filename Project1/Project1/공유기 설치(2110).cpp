#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> vecPos;

bool PlaceAvailable(int _Dist)
{
	int Cnt = C - 1;
	int CurIdx = 0;
	int LastIdx = 0;
	while (CurIdx < vecPos.size())
	{
		int Interval = vecPos[CurIdx] - vecPos[LastIdx];
		if (Interval >= _Dist)
		{
			LastIdx = CurIdx;
			--Cnt;
			if (Cnt == 0)
			{
				return true;
			}
		}
		++CurIdx;
	}

	return false;
}

int FindMaxTrue()
{
	int Ans = 0;
	int Left = 0;
	int Right = vecPos.back();
	while (Left <= Right)
	{
		int Mid = Left + (Right - Left) / 2;
		if (PlaceAvailable(Mid))
		{
			Ans = Mid;
			Left = Mid + 1;
		}
		else
		{
			Right = Mid - 1;
		}
	}

	return Ans;
}


int main()
{
	cin >> N >> C;
	vecPos.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPos[i];
	}
	sort(vecPos.begin(), vecPos.end(), less<int>());

	cout << FindMaxTrue();

	return 0;
}