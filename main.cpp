#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "square.h"

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
    /*do{
        int direction = rand() % 4;

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

        //Shouldn't this be recursive? And shouldn't revisiting grid spaces be allowed? Wth am I doing?
        if(!maze[y][x].visited)
        {
            maze_stack.push_back(maze[y][x]);
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


    } while(maze_stack.size() > 1);*/

    printMaze(maze);

}
