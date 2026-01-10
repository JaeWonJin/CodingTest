// https://school.programmers.co.kr/learn/courses/30/lessons/81305
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> vecNums;
vector<vector<int>> vecLinks;
vector<int> vecParents;
vector<int> vecSums;
vector<int> vecCombs;
vector<char> vecVisited;
vector<char> vecUnlinked;
int Best = 0x7FFFFFFF;
int RootNode = 0;

void PostOrder(int _Node)
{
    int Left = vecLinks[_Node][0];
    int Right = vecLinks[_Node][1];

    if (Left != -1)
    {
        PostOrder(Left);
        vecSums[_Node] += vecSums[Left];
    }
    if (Right != -1)
    {
        PostOrder(Right);
        vecSums[_Node] += vecSums[Right];
    }

    vecSums[_Node] += vecNums[_Node];
}

int Push_BFS(int _Node, vector<char>& _vecBFSVisited, queue<int>& _q)
{
    if (vecVisited[_Node] || _vecBFSVisited[_Node]) return 0;
    _q.push(_Node);
    _vecBFSVisited[_Node] = 1;
    return vecNums[_Node];
}

int FloodFill(int _Node)
{
    static vector<char> vecBFSVisited;
    vecBFSVisited.assign(vecNums.size(), 0);

    int TotalCnt = 0;

    queue<int> q;
    TotalCnt += Push_BFS(_Node, vecBFSVisited, q);

    while (!q.empty())
    {
        int Node = q.front();
        q.pop();

        int NextNode;
        if (vecParents[Node] != -1)
        {
            NextNode = vecParents[Node];
            TotalCnt += Push_BFS(NextNode, vecBFSVisited, q);
        }
        if (vecLinks[Node][0] != -1)
        {
            NextNode = vecLinks[Node][0];
            TotalCnt += Push_BFS(NextNode, vecBFSVisited, q);
        }
        if (vecLinks[Node][1] != -1)
        {
            NextNode = vecLinks[Node][1];
            TotalCnt += Push_BFS(NextNode, vecBFSVisited, q);
        }
    }


    return TotalCnt;
}

int CalcMaxGroup()
{
    int MaxCnt = 0;
    for (int i = 0; i < vecCombs.size(); ++i)
    {
        int Node = vecCombs[i];
        int Sum = FloodFill(Node);
        if (MaxCnt < Sum)
        {
            MaxCnt = Sum;
        }
    }

    return MaxCnt;
}

void BackTracking(int _Node, int _Remain)
{
    if (_Remain == 0)
    {
        int MaxCnt = CalcMaxGroup();
        if (Best > MaxCnt) Best = MaxCnt;
        
    }
    for (int i = 0; i < vecVisited.size(); ++i)
    {
        if (vecVisited[i]) continue;
        if (i == RootNode) continue;

        vecVisited[i] = 1;
        vecCombs.push_back(i);
        BackTracking(i, _Remain - 1);
        vecCombs.pop_back();
        vecVisited[i] = 0;
    }
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    return answer;
}

int main()
{
    int K = 3;
    vecNums = { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 };
    vecLinks = { {-1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 }, { 11, -1 }, { 7, 4 }, { -1, -1 }, { -1, -1 } };
    vecParents.assign(vecNums.size(), -1);
    vecSums.assign(vecNums.size(), 0);
    vecVisited.assign(vecNums.size(), 0);
    for (int i = 0; i < vecLinks.size(); ++i)
    {
        int Left = vecLinks[i][0];
        int Right = vecLinks[i][1];
        if (Left != -1) vecParents[Left] = i;
        if (Right != -1) vecParents[Right] = i;
    }
    for (int i = 0; i < vecParents.size(); ++i)
    {
        if (vecParents[i] == -1)
        {
            RootNode = i;
            break;
        }
    }

    PostOrder(RootNode);

    BackTracking(0, K - 1);

    cout << Best;


    return 0;
}