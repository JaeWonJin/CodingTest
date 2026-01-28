#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> um;
    for (const auto& Name : completion)
    {
        auto iter = um.find(Name);
        if (iter == um.end())
        {
            um.insert(make_pair(Name, 1));
        }
        else
        {
            iter->second = iter->second + 1;
        }
    }
    for (const auto& Name : participant)
    {
        auto iter = um.find(Name);
        if (iter == um.end())
        {
            answer = Name;
        }
        else
        {
            iter->second = iter->second - 1;
            if (iter->second == 0)
            {
                um.erase(Name);
            }
        }
    }

    return answer;
}