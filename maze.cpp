//
//  maze.cpp
//  hw3
//
//  Created by William  Escobar on 5/10/23.
//

//#include <stack>
//#include <iostream>
//#include <cassert>
//Declare Prototype
bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

//Define Coord Class: a class object which holds the current position (r,c)
class Coord
{
    public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {} //initializes row and column positions
    int r() const { return m_r; } //return current row position
    int c() const { return m_c; } //return current column position

    private:
    //member variables that hold the position
    int m_r;
    int m_c;
};
//------------------------------------------------------------------------
//     bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
//
// Returns true if there is a path from (sr, sc) to (er, ec) through maze
// Otherwise it returns false if no path exists
//------------------------------------------------------------------------
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    //create two coordinate objects which keep track of our current position
    //and the position of the end of the maze
    Coord curr(sr, sc); //create the starting coordinate
    Coord end(er, ec); //create the ending coordinate

        //case when our current position is the starting position
    if(curr.r() == end.r() && curr.c() == end.c())
        return true;
        //mark current position as discovered
    maze[curr.r()][curr.c()] = '#';

    //code to explore different directions
        //look to the SOUTH--------------------------------
    if(maze[curr.r()+1][curr.c()] == '.')
    {
        if(pathExists(maze, curr.r()+1, curr.c(), er, ec) )
            return true;
    }
        //look to the EAST---------------------------------
    if(maze[curr.r()][curr.c()+1] == '.')
    {
         if(pathExists(maze, curr.r(), curr.c()+1, er, ec))
             return true;
    }
        //look to the NORTH--------------------------------
    if(maze[curr.r()-1][curr.c()] == '.')
    {
        if(pathExists(maze, curr.r()-1, curr.c(), er, ec) )
            return true;
    }
        //look to the WEST--------------------------------
    if(maze[curr.r()][curr.c()-1] == '.')
    {
        if(pathExists(maze, curr.r(), curr.c()-1, er, ec) )
            return true;
    }
    return false;
}
