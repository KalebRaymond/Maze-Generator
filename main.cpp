#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "square.h"

int main()
{
    Square maze_grid[4][4];

    srand(time(NULL));

    //Start at (0, 0) for simplicity
    std::vector<Square> maze_stack;
    maze_stack.push_back(maze_grid[0][0]);

    do{
        int direction = rand() % 4;

        switch(direction)
            case 0: //Up
                break;
            case 1: //Left
                break;
            case 2: //Right
                break;
            case 3: //Down
                break;

    } while(maze_stack.size() > 1);

}
