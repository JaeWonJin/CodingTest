#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> us;
    for (auto num : nums)
    {
        us.insert(num);
    }

    answer = (us.size() > nums.size() / 2) ? (nums.size() / 2) : (us.size());

    return answer;
}