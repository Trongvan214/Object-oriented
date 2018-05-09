//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Grid.cpp
//Description: declaration of the Grid class 

#ifndef __GRID__
#define __GRID__

class Critter;

class Grid {
public:
    Grid();
    Grid(int height, int width);
    void init();
    void addToGrid(Critter *c);
    int getHeightOfGrid();
    int getWidthOfGrid();
    bool isSpotAvailable(int x, int y);
    bool isAnt(int x, int y);
    void eatAnt(int x, int  y);
    Critter* at(int x, int y);
    void clearCell(int x, int y);
    void nextStep();
    void printScores();
    void antsBreedInc();
    void dbsBreedInc();
    void dbsStarvedInc();
    void showGrid();
private:
    //helper function 
    void clearGrid();
    void stepScoresReset();

    //private variable
    int _height, _width; 
    int totalAnts, totalDBs, antsEaten, antsBreed, dBsBreed, dBstarved;
    Critter*** arr;
};

#endif