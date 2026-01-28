// https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, unordered_set<string>> um;
    for (const auto& clothInfo : clothes)
    {
        string Type = clothInfo[1];
        string cloth = clothInfo[0];
        if (um.find(Type) == um.end())
        {
            um.insert(make_pair(Type, unordered_set<string>()));
        }
        if (um[Type].find(cloth) == um[Type].end())
        {
            um[Type].insert(cloth);
        }
    }

    
    int answer = (um.size() > 0) ? (1) : (0);
    for (auto pair : um)
    {
        answer *= (pair.second.size() + 1);
    }

    --answer;

    return answer;
}

#include <iostream>

int main()
{
    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}} );
    return 0;
}