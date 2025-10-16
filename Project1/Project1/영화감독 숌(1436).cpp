//https://www.acmicpc.net/problem/1436
#include <iostream>
using namespace std;

bool Is666Continues(int _Val)
{
	int Stack = 0;
	while (_Val)
	{
		int Num = _Val % 10;
		if (Num == 6)
		{
			Stack += 1;
		}
		else
		{
			Stack = 0;
		}

		if (Stack == 3)
		{
			return true;
		}

		_Val /= 10;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int Arr[10000] = {};
	int Val = 0;
	int Cnt = 0;

	while (Cnt < 10000)
	{
		Val += 1;
		if (Is666Continues(Val))
		{
			Arr[Cnt] = Val;
			Cnt += 1;
		}
	}



	int N;
	cin >> N;
	cout << Arr[N - 1];


	return 0;
}