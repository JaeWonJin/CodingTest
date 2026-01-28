// https://school.programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>
#include <queue>

using namespace std;

#include <stack>

vector<int> solution(vector<int> prices) {
    vector<int> answer = vector<int>(prices.size(), 0);
    stack<int> Stack;
    for (int i = 0; i < prices.size(); ++i)
    {
        while (!Stack.empty() && prices[Stack.top()] > prices[i])
        {
            answer[Stack.top()] = i - Stack.top();
            Stack.pop();
        }
        Stack.push(i);
    }
    while (!Stack.empty())
    {
        answer[Stack.top()] = prices.size() - 1 - Stack.top();
        Stack.pop();
    }

    return answer;
}

/*
struct Cmp
{
    bool operator()(const pair<int, int>& _A, const pair<int, int>& _B)
    {
        return _A.first < _B.first;
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer = vector<int>(prices.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
    pq.push(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); ++i)
    {
        while (!pq.empty() && pq.top().first > prices[i])
        {
            pair<int, int> Stock = pq.top();
            pq.pop();
            answer[Stock.second] = (i - Stock.second);
        }
        pq.push(make_pair(prices[i], i));
    }
    while (!pq.empty())
    {
        pair<int, int> Stock = pq.top();
        pq.pop();
        answer[Stock.second] = (prices.size() - 1 - Stock.second);
    }

    return answer;
}*/