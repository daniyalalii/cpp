## Question 01:
### You are required to design a C++ program that stores and analyzes daily weather records using only structures. Define a structure Weather that stores the day number, temperature (°C), humidity (%), and rainfall (mm). The program should:
1. Input weather data for 7 days.
2. Calculate and display the average temperature, average humidity, and total rainfall over
the week.
3. Find and display the day with the highest temperature and the day with the maximum
rainfall.
4. Print all 7 records in a neat tabular format.
---
## Question 03:
### You are required to design a C++ program that solves a standard 9×9 Sudoku puzzle using only structures, raw arrays, recursion, and pointers without relying on STL containers; the Sudoku grid must be stored in a 2D array of Cell structures, where each cell keeps track of its row and column position, its current value (0 if empty), a boolean flag indicating whether the value is fixed (i.e., part of the original puzzle and cannot be changed), and a pointer to the previous cell filled during recursion to support manual backtracking; your recursive solver must start at the first cell and attempt to fill all empty positions with digits 1–9, checking validity at each step according to Sudoku rules (no duplicates allowed in any row, column, or 3×3 subgrid), and whenever no valid value can be placed, the recursion must backtrack by following the prev pointer and resetting the cell to 0; the program must ultimately print the completed Sudoku if solvable, otherwise report that no solution exists, and in either case, it must also output statistics including the total number of recursive calls made, the maximum recursion depth reached.