#include <iostream>
using namespace std;

long long recursiveCalls = 0;
int maxDepth = 0;

struct Cell
{
    int row;
    int column;
    int value;
    bool fixed;
    Cell *prev;
};

bool solveSudoku(Cell grid[9][9], int row, int column, Cell *prev, int depth);

bool checkRow(Cell grid[9][9], int row, int column, int digit, int j = 0)
{
    if (j == 9)
    {
        return true; // reached end row
    }
    if (grid[row][j].value == digit)
    {
        return false;
    }
    return checkRow(grid, row, column, digit, j + 1);
}

bool checkColumn(Cell grid[9][9], int row, int column, int digit, int i = 0)
{
    if (i == 9)
    { // reached column end
        return true;
    }
    if (grid[i][column].value == digit)
    {
        return false;
    }
    return checkColumn(grid, row, column, digit, i + 1);
}

bool checkSubGrid(Cell grid[9][9], int sRow, int sCol, int digit, int i = 0, int j = 0)
{
    if (i == 3)
        return true;

    if (j == 3)
        return checkSubGrid(grid, sRow, sCol, digit, i + 1, 0);

    if (grid[sRow + i][sCol + j].value == digit)
        return false;

    return checkSubGrid(grid, sRow, sCol, digit, i, j + 1);
}

bool isSafe(Cell grid[9][9], int row, int column, int digit)
{
    int sRow = (row / 3) * 3;
    int sCol = (column / 3) * 3;

    return checkRow(grid, row, column, digit) && checkColumn(grid, row, column, digit) && checkSubGrid(grid, sRow, sCol, digit);
}

bool checkDigit(Cell grid[9][9], int row, int col, int digit, Cell *prev, int depth)
{
    if (digit > 9)
        return false;

    if (isSafe(grid, row, col, digit))
    {
        grid[row][col].value = digit;
        grid[row][col].prev = prev;

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow++;
            nextCol = 0;
        }

        if (solveSudoku(grid, nextRow, nextCol, &grid[row][col], depth + 1))
            return true;
        // backtracking
        grid[row][col].value = 0;
    }

    return checkDigit(grid, row, col, digit + 1, prev, depth);
}

bool solveSudoku(Cell grid[9][9], int row, int column, Cell *prev, int depth)
{
    recursiveCalls++;
    maxDepth = max(maxDepth, depth);

    if (row == 9) // all row checked
    {
        return true;
    }

    int nextRow = row;
    int nextColumn = column + 1;
    if (nextColumn == 9)
    {
        nextRow++;
        nextColumn = 0;
    }
    if (grid[row][column].fixed)
    {
        return solveSudoku(grid, nextRow, nextColumn, &grid[row][column], depth + 1);
    }

    return checkDigit(grid, row, column, 1, prev, depth);
}

void printRow(Cell grid[9][9], int row, int column = 0)
{
    if (column == 9)
    {
        cout << endl;
        return;
    }
    cout << grid[row][column].value << " ";
    printRow(grid, row, column + 1);
}

void printGrid(Cell grid[9][9], int row = 0)
{

    if (row == 9)
        return;

    printRow(grid, row);
    printGrid(grid, row + 1);
}

int main()
{
    Cell grid[9][9];

    int puzzle[9][9] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},

        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},

        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            grid[i][j].row = i;
            grid[i][j].column = j;
            grid[i][j].value = puzzle[i][j];
            grid[i][j].fixed = (puzzle[i][j] != 0);
            grid[i][j].prev = nullptr;
        }
    }
    cout << string(25, '-') << endl;
    cout << "Sudoko before solving: " << endl;
    printGrid(grid);
    cout << string(25, '-') << endl;

    if (solveSudoku(grid, 0, 0, nullptr, 0))
    {
        cout << string(25, '-') << endl;
        cout << "Suduko is solved" << endl;
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    cout << string(25, '-') << endl;
    cout << "Recursive calls: " << recursiveCalls << endl;
    cout << "Max recursion depth: " << maxDepth << endl;
    return 0;
}