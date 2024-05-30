//
// Created by _edd.ie_ on 30/05/2024.
//

#ifndef SORTING_H
#define SORTING_H

inline void selection(int arrayData[], int size)
{
    std::cout << "\nSelection sort:\n";
    for (int x = 0; x < size; x++)
    {
        std::cout << arrayData[x] << "->";
        int smallest = arrayData[x];
        int index = x;
        for(int y = x+1; y < size; y++)
        {
            if(arrayData[y] < smallest)
            {
                smallest = arrayData[y];
                index = y;
            }
        }

        if(index > x){
            arrayData[index] = arrayData[x];
            arrayData[x] = smallest;
        }

        std::cout << arrayData[x] << "\t";
    }
    std::cout << "\n";
}

inline void insertion(int array[], const int arraySize)
{
    std::cout << "\nInsertion sort:\n";
    for(int i = 1; i < arraySize-1; i++)
    {

        if(array[i+1] < array[i])
        {
            std::cout << array[i+1] << "->";
            bool inserted = false;
            int value = array[i+1];
            for (int y = i; y > -1 && !inserted; y--)
            {
                if(value <= array[y])
                {
                    array[y+1] = array[y];
                }
                else
                {
                    array[y] = value;
                    inserted = true;
                }
                if(y==0 && !inserted)
                {
                    array[y] = value;
                    inserted = true;
                }
            }
            std::cout << array[i] << "\t";
        }


    }
}

#endif //SORTING_H
