//
// Created by _edd.ie_ on 31/05/2024.
//

#ifndef SUDOKU_H
#define SUDOKU_H

// Printing the Sudoku grid

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
