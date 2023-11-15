/***
 * Gameplay will get a user input for moves
 * and uopdate the grid based on that move
 * TODO: Get a live reader of the inouts being made to make it more video game like
 ***/
#include "GamePlay.h"
#include "MapDisplay.h"
#include <iostream>
#include <vector>
#include "Weapon.h"

using std::cout, std::endl, std::cin;
GamePlay::GamePlay() {
    fUserInput = ' ';
    fWallIcon = '#';
    fPlayerIcon = '@';
    fBlankSpace = ' ';
    fGridSize = 10;
}
//destructor
GamePlay::~GamePlay() {

}

/**
 * Gets a user input and updates the grid vector based on that move
 * @param pCurrentGrid
 * @param pPLayerY
 * @param pPlayerX
 * @return an updated player grid to be printed in MapDisplay
 */
void GamePlay::updateMove(std::vector<std::vector<char>> &pCurrentGrid, int pPLayerY, int pPlayerX) {
    while (true) {
        GamePlay::getUserInput();

        if (fUserInput == 'q') {
            break; // Quit the game
        }

        // Clear the previous player position
        pCurrentGrid[pPLayerY][pPlayerX] = fBlankSpace;
        Weapon weapon;
        // Update the player position based on the move
        switch (fUserInput) {
            case 'w':
                if (pPLayerY > 1) {
                    pPLayerY--;
                }
                break;
            case 'a':
                if (pPlayerX > 1) {
                    pPlayerX--;
                }
                break;
            case 's':
                if (pPLayerY < fGridSize - 2) {
                    pPLayerY++;
                }
                break;
            case 'd':
                if (pPlayerX < fGridSize - 2) {
                    pPlayerX++;
                }
                break;

            case 'i':
                //displays inventory
                weapon.displayInventory();
                break;
            default:
                break;
        }

        // Set the new player position
        pCurrentGrid[pPLayerY][pPlayerX] = fPlayerIcon;
        MapDisplay mapDisplay;
        mapDisplay.updateDisplay(pCurrentGrid);


    }
}

/**
 * get user input should take just a char
 */
void GamePlay::getUserInput() {
    std::string message;
    bool isGood = false;
    // isGood is our status checker to see if we are good to return the character.

    // Do/while to make sure that we are still checking -- present in all my functions.
    do {

        std::string userString;
        std::cout << "Please enter your move:" << std::endl;



        if (std::getline(std::cin,userString)){
            // checks to see if empty, also checks to see if it size is bigger than 1
            if (userString.size() == 1 && userString[0] == ' '
            || userString[0] == 'q' || userString[0] == 'w' || userString[0] == 'a' || userString[0] == 's' || userString[0] == 'd' || userString[0] == 'i'){

                GamePlay::setUserInput(userString[0]);
                isGood = true;
            } else{
                std::cout << "You did not type in a valid move, if you need a refresher, go to /settings and then /controls" << std::endl;

            }
        } else{
            std::cout << "Argh! You did not type in a character, please try again!""" << std::endl;
            std::cin.clear();
        }


    } while(!isGood);







}

// setter
void GamePlay::setUserInput(char pUserInput) {
    fUserInput = pUserInput;

}


