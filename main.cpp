#include <iostream>
#include <bitset>
#include <iomanip>
#include <fstream>
#include "CurrentTime.h"
#include "LinkedList.h"
#include "TestFunctions.h"
#include "Sorting.h"
#include "Sudoku.h"
#include "dungeonBFS.h"



int main()
{
    currentTime();

    int input[5] = {2,35,7,4,3};

    std::ofstream file("output.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for(int i : input)
    {
        file << i <<std::endl;
    }

    file.close();

    LinkedList list;

    try{list.remove();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    list.add(3);
    try{list.remove();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{list.removeFirst();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    list.add(15);
    list.add(6);
    list.add(1);

    try{list.removeFirst();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    list.add(62);
    list.add(5);
    list.add(66);

    std::cout << "\nList:\n" << list.toString() << std::endl;

    int arr[5] = {1,2,3,5,8};

    std::cout << "Found index: " << binarySearch(arr,5, 3) <<
        "\nNot found: " << binarySearch(arr, 5, 4) << std::endl;


    int dataSet[7] = {2,9,5,4,8,1,6};

    //TODO: FIx insertion sort
    insertion(dataSet, 7);

    printArray(dataSet,7);

    int puzzle[9][9] = {
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

    int zeros[81][2];

    const int cells = freeCells(puzzle, zeros);

    printPuzzle(puzzle);
    std::cout << "Free cells : " << cells <<"\n";


    initializeQueues();

    return 0;
}
