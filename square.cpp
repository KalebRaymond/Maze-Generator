#include "Square.h"

Square::Square()
{
    for(bool &w : walls)
    {
        w = true;
    }

    visited = 0;

}
