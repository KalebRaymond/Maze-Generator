/*  Represents a space in a grid forming a complete maze. Each side of each space can either be  /
/   open or walled                                                                              */
class Square
{
    public:
        bool visited;
        bool walls[4];
        Square();
};
