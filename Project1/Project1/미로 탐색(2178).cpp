//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct tNode
{
	tNode* Parent;
	pair<int, int> Point;
	int Length;

	tNode(int _Row, int _Col)
		: Parent(nullptr)
		, Point(_Row, _Col)
		, Length(0)
	{
	}
	~tNode()
	{

	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int Best = 10000;
vector<string> vecBoard;
vector<vector<bool>> vecVisited;
queue<tNode*> queueBFS;
vector<tNode*> vecAllNodes;

bool IsPointValid(const pair<int, int>& _Point)
{
	if (_Point.first >= 0 && _Point.first < N
		&& _Point.second >= 0 && _Point.second < M)
	{
		return true;
	}
	return false;
}

/*
void PushNode_DFS(const pair<int, int>& _Point)
{
	vecVisited[_Point.first][_Point.second] = true;
	vecOrders.push_back(_Point);
	if (_Point.first == N - 1 && _Point.second == M - 1)
	{
		Best = min((int)vecOrders.size(), Best);
	}
}

void PopNode_DFS()
{
	pair<int, int> Point = vecOrders.back();
	vecOrders.pop_back();
	vecVisited[Point.first][Point.second] = false;
}

void DFS(const pair<int, int>& _Point)
{
	PushNode_DFS(_Point);

	for (int i = 0; i < 4; ++i)
	{
		pair<int, int> Next = make_pair(_Point.first + dx[i], _Point.second + dy[i]);
		if (!IsPointValid(Next)) continue;
		if (vecVisited[Next.first][Next.second]) continue;
		if (vecBoard[Next.first][Next.second] == '0') continue;

		DFS(Next);
	}

	PopNode_DFS();
}*/

void PushNode_BFS(tNode* _Node, tNode* _Parent)
{
	_Node->Parent = _Parent;
	if (_Parent) _Node->Length = _Parent->Length + 1;
	else _Node->Length = 1;
	queueBFS.push(_Node);
	vecAllNodes.push_back(_Node);
	vecVisited[_Node->Point.first][_Node->Point.second] = true;
	if (_Node->Point.first == N - 1 && _Node->Point.second == M - 1)
	{
		Best = min(_Node->Length, Best);
	}
}

void BFS(tNode* _Start)
{
	PushNode_BFS(_Start, nullptr);

	while (!queueBFS.empty())
	{
		tNode* Node = queueBFS.front();
		queueBFS.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> Next = make_pair(Node->Point.first + dx[i], Node->Point.second + dy[i]);
			if (!IsPointValid(Next)) continue;
			if (vecVisited[Next.first][Next.second]) continue;
			if (vecBoard[Next.first][Next.second] == '0') continue;

			tNode* NextNode = new tNode(Next.first, Next.second);
			PushNode_BFS(NextNode, Node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vecBoard.resize(N);
	vecVisited.assign(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
	{
		cin >> vecBoard[i];
	}

	BFS(new tNode(0, 0));

	for (tNode* Node : vecAllNodes)
		delete Node;

	cout << Best;
}