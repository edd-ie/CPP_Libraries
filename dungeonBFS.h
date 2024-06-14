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
    {'#', '.', '#', 'E', '.', '#', '.'}
};



inline void bfs(char grid[5][7])
{
    std::queue<int> row;
    std::queue<int> col;
    row.push(0);
    col.push(0);

    int rowDirection[4] = {-1, 1, 0, 0};
    int colDirection[4] = {0, 0, 1, -1};
    int rowCheck, colCheck, r, c;

    while(!row.empty())
    {
        r = row.front();
        c = row.front();
        std::cout << '\n' <<grid[r][c]<<' '<<r << ", " << c <<'\n';


        row.pop();
        col.pop();

        if(grid[r][c] == 'E') break;
        if(grid[r][c] == 'S' || grid[r][c] != '.') continue;
        grid[r][c] = 'O';


        for(int i = 0; i < 4; i++)
        {
            rowCheck = r+rowDirection[i];
            colCheck = c+colDirection[i];

            if(r == rowCheck && c == colCheck) continue;
            if(rowCheck < 0 || colCheck < 0) continue;
            if(rowCheck > 4 || colCheck >6) continue;

            if(grid[rowCheck][colCheck] == '.')
            {
                row.push(colCheck);
                col.push(colCheck);
                std::cout << rowCheck << ", " << colCheck <<'\n';
            }
        }

    }
}





#endif //DUNGEONBFS_H
