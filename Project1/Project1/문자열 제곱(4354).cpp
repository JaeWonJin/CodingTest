// https://www.acmicpc.net/problem/4354
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Text;
vector<int> vecPi;

void CalcPi()
{
	int j = 0;
	for (int i = 1; i < Text.size(); ++i)
	{
		while (j > 0 && Text[i] != Text[j]) j = vecPi[j - 1];
		if (Text[i] == Text[j])
		{
			++j;
			vecPi[i] = j;
		}
	}
}

int Kmp(const string& _Pattern)
{
	int Cnt = 0;
	int j = 0;
	for (int i = 0; i < Text.size(); ++i)
	{
		while (j > 0 && Text[i] != _Pattern[j]) j = vecPi[j - 1];
		if (Text[i] == _Pattern[j])
		{
			if (j == _Pattern.size() - 1)
			{
				++Cnt;
				j = vecPi[j];
			}
			else
			{
				++j;
			}
		}
	}
	return Cnt;
}

int FindMaxN()
{
	int j = Text.size() - 1;
	while (j)
	{
		int PatSize = vecPi[j];
		if (PatSize == 0) return 1;
		if (Text.size() % PatSize == 0)
		{
			string Pattern = Text.substr(0, PatSize);
			int Cnt = Kmp(Pattern);
			if (Cnt * PatSize == Text.size()) return Cnt;
		}
		j = vecPi[j - 1];
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1)
	{
		getline(cin, Text);
		if (Text == ".") break;
		vecPi.assign(Text.size(), 0);
		CalcPi();
		
		//cout << FindMaxN() << "\n";

		int MatchedLen = vecPi[Text.size() - 1];
		int UnitLen = Text.size() - MatchedLen;
		if (Text.size() % UnitLen == 0) cout << Text.size() / UnitLen << "\n";
		else cout << 1 << "\n";
	}

	return 0;
}