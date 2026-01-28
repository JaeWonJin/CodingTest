// https://www.acmicpc.net/problem/1305
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
vector<int> vecPi;
string Text;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L;
	cin >> Text;
	vecPi.assign(L, 0);

	int j = 0;
	for (int i = 1; i < L; ++i)
	{
		while (j > 0 && Text[i] != Text[j]) j = vecPi[j - 1];

		if (Text[i] == Text[j])
		{
			++j;
			vecPi[i] = j;
		}
	}

	cout << L - vecPi[L - 1];

	return 0;
}