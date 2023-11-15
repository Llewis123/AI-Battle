/**
 * Lincoln Lewis
 * 9/17/23
 * This file will serve as a runner for all of the mapDisplay's
 * There will be a few types of map displays depending on the map and the level of difficulty
 *
 */
#include "MapDisplay.h"






using std::cout, std::endl;

// This shoudd basically just set the vectors for the grids up as needed.
/**
 * Resizes things
 * TODO: Create different grids based on difficulty
 * also initializes the maps
 */
MapDisplay::MapDisplay() {
    fWallIcon = '#';
    fPlayerIcon = '@';
    fBlankSpace = ' ';
    fGridSize = 10;

    gridTwo.resize(fGridSize,std::vector<char>(fGridSize, fBlankSpace));
    gridThree.resize(fGridSize,std::vector<char>(fGridSize, fBlankSpace));

    //Initialz
    fInitPlayerX = 2;
    fInitPlayerY = 2;



}
MapDisplay::~MapDisplay() {

}


/**
 * Shoud initilize grid, give a few prompts etc
 * Only display grid
 * @param grid
 */
void MapDisplay::initDisplay() {
    for (const auto& row : gridOne) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

/**
 * initGrid fills a vector of vectors of chars
 * with either a wall icon, player or an empty space
 * @return grid
 */
std::vector<std::vector<char>> MapDisplay::initGrid() {
    gridOne.resize(fGridSize,std::vector<char>(fGridSize, fBlankSpace));
    // Create walls around the grid
    for (int i = 0; i < fGridSize; ++i) {
        gridOne[0][i] = fWallIcon;
        gridOne[fGridSize - 1][i] = fWallIcon;
        gridOne[i][0] = fWallIcon;
        gridOne[i][fGridSize - 1] = fWallIcon;
    }

    //Initial player position

    gridOne[fInitPlayerY][fInitPlayerX] = fPlayerIcon;

    return gridOne;
}

// setters for grid
void MapDisplay::setGrid(std::vector<std::vector<char>> &grid) {

    gridOne = grid;


}
// getters
std::vector<std::vector<char>> &MapDisplay::getGrid() {
    return gridOne;
}

int MapDisplay::getInitX() {
    return fInitPlayerX;
}
int MapDisplay::getInitY() {
    return fInitPlayerY;
}

/**
 * Takes in grid vector and displays it
 * TODO: Have a gui that live updates
 * @param grid
 */
void MapDisplay::updateDisplay(std::vector<std::vector<char>> &grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }



}


