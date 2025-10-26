//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> vecMeetingSchedule;
int MeetingCnt = 0;
int EndTime = 0;

bool CmpFunc(const pair<int, int>& _A, const pair<int, int>& _B)
{
	if (_A.second == _B.second)
	{
		return (_A.first < _B.first);
	}
	return (_A.second < _B.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecMeetingSchedule.assign(N, make_pair(0, 0));
	for (int i = 0; i < N; ++i)
	{
		cin >> vecMeetingSchedule[i].first >> vecMeetingSchedule[i].second;
	}

	sort(vecMeetingSchedule.begin(), vecMeetingSchedule.end(), &CmpFunc);

	for (int i = 0; i < N; ++i)
	{
		//cout << vecMeetingSchedule[i].first << " " << vecMeetingSchedule[i].second << "\n";
		if (EndTime <= vecMeetingSchedule[i].first)
		{
			EndTime = vecMeetingSchedule[i].second;
			++MeetingCnt;
		}
	}

	cout << MeetingCnt;

	return 0;
}