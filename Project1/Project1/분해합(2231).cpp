// https://www.acmicpc.net/problem/2231
#include <iostream>

using namespace std;

int DigitSum(int _M)
{
	int ret = 0;
	while (_M)
	{
		ret += (_M % 10);
		_M /= 10;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int Ans = 0;

	for (int i = 0; i < N; ++i)
	{
		int Sum = i + DigitSum(i);
		if (Sum == N)
		{
			Ans = i;
			break;
		}
	}

	cout << Ans;

	return 0;
}