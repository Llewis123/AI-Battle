/**
 * header file for MapDisplay.cpp
 */

#ifndef M1OEP_MAPDISPLAY_H
#define M1OEP_MAPDISPLAY_H

#include <vector>
#include <iostream>

class MapDisplay {
private:
    // private fields for initial values of maps
    char fPlayerIcon;
    char fWallIcon;
    int fGridSize;
    char fBlankSpace;
    int fInitPlayerX;
    int fInitPlayerY;

    std::vector<std::vector<char>> gridOne;
    std::vector<std::vector<char>> gridTwo;
    std::vector<std::vector<char>> gridThree;


public:

    MapDisplay();
    // destructor
    ~MapDisplay();


    void initDisplay();
    std::vector<std::vector<char>> initGrid();
    void updateDisplay(std::vector<std::vector<char>> &grid);

    void setGrid(std::vector<std::vector<char>>& grid);
    std::vector<std::vector<char>>& getGrid();
    int getInitX();
    int getInitY();


};











#endif //M1OEP_MAPDISPLAY_H
