#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "square.h"
#include <cmath>

void printMaze(Square maze[4][4])
{
    std::cout << " _ _ _ _\n";

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

    srand(time(NULL));

    //Start at (0, 0) for simplicity
    std::vector<Square> maze_stack;
    maze_stack.push_back(maze[0][0]);

    //Maze coordinates
    int x = 0;
    int y = 0;

    //Iterative solution
    do{
        int direction = -1;

        while(!(x == 0 && direction == 1) && !(x == 3 && direction == 2) && !(y == 0 && direction == 0) && !(y == 3 && direction == 3))
        {
            direction = rand() % 4;
        }

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

        if(!maze[y][x].visited)
        {
            maze_stack.push_back(maze[y][x]);
            //Erase wall of visited new cell
            maze[y][x].walls[direction] = false;
            //Erase corresponding wall of previous cell
            maze_stack[maze_stack.size() - 2].walls[std::abs(direction - 3)] = false;

            maze[y][x].visited = true;
        }
        else if(x == y && x == 0)
        {
            break;
        }
        else
        {
            maze_stack.erase(maze_stack.end());
        }


    } while(maze_stack.size() > 1);

    printMaze(maze);

}
