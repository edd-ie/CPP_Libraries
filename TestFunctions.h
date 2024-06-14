//
// Created by _edd.ie_ on 29/05/2024.
//

#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

inline int binarySearch(const int arr[], int arraysize, const int value)
{
    int x = 0;
    int y = arraysize-1;
    int found = -1;

    while(found<0 && x<=y)
    {
        int middle = (y + x) / 2;
        // std::cout << "\ncurrent: " << arr[middle] <<"\t"<< middle <<std::endl;

        if(arr[middle] == value) found = middle;
        else if(arr[middle] > value) y = middle-1;
        else x = middle+1;
    }

    return found;
}


inline void printArray(int arraySet[], int size)
{
    std::cout << "\nThe array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arraySet[i] << "\t";
    }
    std::cout << "\n\n";
}

template <typename T, size_t rows, size_t cols>
void print2DArray(const T (&arraySet)[rows][cols])
{
    std::cout << "\n\n\n-----------------\n";
    for (int i = 0; i<rows; i++) {

        for (const T val : arraySet[i]) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }


    std::cout << "--------------\n";
}

#endif //TESTFUNCTIONS_H
