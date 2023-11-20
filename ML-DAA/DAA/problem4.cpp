#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> board)
{
    int N = board.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        printf("\n");
    }
}

bool checkSafe(vector<vector<int>> board, int n, int r, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (board[r][i])
            return false;

    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = r, j = c; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool place(vector<vector<int>> &board, int n, int col)
{
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (checkSafe(board, n, i, col))
        {
            board[i][col] = 1;
            if (place(board, n, col + 1))
            {
                cout << "\nValid configuration found:\n";
                printSolution(board);
                return true;
            }
            board[i][col] = 0;
        }
    }
    cout << "\nInvalid placement of queen: \n";
    printSolution(board);
    return false;
}

int main()
{
    int q = 4;

    vector<vector<int>> board(q, vector<int>(q, 0));
    // for(int )

    place(board, q, 0);

    return 0;
}