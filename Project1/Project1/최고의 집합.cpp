// https://school.programmers.co.kr/learn/courses/30/lessons/12938
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n >= s) return vector<int>(1, -1);

    int Avg = s / n;
    int Remain = s % n;
    answer.assign(n, Avg);
    for (int i = n - 1; i >= 0; --i)
    {
        if (Remain == 0) break;
        answer[i] += 1;
        Remain -= 1;
    }

    //sort(answer.begin(), answer.end());
    return answer;
}

int main()
{

    vector<int> Ans = solution(3, 8);

    return 0;
}