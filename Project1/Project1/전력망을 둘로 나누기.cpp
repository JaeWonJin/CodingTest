//https://school.programmers.co.kr/learn/courses/30/lessons/86971
#include <string>
#include <vector>
#include <queue>

using namespace std;

void DFS(int _Cur, int _Prev, vector<int>& _vecSubTreeSizes, const vector<vector<int>>& _vecAdj)
{
    for (auto Next : _vecAdj[_Cur])
    {
        if (Next == _Prev) continue;
        DFS(Next, _Cur, _vecSubTreeSizes, _vecAdj);
        _vecSubTreeSizes[_Cur] += _vecSubTreeSizes[Next];
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> vecAdj = vector<vector<int>>(n + 1, vector<int>());
    vector<int> vecSubTreeSizes = vector<int>(n + 1, 1);
    for (const auto& uv : wires)
    {
        int u = uv[0];
        int v = uv[1];
        vecAdj[u].push_back(v);
        vecAdj[v].push_back(u);
    }
    DFS(1, 0, vecSubTreeSizes, vecAdj);

    for (const auto& uv : wires)
    {
        int u = uv[0];
        int v = uv[1];
        int Size1 = min(vecSubTreeSizes[u], vecSubTreeSizes[v]);
        int Size2 = n - Size1;
        answer = min(answer, abs(Size1 - Size2));
    }


    return answer;
}

#include <iostream>
int main()
{
    cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} );
    return 0;
}