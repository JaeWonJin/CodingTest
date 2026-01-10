// https://school.programmers.co.kr/learn/courses/30/lessons/42627
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct tRequest
{
    int ReqTime;
    int Duration;
    int Index;
};

struct tCmp
{
    bool operator()(const tRequest& _A, const tRequest& _B)
    {
        if (_A.Duration != _B.Duration) return _A.Duration > _B.Duration;
        if (_A.ReqTime != _B.ReqTime) return _A.ReqTime > _B.ReqTime;
        return _A.Index > _B.Index;
    }
};

tRequest ToRequest(int _Index, const vector<int>& _Job)
{
    tRequest ret;
    ret.Index = _Index;
    ret.ReqTime = _Job[0];
    ret.Duration = _Job[1];

    return ret;
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());

    int answer = 0;
    priority_queue<tRequest, vector<tRequest>, tCmp> pq;

    int i = 0;
    int CurTime = 0;
    bool IsWorking = false;
    tRequest CurReq;
    int TotalFinishedTimer = 0;
    while (1)
    {
        if (IsWorking)
        {
            if(CurReq.Duration) CurReq.Duration -= 1;

            if (CurReq.Duration == 0)
            {
                TotalFinishedTimer += (CurTime - CurReq.ReqTime);
                IsWorking = false;
                if (i == jobs.size() && pq.empty())
                {
                    break;
                }
            }
        }

        while (i < jobs.size() && CurTime == jobs[i][0])
        {
            pq.push(ToRequest(i, jobs[i]));
            ++i;
        }

        if (!IsWorking)
        {
            if (!pq.empty())
            {
                CurReq = pq.top();
                pq.pop();
                IsWorking = true;
            }
        }

        ++CurTime;
    }


    
    answer = TotalFinishedTimer / jobs.size();

    return answer;
}


int main()
{
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {3, 5} };
    cout << solution(jobs);
    return 0;
}