//
// Created by _edd.ie_ on 13/06/2024.
//

#ifndef DUNGEONBFS_H
#define DUNGEONBFS_H
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

inline char grid[][7] = {
    {'S', '.', '.', '#', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.'},
    {'.', '.', '#', '#', '.', '.', '.'},
    {'#', '.', '#', 'E', '.', '#', '.'}
};


// struct Position {
//
//     class Node
//     {
//     public:
//         int row;
//         int col;
//         Node* next;
//
//         Node (int r, int c) : row(r), col(c), next(nullptr) {}
//     };
//
//     Node* head{};
//     Node* tail;
//     int length;
//
//     Position (int r, int c)
//     {
//         head = new Node(r,c);
//         tail = head;
//         length = 1;
//     }
//
//
//     void addNode(const int r, const int c)
//     {
//         Node* curr = new Node(r,c);
//
//         tail->next = curr;
//         tail = curr;
//         length++;
//     }
//
// };

class Node
{
public:
    int row;
    int col;
    Node* prev;

    Node (int r, int c) : row(r), col(c), prev(nullptr) {}

    void setPrev (Node* node)
    {
        prev = node;
    }

    Node getPrev()
    {
        return *prev;
    }

    void pos(int* arr[][2], int pos) const
    {
        (*arr[pos][0]) = row;
        (*arr[pos][1]) = col;
    }
};



inline void bfs(char grid[5][7])
{
    std::queue<Node> cells;
    cells.emplace(0,0);

    Node* previous;
    Node current = cells.front();
    current.prev = nullptr;

    int r, c;
    int count = 0;

    while(!cells.empty())
    {
        r = cells.front().row;
        c = cells.front().col;


        if(grid[r][c] == 'E') break;


        if(r+1 < 5 && grid[r+1][c] != '#' && grid[r+1][c] != '0')
        {
            cells.emplace(r+1,c);
            cells.back().prev = &current;
        }
        if(r-1 > -1 && grid[r-1][c] != '#' && grid[r-1][c] != '0')
        {
            cells.emplace(r-1, c);
            cells.back().prev = &current;
        }
        if(c+1 < 7 && grid[r][c+1] != '#' && grid[r][c+1] != '0')
        {
            cells.emplace(r, c+1);
            cells.back().prev = &current;
        }
        if(c-1 > -1 && grid[r][c-1] != '0' && grid[r][c-1] != '#')
        {
            cells.emplace(r, c-1);
            cells.back().prev = &current;
        }

        grid[r][c] = '0';
        count++;
        cells.pop();
        current = cells.front();
    }

    std::vector<std::vector<int>> pos (10);

    int i =0;
    int stop = false;

    Node* p = &current;
    while (!stop)
    {
        pos[i] ={p->row, p->col};
        std::cout << pos[i][0] <<", " << pos[i][1] << '\n' ;
        if(p->prev == nullptr) stop=true;
        p = p->prev;
    }
}





#endif //DUNGEONBFS_H
