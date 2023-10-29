#include <iostream>
#include <vector>
using namespace std;
const int N = 9; // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place 'num' at cell (row, col)
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row and column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[boxRowStart + i][boxColStart + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Sudoku solver using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            return true; // If it leads to a solution
                        }
                        grid[row][col] = 0; // If it doesn't lead to a solution, backtrack
                    }
                }
                return false; // If no number can be placed, backtrack further
            }
        }
    }
    return true; // All cells are filled
}

int main() 
{
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solved:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
