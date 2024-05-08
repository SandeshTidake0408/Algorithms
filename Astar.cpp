#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
            {
                cout << board[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int geth(vector<vector<int>> board)
{
    int h = 0;
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            if ((i * 3) + j + 1 != board[i][j]) /// calculate the misplaced tiles
            {
                h++;
            }
        }
    }
    return h;
}

bool validstate(vector<vector<int>> board)
{
    int n = board.size();
    vector<vector<int>> invalid;
    for (int i = 0; i < n; i++)
    {
        invalid.push_back(vector<int>(n, -1));
    }
    return invalid != board;

    // This function validstate checks whether the input board is valid or not.
    // A valid board is one that is not completely filled with a specific value (in this case, -1).
    // return board != vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
}

vector<vector<int>> move(vector<vector<int>> board, char direction)
{
    int p = -1, q = -1;
    int n = board.size();

    // Find the position of the empty cell
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 0)
            {
                p = i;
                q = j;
                break;
            }
        }
        if (p != -1 && q != -1)
        {
            break;
        }
    }

    // Define the move offsets based on the direction
    int dr[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
    int dc[] = {0, 0, -1, 1};
    char moves[] = {'U', 'D', 'L', 'R'};

    // Check if the move is valid and perform it if valid
    for (int i = 0; i < 4; ++i)
    {
        if (direction == moves[i])
        {
            int nr = p + dr[i];
            int nc = q + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n)
            {
                swap(board[p][q], board[nr][nc]);
                return board;
            }
            break;
        }
    }

    // If the direction is invalid, return the original board
    return board;
}

void play(vector<vector<int>> state1, vector<vector<int>> state2)
{
    print(state1);
    int h = geth(state1);
    if (h == 0)
    {
        return;
    }

    char moves[] = {'U', 'D', 'R', 'L'};
    int minIndex = -1;
    int minH = 999;

    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> newState = move(state1, moves[i]);
        if (validstate(newState))
        {
            int newH = geth(newState);
            if (newH < minH)
            {
                minH = newH;
                minIndex = i;
            }
        }
    }

    if (minIndex != -1)
    {
        state1 = move(state1, moves[minIndex]);
    }

    play(state1, state2);
}

class Game
{
private:
    vector<vector<int>> state1;
    vector<vector<int>> state2;

public:
    Game(const vector<vector<int>> &state1) : state1(state1)
    {
        int n = state1.size();
        state2 = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                state2[i][j] = (i * n) + j + 1;
            }
        }
        state2[n - 1][n - 1] = 0;
    }

    void printStates()
    {
        cout << "printing the states" << endl;
        print(state1);
        print(state2);
    }

    void solution()
    {
        play(state1, state2);
    }
};

int main()
{
    Game g({{0, 1, 2}, {4, 5, 3}, {7, 8, 6}});
    g.printStates();

    cout << "solution is" << endl;
    g.solution();
    return 0;
}
