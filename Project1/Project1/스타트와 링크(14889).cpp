#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> S;
vector<int> vecSums;
vector<int> vecScores;
vector<int> vecPicked;
int BestScoreGap = 0x7FFFFFFF;
vector<vector<int>> vecCases;
vector<int> vecCurComb;

void CalcScore()
{
	int StartScore = 0;
	int LinkScore = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (vecPicked[i] && vecPicked[j])
			{
				StartScore += (S[i][j]);
			}
			else if (vecPicked[i] == 0 && vecPicked[j] == 0)
			{
				LinkScore += (S[i][j]);
			}
		}
	}
	int ScoreGap = abs(StartScore - LinkScore);
	if (ScoreGap < BestScoreGap)
	{
		BestScoreGap = ScoreGap;
	}
}

void BackTrack(int _CurIdx, int _Cnt)
{
	if (_Cnt == 0)
	{
		//vecCases.push_back(vector<int>(vecCurComb));
		CalcScore();
		return;
	}

	for (int i = _CurIdx + 1; i <= N; ++i)
	{
		if (vecPicked[i]) continue;
		vecPicked[i] = 1;
		//vecCurComb.push_back(i);
		BackTrack(i, _Cnt - 1);
		//vecCurComb.pop_back();
		vecPicked[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		S.assign(N + 1, vector<int>(N + 1, 0));
	}
	vecSums.assign(N + 1, 0);
	vecScores.assign(N + 1, 0);
	vecPicked.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> S[i][j];
		}
	}


	BackTrack(0, N / 2);

	cout << BestScoreGap;

	return 0;
}