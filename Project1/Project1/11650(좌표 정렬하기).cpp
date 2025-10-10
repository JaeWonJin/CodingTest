// https://www.acmicpc.net/problem/11650

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> _A, const pair<int, int> _B)
{
    if (_A.first < _B.first) return true;
    else if (_A.first == _B.first)
    {
        return _A.second < _B.second;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), &cmp);

    for (auto point : arr)
        cout << point.first << " " << point.second << '\n';
    return 0;
}