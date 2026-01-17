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
vector<vector<int>> vecDP;

bool IsValid(int _Row, int _Col)
{
	return (_Row >= 0 && _Row < N&& _Col >= 0 && _Col < M);
}

/*
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
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Pos.first + dy[i], Pos.second + dx[i]);
			if (!IsValid(Next.first, Next.second)) continue;
			int Dist = vecDP[Pos.first][Pos.second] + vecBoard[Next.first][Next.second] - '0';
			if (Dist < vecDP[Next.first][Next.second])
			{
				vecDP[Next.first][Next.second] = Dist;
				pq.push(tNode(Next, Dist));
			}
		}
	}
}*/

void Zero_One_BFS()
{
	deque<pair<int, int>> dq;
	vecDP[0][0] = 0;
	dq.push_front(make_pair(0, 0));

	while (!dq.empty())
	{
		pair<int, int> Pos = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Pos.first + dy[i], Pos.second + dx[i]);
			if (!IsValid(Next.first, Next.second)) continue;

			int Zero_One = vecBoard[Next.first][Next.second] - '0';
			int Dist = vecDP[Pos.first][Pos.second] + Zero_One;
			if (Dist < vecDP[Next.first][Next.second])
			{
				vecDP[Next.first][Next.second] = Dist;
				if (Zero_One == 0) dq.push_front(Next);
				else dq.push_back(Next);
			}
		}
	}
}



int main()
{
	cin >> M >> N;
	vecBoard.assign(N, "");
	vecDP.assign(N, vector<int>(M, 0x7FFFFFFF - 1));
	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
	}

	//Dijkstra();
	Zero_One_BFS();

	cout << vecDP[N - 1][M - 1];

	return 0;
}