#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x, y, g, h, f;
};

struct CompareNode
{
    bool operator()(Node const &n1, Node const &n2)
    {
        // Nodes with a smaller f value are higher priority
        return n1.f > n2.f;
    }
};

bool isValid(int x, int y, int rows, int cols)
{
    return (x >= 0 && y >= 0 && x < rows && y < cols);
}

vector<Node> getNeighbors(Node &node, int rows, int cols)
{
    vector<Node> neighbors;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i)
    {
        int newX = node.x + dx[i];
        int newY = node.y + dy[i];

        if (isValid(newX, newY, rows, cols))
        {
            neighbors.push_back(Node{newX, newY, 0, 0, 0});
        }
    }

    return neighbors;
}

Node aStar(vector<vector<int>> &grid, Node &start, Node &end)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> closedList(rows, vector<bool>(cols, false));
    priority_queue<Node, vector<Node>, CompareNode> openList;
    start.f = 0;
    start.g = 0;
    start.h = 0;
    openList.push(start);

    while (!openList.empty())
    {
        Node node = openList.top();
        openList.pop();

        closedList[node.x][node.y] = true;

        vector<Node> neighbors = getNeighbors(node, rows, cols);
        for (Node &neighbor : neighbors)
        {
            if (neighbor.x == end.x && neighbor.y == end.y)
            {
                neighbor.g = node.g + 1;
                neighbor.h = abs(neighbor.x - end.x) + abs(neighbor.y - end.y);
                neighbor.f = neighbor.g + neighbor.h;
                return neighbor;
            }
            else if (!closedList[neighbor.x][neighbor.y] && grid[neighbor.x][neighbor.y] == 0)
            {
                neighbor.g = node.g + 1;
                neighbor.h = abs(neighbor.x - end.x) + abs(neighbor.y - end.y);
                neighbor.f = neighbor.g + neighbor.h;
                openList.push(neighbor);
            }
        }
    }

    return Node{-1, -1, -1, -1, -1}; // Return an invalid node if no path is found
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};

    Node start = {0, 0, 0, 0, 0};
    Node end = {4, 4, 0, 0, 0};

    Node result = aStar(grid, start, end);

    if (result.x != -1)
    {
        cout << "Path found!" << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void print(vector<vector<int>> board)
// {
//     int n = board.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (board[i][j] != 0)
//             {
//                 cout << board[i][j] << " ";
//             }
//             else
//             {
//                 cout << "  ";
//             }
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

// int geth(vector<vector<int>> board)
// {
//     int h = 0;
//     int n = board.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (board[i][j] == 0)
//             {
//                 continue;
//             }
//             if ((i * 3) + j + 1 != board[i][j]) /// calculate the misplaced tiles
//             {
//                 h++;
//             }
//         }
//     }
//     return h;
// }

// bool validstate(vector<vector<int>> board)
// {
//     int n = board.size();
//     vector<vector<int>> invalid;
//     for (int i = 0; i < n; i++)
//     {
//         invalid.push_back(vector<int>(n, -1));
//     }
//     return invalid != board;

//     // This function validstate checks whether the input board is valid or not.
//     // A valid board is one that is not completely filled with a specific value (in this case, -1).
//     // return board != vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
// }

// vector<vector<int>> move(vector<vector<int>> board, char direction)
// {
//     int p = -1, q = -1;
//     int n = board.size();

//     // Find the position of the empty cell
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             if (board[i][j] == 0)
//             {
//                 p = i;
//                 q = j;
//                 break;
//             }
//         }
//         if (p != -1 && q != -1)
//         {
//             break;
//         }
//     }

//     // Define the move offsets based on the direction
//     int dr[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
//     int dc[] = {0, 0, -1, 1};
//     char moves[] = {'U', 'D', 'L', 'R'};

//     // Check if the move is valid and perform it if valid
//     for (int i = 0; i < 4; ++i)
//     {
//         if (direction == moves[i])
//         {
//             int nr = p + dr[i];
//             int nc = q + dc[i];
//             if (nr >= 0 && nr < n && nc >= 0 && nc < n)
//             {
//                 swap(board[p][q], board[nr][nc]);
//                 return board;
//             }
//             break;
//         }
//     }

//     // If the direction is invalid, return the original board
//     return board;
// }

// void play(vector<vector<int>> state1, vector<vector<int>> state2)
// {
//     print(state1);
//     int h = geth(state1);
//     if (h == 0)
//     {
//         return;
//     }

//     char moves[] = {'U', 'D', 'R', 'L'};
//     int minIndex = -1;
//     int minH = 999;

//     for (int i = 0; i < 4; i++)
//     {
//         vector<vector<int>> newState = move(state1, moves[i]);
//         if (validstate(newState))
//         {
//             int newH = geth(newState);
//             if (newH < minH)
//             {
//                 minH = newH;
//                 minIndex = i;
//             }
//         }
//     }

//     if (minIndex != -1)
//     {
//         state1 = move(state1, moves[minIndex]);
//     }

//     play(state1, state2);
// }

// class Game
// {
// private:
//     vector<vector<int>> state1;
//     vector<vector<int>> state2;

// public:
//     Game(const vector<vector<int>> &state1) : state1(state1)
//     {
//         int n = state1.size();
//         state2 = vector<vector<int>>(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 state2[i][j] = (i * n) + j + 1;
//             }
//         }
//         state2[n - 1][n - 1] = 0;
//     }

//     void printStates()
//     {
//         cout << "printing the states" << endl;
//         print(state1);
//         print(state2);
//     }

//     void solution()
//     {
//         play(state1, state2);
//     }
// };

// int main()
// {
//     Game g({{0, 1, 2}, {4, 5, 3}, {7, 8, 6}});
//     g.printStates();

//     cout << "solution is" << endl;
//     g.solution();
//     return 0;
// }
