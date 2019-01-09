#include "Square.h"

Square::Square()
{
    for(bool &w : walls)
    {
        w = true;
    }

    /*walls[0] = true;
    walls[1] = true;
    walls[2] = false;
    walls[3] = true;*/

    visited = false;

}
