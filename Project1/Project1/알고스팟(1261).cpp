// https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
vector<string> vecBoard;
vector<vector<char>> vecVisited;
vector<vector<int>> vecDP;

struct tNode
{
	pair<int, int> Dest;
	int Dist;

	tNode(pair<int, int> _Dest, int _Dist)
		: Dest(_Dest), Dist(_Dist)
	{
	}
};

struct tCmp
{
	bool operator()(const tNode& _A, const tNode& _B)
	{
		return _A.Dist > _B.Dist;
	}
};

bool IsValid(int _Row, int _Col)
{
	return (_Row >= 0 && _Row < N&& _Col >= 0 && _Col < M);
}

void Push_Dijkstra(priority_queue<tNode, vector<tNode>, tCmp>& _pq, tNode _Node)
{

}

void Dijkstra()
{
	priority_queue<tNode, vector<tNode>, tCmp> pq;
	vecDP[0][0] = 0;
	pq.push(tNode(make_pair(0, 0), 0));
	
	while (!pq.empty())
	{
		tNode Node = pq.top();
		pq.pop();
		
		pair<int, int> Pos = Node.Dest;
		vecVisited[Pos.first][Pos.second] = 1;
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Pos.first + dy[i], Pos.second + dx[i]);
			if (!IsValid(Next.first, Next.second)) continue;
			if (vecVisited[Next.first][Next.second]) continue;
			int Dist = vecDP[Pos.first][Pos.second] + vecBoard[Next.first][Next.second] - '0';
			if (Dist < vecDP[Next.first][Next.second])
			{
				vecDP[Next.first][Next.second] = Dist;
				pq.push(tNode(Next, Dist));
			}
		}
	}
}



int main()
{
	cin >> M >> N;
	vecBoard.assign(N, "");
	vecVisited.assign(N, vector<char>(M, 0));
	vecDP.assign(N, vector<int>(M, 0x7FFFFFFF - 1));
	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
	}

	Dijkstra();

	cout << vecDP[N - 1][M - 1];

	return 0;
}