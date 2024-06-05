//
// Created by _edd.ie_ on 31/05/2024.
//

#ifndef SUDOKU_H
#define SUDOKU_H

// Printing the Sudoku grid

inline int freeCells(int puzzle[9][9] , int freeCells[81][2])
{
    int cells = 0;

    for (int i = 0; i<9; i++)
    {
        for (int x = 0; x<9; x++)
        {
            if(puzzle[i][x] == 0)
            {
                freeCells[cells][0] = i;
                freeCells[cells][1] = x;
                cells++;
            }
        }
    }

    return cells;
}

inline void printPuzzle(int puzzle[][9], int size = 9)
{
    std::cout << "-----------------\n";
    for (int i = 0; i<size; i++) {

        for (const int val : puzzle[i]) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
	
	
    std::cout << "--------------\n";
}

#endif //SUDOKU_H
