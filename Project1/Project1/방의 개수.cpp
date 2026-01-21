//https://school.programmers.co.kr/learn/courses/30/lessons/49190
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

# define MAX_COORD 400005
# define DIR_END 8

int dx[DIR_END] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[DIR_END] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct PairHash
{
    size_t operator()(const pair<int, int> _Pos) const
    {
        return (long long)_Pos.first + (long long)MAX_COORD * _Pos.second;
    }
};

int solution(vector<int> arrows)
{
    int answer = 0;
    unordered_map<pair<int, int>, int, PairHash> um;
    int PosIdx = 0;
    int CurPosIdx = 0;
    int NextPosIdx = 0;
    pair<int, int> CurPos = make_pair(0, 0);
    pair<int, int> NextPos;
    vector<int> vecLinkedBit;
    um.insert(make_pair(CurPos, PosIdx));
    vecLinkedBit.push_back(0);


    for (auto Dir : arrows)
    {
        int RevDir = (Dir + 4) % DIR_END;
        int Bit_Dir = (1 << Dir);
        int Bit_Rev = (1 << RevDir);

        for (int i = 0; i < 2; ++i)
        {
            NextPos = make_pair(CurPos.first + dx[Dir], CurPos.second + dy[Dir]);
            // 새로운 정점 발견시
            unordered_map<pair<int, int>, int, PairHash>::iterator iter = um.find(NextPos);
            if (iter == um.end())
            {
                um.insert(make_pair(NextPos, ++PosIdx));
                vecLinkedBit.push_back((0));
                NextPosIdx = PosIdx;
            }
            // 지나간 적 있는 정점 방문시
            else
            {
                // 다음 정점
                NextPosIdx = iter->second;

                // 이미 만들어진 간선을 지나지 않는 경우 방 추가 O
                if (!((vecLinkedBit[CurPosIdx] & Bit_Dir)
                    && vecLinkedBit[NextPosIdx] & Bit_Rev))
                {
                    ++answer;
                }
            }

            // 현재 정점과 다음 정점 연결
            vecLinkedBit[CurPosIdx] |= Bit_Dir;
            vecLinkedBit[NextPosIdx] |= Bit_Rev;

            CurPos = NextPos;
            CurPosIdx = NextPosIdx;
        }
    }

    
    return answer;
}

int main()
{
    cout << solution({6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0});
    return 0;
}