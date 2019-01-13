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
    //I feel like I have all the pieces of the puzzle, just not in the right places
    //Have to alter the visited member before pushing to end of vector... so vector pushes back a whole new object? sounds like a lot of memory
    do{
        std::cout << "[" << maze_stack.size() << "]";

        //Check if all adjacent cells have been visited.
        if((y != 3 && maze[y + 1][x].visited == true )
            && (y != 0 && maze[y - 1][x].visited == true)
            && (x != 3 && maze[y][x + 1].visited == true)
            && (x != 0 && maze[y][x - 1].visited == true))
        {
            maze_stack.erase(maze_stack.end() - 1, maze_stack.end());
            y = maze_stack[maze_stack.size() - 1].y;
            x = maze_stack[maze_stack.size() - 1].x;
            continue;
        }

        std::vector<int> directions;
        if(x != 0) {directions.push_back(1); }
        if(x != 3) {directions.push_back(3); }
        if(y != 0) {directions.push_back(0); }
        if(y != 3) {directions.push_back(2); }
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

        //This whole thing needs to be in a while loop or seomthing. If an adjacent cell is already visited, we need to pick another. Only back up
        //if all adjacent cells have been visited
        if(!maze[y][x].visited)
        {
            //Mark new cell as visited and erase wall
            maze[y][x].visited = true;
            maze[y][x].walls[direction] = false;
            maze_stack.push_back(maze[y][x]);

            //Erase corresponding wall of previous cell - potential problem
            maze_stack[maze_stack.size() - 2].walls[std::abs(direction - 3)] = false;
        }
        else /*if(x == y && x == 0)*/
        {
            break;
        }

        std::cout << maze_stack[maze_stack.size() - 1].visited << " ";

    } while(maze_stack.size() > 1);

    printMaze(maze);

}
