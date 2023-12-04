#include <iostream>
#include <vector>

using namespace std;


void backtrack(vector<bool>& used, int r, vector<string> current_chessboard, vector<vector<string>>& solutions, int n)
{
    if (r == n)
    {
        solutions.push_back(current_chessboard);
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (!used[col] && !used[n + (r - col) + n -1] && !used[n - 1 + 2*n + r + col])
            {
                current_chessboard[r][col] = 'Q';
                used[col] = used[n + (r - col) + n - 1] = used[n - 1 + 2*n + r + col] = true; 
                backtrack(used, r + 1, current_chessboard, solutions, n);

                current_chessboard[r][col] = '.';
                used[col] = used[n + (r - col) + n - 1] = used[n - 1 + 2*n + r + col] = false;
               
            }

        }
    }
}

void printSolution(vector<vector<string>>& solutions)
{
    if (solutions.size() == 0)
    {
        cout << "No Solution" << endl;
    }
    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "Solution: " << i + 1 << endl;
        for (int j = 0; j < solutions[i].size(); j++)
        {
            cout << solutions[i][j] << endl;
        }
        cout << "------------------" << endl;
    }
}

void sloveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<bool> used(n + 2*n -1 + 2*n -1, false);
    vector<string> chessboard(n, string(n, '.'));
    backtrack(used, 0, chessboard, solutions, n);
    printSolution(solutions);
}


int main()
{
    int n;
    cin >> n;
    sloveNQueens(n);
    
    return 0;
}
// Solution by Nicolas Abboud
