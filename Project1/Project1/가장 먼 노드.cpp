// https://school.programmers.co.kr/learn/courses/30/lessons/49189
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void PushNode_BFS(queue<int>& _q, vector<char>& _vecVisited, int _Start)
{
    _vecVisited[_Start] = 1;
    _q.push(_Start);
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> vecAdj = vector<vector<int>>(n + 1, vector<int>());
    vector<char> vecVisited = vector<char>(n + 1, 0);
    vector<int> vecDist = vector<int>(n + 1, 0);

    for (int i = 0; i < edge.size(); ++i)
    {
        int s = edge[i][0];
        int e = edge[i][1];
        vecAdj[s].push_back(e);
        vecAdj[e].push_back(s);
    }

    queue<int> q;

    PushNode_BFS(q, vecVisited, 1);
    while (!q.empty())
    {
        int Node = q.front();
        q.pop();
        for (int i = 0; i < vecAdj[Node].size(); ++i)
        {
            int Next = vecAdj[Node][i];
            if (vecVisited[Next] != 0) continue;

            vecDist[Next] = vecDist[Node] + 1;
            PushNode_BFS(q, vecVisited, Next);
        }
    }

    sort(vecDist.begin(), vecDist.end());
    int MaxDist = vecDist[vecDist.size() - 1];
    for (int i = n; i >= 1; --i)
    {
        if (MaxDist == vecDist[i]) ++answer;
        else break;
    }

    return answer;
}

int main()
{
    vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };
    cout << solution(6, edge);
}