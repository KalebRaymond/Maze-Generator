#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "square.h"
#include <cmath>

void printMaze(Square maze[4][4])
{
    std::cout << "\n _ _ _ _\n";

    for(int i = 0; i < 4; i++)
    {
        std::cout << "|";
        for(int j = 0; j < 4; j++)
        {
            if(maze[i][j].walls[3] || i == 3)
            {
                std::cout << "_";
            }
            else
            {
                std::cout << " ";
            }

            if(maze[i][j].walls[2] || j == 3)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }

}

int main()
{
    Square maze[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            maze[i][j].y = i;
            maze[i][j].x = j;
        }
    }

    srand(time(NULL));

    //Start at (0, 0) for simplicity
    std::vector<Square> maze_stack;
    maze[0][0].visited = true;
    maze_stack.push_back(maze[0][0]);

    //Maze coordinates
    int x = 0;
    int y = 0;

    //Iterative solution
    //Have to alter the visited member before pushing to end of vector... so vector pushes back a whole new object? sounds like a lot of memory
    do{
        std::cout << "[" << maze_stack.size() << "]";

        std::vector<int> directions = {};
        if(x != 0 && !maze[y][x - 1].visited) {directions.push_back(1); }
        if(x != 3 && !maze[y][x + 1].visited) {directions.push_back(2); }
        if(y != 0 && !maze[y - 1][x].visited) {directions.push_back(0); }
        if(y != 3 && !maze[y + 1][x].visited) {directions.push_back(3); }

        //All adjacent cells have been visited
        if(directions.size() == 0)
        {
            //All cells in maze have been visited
            if(maze_stack.size() == 1)
            {
                break;
            }
            //Find new cells
            else
            {
                maze_stack.erase(maze_stack.end() - 1, maze_stack.end());
                y = maze_stack[maze_stack.size() - 1].y;
                x = maze_stack[maze_stack.size() - 1].x;
                continue;
            }
        }

        int direction = directions[rand() % directions.size()];
        std::cout << "{" << direction << "}";

        switch(direction)
        {
            case 0: //Up
                y--;
                break;
            case 1: //Left
                x--;
                break;
            case 2: //Right
                x++;
                break;
            case 3: //Down
                y++;
                break;
        }

        //Mark new cell as visited and erase wall
        maze[y][x].visited = true;
        maze[y][x].walls[std::abs(direction - 3)] = false;
        maze_stack.push_back(maze[y][x]);

        //Erase corresponding wall of previous cell
        //This code is excessive and unsightly - there must be a better way
        int previous_y = maze_stack[maze_stack.size() - 2].y;
        int previous_x = maze_stack[maze_stack.size() - 2].x;
        maze[previous_y][previous_x].walls[direction] = false;
        maze_stack[maze_stack.size() - 2] = maze[previous_y][previous_x];

        std::cout << maze_stack[maze_stack.size() - 1].visited << " ";

    } while(true);

    printMaze(maze);

}
