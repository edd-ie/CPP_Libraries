//
// Created by _edd.ie_ on 13/06/2024.
//

#ifndef DUNGEONBFS_H
#define DUNGEONBFS_H
#include <queue>

inline char grid[][7] = {
    {'S', '.', '.', '#', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.'},
    {'.', '.', '#', '#', '.', '.', '.'},
    {'#', '.', '#', 'S', '.', '#', '.'}
};





inline std::queue<int> row;
inline std::queue<int> col;

// Function to initialize the queues
inline void initializeQueues() {
    row.push(0);
    col.push(0);
}






#endif //DUNGEONBFS_H
