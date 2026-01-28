// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int CurTotalWeight = 0;
    int NextTruckIdx = 0;
    int Timer = 0;
    queue<pair<int, int>> q;
    while (1)
    {
        ++Timer;
        if (!q.empty())
        {
            if (q.front().second <= Timer)
            {
                q.pop();
                if (q.empty() && NextTruckIdx >= truck_weights.size()) break;
            }
        }
        if (q.size() < bridge_length
            && NextTruckIdx < truck_weights.size()
            && CurTotalWeight + truck_weights[NextTruckIdx] <= weight)
        {
            q.push(make_pair(NextTruckIdx, Timer + bridge_length));
            CurTotalWeight += truck_weights[NextTruckIdx];
            NextTruckIdx += 1;
        }
    }


    return answer;
}