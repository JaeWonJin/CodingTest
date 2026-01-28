// https://school.programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Cmp
{
    bool operator()(int _A, int _B) { return _A > _B; }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, Cmp> pq;
    for (auto Num : scoville) pq.push(Num);
    while (!pq.empty())
    {
        int LeastS = pq.top();
        if (LeastS >= K) break;
        pq.pop();
        if (pq.empty())
        {
            answer = -1;
            break;
        }
        int SecondLeastS = pq.top();
        pq.pop();
        int NewS = LeastS + 2 * SecondLeastS;
        ++answer;
        pq.push(NewS);
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 3, 9, 10, 12 }, 7);
    return 0;
}