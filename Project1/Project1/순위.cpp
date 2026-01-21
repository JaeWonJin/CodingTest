// https://school.programmers.co.kr/learn/courses/30/lessons/49191
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define INF 0x7FFFFFFF

void Floid(int _N, vector<vector<int>>& _vecDist)
{
    for (int k = 1; k <= _N; ++k)
    {
        for (int i = 1; i <= _N; ++i)
        {
            for (int j = 1; j <= _N; ++j)
            {
                if (_vecDist[i][k] == INF || _vecDist[k][j] == INF) continue;
                if (_vecDist[i][j] > _vecDist[i][k] + _vecDist[k][j])
                {
                    _vecDist[i][j] = _vecDist[i][k] + _vecDist[k][j];
                }
            }
        }
    }
}

int CalcLinkedNode(int _N, int _Node, const vector<vector<int>>& _vecDist, const vector<vector<int>>& _vecRevDist)
{
    int Cnt = 0;
    for (int i = 1; i <= _N; ++i)
    {
        if (i == _Node) continue;
        if (_vecDist[_Node][i] != INF) ++Cnt;
        if (_vecRevDist[_Node][i] != INF) ++Cnt;
    }
    return Cnt;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    vector<vector<int>> vecDist;
    vector<vector<int>> vecRevDist;
    vecDist.assign(n + 1, vector<int>(n + 1, INF));
    vecRevDist.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
    {
        vecDist[i][i] = 0;
        vecRevDist[i][i] = 0;
    }

    int u, v;
    for (int i = 0; i < results.size(); ++i)
    {
        u = results[i][0];
        v = results[i][1];

        vecDist[u][v] = 1;
        vecRevDist[v][u] = 1;
    }

    Floid(n, vecDist);
    Floid(n, vecRevDist);
    
    for (int i = 1; i <= n; ++i)
    {
        int Cnt = CalcLinkedNode(n, i, vecDist, vecRevDist);
        if (Cnt == n - 1) ++answer;
    }

    return answer;
}

int main()
{

    cout << solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}} );
    return 0;
}