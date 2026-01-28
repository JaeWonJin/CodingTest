// https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct tGenreInfo
{
    int GenreID;
    int PlayCnt;
    vector<int> vecMusics;
};

struct tMusicInfo
{
    int GenrePlayCnt;
    int MusicPlayCnt;
    int MusicID;
    int GenreID;
};

bool CmpFunc(const tMusicInfo& _A, const tMusicInfo& _B)
{
    if (_A.GenrePlayCnt != _B.GenrePlayCnt)
        return _A.GenrePlayCnt > _B.GenrePlayCnt;
    if (_A.MusicPlayCnt != _B.MusicPlayCnt)
        return _A.MusicPlayCnt > _B.MusicPlayCnt;
    return _A.MusicID < _B.MusicID;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int Idx = 0;

    unordered_map<string, tGenreInfo> um;
    for (int i = 0; i < genres.size(); ++i)
    {
        string genre = genres[i];
        int play = plays[i];
        if (um.find(genre) == um.end())
        {
            tGenreInfo Info;
            Info.GenreID = Idx++;
            Info.PlayCnt = play;
            Info.vecMusics.push_back(i);
            um.insert(make_pair(genre, Info));
        }
        else
        {
            um[genre].PlayCnt += play;
            um[genre].vecMusics.push_back(i);
        }
    }

    vector<tMusicInfo> vecMusics;
    for (const auto& Pair : um)
    {
        const tGenreInfo& GenreInfo = Pair.second;
        for (const auto& MusicID : GenreInfo.vecMusics)
        {
            tMusicInfo Info;
            Info.GenrePlayCnt = GenreInfo.PlayCnt;
            Info.MusicPlayCnt = plays[MusicID];
            Info.MusicID = MusicID;
            Info.GenreID = GenreInfo.GenreID;
            vecMusics.push_back(Info);
        }
    }
    sort(vecMusics.begin(), vecMusics.end(), CmpFunc);

    vector<int> vecGenreSampledCnts;
    vecGenreSampledCnts.assign(Idx, 0);
    for (int i = 0; i < vecMusics.size(); ++i)
    {
        const tMusicInfo& Info = vecMusics[i];
        if (vecGenreSampledCnts[Info.GenreID] >= 2) continue;
        vecGenreSampledCnts[Info.GenreID] += 1;
        answer.push_back(Info.MusicID);
    }

    return answer;
}

#include <iostream>
int main()
{
    solution({"classic", "pop", "classic", "classic", "pop"}, { 500, 600, 150, 800, 2500 });
    return 0;
}