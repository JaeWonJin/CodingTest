//https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

struct tOrder
{
    int OrderType;      // 0 :: Insert, 1 :: Delete
    int Value;
};

int ToNum(const string& _Input)
{
    int Num = 0;
    bool IsMinus = (_Input[0] == '-');
    int i = (IsMinus) ? (1) : (0);
    for (; i < _Input.size(); ++i)
    {
        Num = Num * 10 + (_Input[i] - '0');
    }
    if (IsMinus) Num = -Num;
    return Num;
}

tOrder ParseOrder(const string& _Input)
{
    tOrder Order;
    switch (_Input[0])  
    {
    case 'I':
        Order.OrderType = 0;
        break;
    case 'D':
        Order.OrderType = 1;
        break;
    }
    Order.Value = ToNum(&_Input[2]);

    return Order;
}

template<typename T>
int RealPop(unordered_map<int, int>& _mapCnts, T& _pq)
{
    while (_mapCnts[_pq.top()] == 0)
    {
        _pq.pop();
    }
    int Value = _pq.top();
    _mapCnts[Value] -= 1;
    _pq.pop();
    return Value;
}
/*
vector<int> solution(vector<string> operations) {
    vector<int> answer = vector<int>(2, 0);
    int RealQueueSize = 0;
    priority_queue<int, vector<int>, less<int>> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    unordered_map<int, int> mapCnts;

    for (const auto& Input : operations)
    {
        tOrder Order = ParseOrder(Input);
        if (Order.OrderType == 0)
        {
            ++RealQueueSize;
            pqMax.push(Order.Value);
            pqMin.push(Order.Value);
            mapCnts[Order.Value]++;
        }
        else if (Order.OrderType == 1)
        {
            if (RealQueueSize == 0) continue;
            --RealQueueSize;
            if (Order.Value == -1)
            {
                RealPop(mapCnts, pqMin);
            }
            else if (Order.Value == 1)
            {
                RealPop(mapCnts, pqMax);
            }
        }
    }
    if (RealQueueSize)
    {
        answer[0] = RealPop(mapCnts, pqMax);
        answer[1] = RealPop(mapCnts, pqMin);
    }

    return answer;
}*/

vector<int> solution(vector<string> operations) {
    vector<int> answer = vector<int>(2, 0);
    multiset<int> setMinMaxQ;


    for (const auto& Input : operations)
    {
        tOrder Order = ParseOrder(Input);
        if (Order.OrderType == 0)
        {
            setMinMaxQ.insert(Order.Value);
        }
        else if (Order.OrderType == 1)
        {
            if (setMinMaxQ.empty()) continue;
            
            if (Order.Value == -1)
            {
                setMinMaxQ.erase(setMinMaxQ.begin());
            }
            else if (Order.Value == 1)
            {
                setMinMaxQ.erase(--setMinMaxQ.end());
            }
        }
    }

    if (!setMinMaxQ.empty())
    {
        answer[0] = *(--setMinMaxQ.end());
        answer[1] = *(setMinMaxQ.begin());
    }

    return answer;
}

int main()
{
    solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
    return 0;
}