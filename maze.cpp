#include <iostream>
using namespace std;

const int N = 5;

int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1}
};

int solution[N][N] = {0};

bool solveMaze(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (x >= N || y >= N || maze[x][y] == 0)
        return false;

    if (solution[x][y] == 1)
        return false;

    solution[x][y] = 1;

    if (solveMaze(x + 1, y) || solveMaze(x, y + 1))
        return true;

    solution[x][y] = 0;
    return false;
}

int main() {
    if (solveMaze(0, 0)) {
        cout << "Maze Solution:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists.";
    }

    return 0;
}