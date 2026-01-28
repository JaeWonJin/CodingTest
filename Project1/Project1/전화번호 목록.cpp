#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool CmpFunc(const string& _A, const string& _B)
{
    return _A.size() < _B.size();
}

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    unordered_set<string> us;
    sort(phone_book.begin(), phone_book.end(), CmpFunc);
    int MinLeng = phone_book.front().size();
    int MaxLeng = phone_book.back().size();
    for (const auto& phone : phone_book)
    {
        for (int i = MinLeng; i <= MaxLeng && i <= phone.size(); ++i)
        {
            string subStr = phone.substr(0, i);
            auto iter = us.find(subStr);
            if (iter == us.end())
            {
                if(i == phone.size()) us.insert(subStr);
            }
            else
            {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

#include <iostream>
int main()
{
    cout << solution({ "119", "97674223", "1195524421" });
    return 0;
}