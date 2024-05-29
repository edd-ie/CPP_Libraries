//
// Created by _edd.ie_ on 29/05/2024.
//

#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

inline int binarySearch(const int arr[], const int value)
{
    constexpr int arrSize = sizeof(arr);
    int x = 0;
    int y = arrSize-1;
    int found = -1;

    while(found<0 && x<=y)
    {
        int middle = (y + x) / 2;
        // std::cout << "current: " << arr[middle] << std::endl;

        if(arr[middle] == value) found = middle;
        else if(arr[middle] < value) y = middle-1;
        else x = middle+1;
    }

    return found;
}

#endif //TESTFUNCTIONS_H
