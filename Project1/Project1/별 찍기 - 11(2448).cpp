// https://www.acmicpc.net/problem/2448
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> vecBoard;

char arrTriangle[3][6] = {
	"  *  ",
	" * * ",
	"*****",
};

void Draw(int _N, int _X, int _Y)
{
	if (_N == 3)
	{
		int Left = _X;
		int Top = _Y - 2;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				vecBoard[Top + i][Left + j] = arrTriangle[i][j];
			}
		}
		return;
	}
	Draw(_N / 2, _X, _Y);
	Draw(_N / 2, _X + _N / 2, _Y - _N / 2);
	Draw(_N / 2, _X + _N, _Y);
}
// N = 12
//           *                        
//          * *                       
//         *****                      
//        *     *                     
//       * *   * *                    
//      ***** *****                   
//     *           *                  
//    * *         * *                 
//   *****       *****                
//  *     *     *     *               
// * *   * *   * *   * *              
//***** ***** ***** *****
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vecBoard.assign(N, vector<char>(2 * N - 1, ' '));

	Draw(N, 0, N - 1);

	for (int i = 0; i < vecBoard.size(); ++i)
	{
		for (int j = 0; j < vecBoard[i].size(); ++j)
		{
			cout << vecBoard[i][j];
		}
		cout << '\n';
	}
}