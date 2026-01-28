// https://www.acmicpc.net/problem/1786
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Text;
string Pattern;
vector<int> vecPi;
vector<int> vecAns;

void CalcPi()
{
	int j = 0;
	for (int i = 1; i < Pattern.size(); ++i)
	{
		while (j > 0 && Pattern[i] != Pattern[j]) j = vecPi[j - 1];

		if (Pattern[i] == Pattern[j])
		{
			++j; vecPi[i] = j;
		}
	}
}

void KMP()
{
	int j = 0;
	for (int i = 0; i < Text.size(); ++i)
	{
		while (j > 0 && Text[i] != Pattern[j]) j = vecPi[j - 1];

		if (Text[i] == Pattern[j])
		{
			if (j == Pattern.size() - 1)
			{
				vecAns.push_back(i - Pattern.size() + 1);
				j = vecPi[j];
			}
			else
			{
				++j;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, Text);
	getline(cin, Pattern);
	vecPi.assign(Pattern.size() , 0);

	CalcPi();
	KMP();

	cout << vecAns.size() << "\n";
	for (int i = 0; i < vecAns.size(); ++i) cout << vecAns[i] + 1 << "\n";

	return 0;
}