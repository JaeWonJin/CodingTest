// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string strEquation;

int AnsNum = 0;
int CurNum = 0;
bool IsMinus = false;

void CalcValue()
{
	if (IsMinus)
	{
		AnsNum -= CurNum;
	}
	else
	{
		AnsNum += CurNum;
	}
	CurNum = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> strEquation;

	int strIdx = 0;
	for (char c : strEquation)
	{
		if (c >= '0' && c <= '9')
		{
			CurNum *= 10;
			CurNum += ((int)(c - '0'));
		}
		else
		{
			CalcValue();
			if (c == '-')
			{
				IsMinus = true;
			}
		}
		
		++strIdx;
	}
	CalcValue();

	cout << AnsNum;

	return 0;
}