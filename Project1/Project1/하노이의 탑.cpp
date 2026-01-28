// https://school.programmers.co.kr/learn/courses/30/lessons/12946

#include <string>
#include <vector>

using namespace std;

void Hanoi(const int _PlateNum, int _PlateSize, int _StartCol, int _DestCol, vector<vector<int>>& _vecAns)
{
    int AnotherCol = 6 - _StartCol - _DestCol;
    if (_PlateSize == 1)
    {
        _vecAns.push_back({ _StartCol, _DestCol });
        return;
    }
    Hanoi(_PlateNum, _PlateSize - 1, _StartCol, AnotherCol, _vecAns);
    _vecAns.push_back({ _StartCol, _DestCol });
    Hanoi(_PlateNum, _PlateSize - 1, AnotherCol, _DestCol, _vecAns);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(n, n, 1, 3, answer);
    return answer;
}