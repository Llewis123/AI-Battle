/**
* @author Lincoln Lewis
 * 9/16/23
 * M1OEP
 * Genetic Algorithm Sci Fi RPG
*/

#include <iomanip>
#include "build/MapDisplay.h"
#include "framework/GameEngine.h"



#include "framework/GamePlay.h"

// TODO: Add pointers for enemy direction and add enemies
// TODO: Graphics 2D
using std::cout, std::cin, std::endl, std::string, std::cerr;

/**
 * function will get a valid integer
 * that corrisponds to a selection in the main menu
 * @return a user input in the main menu
 */
int getIntInput(){
    std::string userInput;
    int userInt;
    bool isValid = false;
    cout << "Enter your input: (1,2 or 3)" << endl;
    do {
        // No special characters
        const std::string specialChars = ",./<>;:'[]{}`~!@#$%^&*()_-+=";
        std::string message = "Please enter 1,2 or 3";
        std::getline(std::cin,userInput);
        bool isGood = true;
        if (userInput.empty() || (userInput != "1" && userInput !="2" && userInput !="3")){
            isGood = false;
            message = "Miss input";
        }

        // trys to convert to integer, catches it if it cant, will be false.
        try {
            userInt = std::stoi(userInput);
        } catch(const std::exception& e){
            isGood = false;
        }

        if (!isGood){;
            std::cin.clear(); // Clear the error state
            std::cout << message <<  endl;
        } else{
            isValid= true;
        }

    } while (!isValid);

    return userInt;

}

/**
 * mainMenu will run the graphic of the main menu
 * and handle all incorrect inputs
 * etc etc
 */
void mainMenu(){
    int input;



    cout << "Welcome to the game that has yet to be named!" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "                    Play (1)                 " << endl;
    cout << "                  Settings (2)               " << endl;
    cout << "                    Exit (3)                 " << endl;
    input = getIntInput();
    if (input == 1){
        // runs the game
        MapDisplay mapDisplay;
        GamePlay gamePlay;
        mapDisplay.initGrid();
        mapDisplay.initDisplay();
        gamePlay.updateMove(mapDisplay.getGrid(),mapDisplay.getInitX(), mapDisplay.getInitY());
    }
    if (input == 2){
        // opens settings panel
        cout << "-------------------Settings------------------" << endl;
        cout << "                  Graphics (1)               " << endl;
        cout << "                  Controls (2)               " << endl;
        cout << "                    Back (3)                 " << endl;

        int input = getIntInput();

        if (input == 1) {
            cout << "This page is a work in progress!!" << endl;
            string in;
            cout << "Type anything to go back" << endl;
            while (in.empty()){
                cin >> in;
            }
            mainMenu();
        }
        if (input == 2){
            cout << "---------Controls-----------" << endl;
            cout << " q | exit game |" << endl;
            cout << " i | view inventory |" << endl;
            cout << " w | move up 1 space |" << endl;
            cout << " a | move left 1 space |" << endl;
            cout << " d | move right 1 space |" << endl;
            cout << " s | move down 1 space |" << endl;
            cout << "------------------------" << endl;
            string in;

            cout << "Type anything to go back" << endl;
            while (in.empty()){
                cin >> in;
            }
            mainMenu();
        }
        if (input == 3){
            mainMenu();
        }
    }
}

/**
 * Just runs the main menu portion
*/
GameEngine *GAME = nullptr;


int main(int argc, char *argv[]){



//    SDL_Init(SDL_INIT_EVERYTHING);
//    SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,400,SDL_WINDOW_SHOWN);
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
//
//    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//    SDL_RenderClear(renderer);
//    SDL_RenderPresent(renderer);
//
//    SDL_Delay(3000);
//
    GAME = new GameEngine();

    GAME->init("TestEngine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);

//    if(TTF_Init() > 0){
//        std::cout<< "TTF failed to initialie" << std::endl;
//    }


    while (GAME->running()){
        // TODO: Add check statements in between these three to check for is running
        GAME->handleEvents();
        GAME->update();
        GAME->render();

        if (!GAME->running()) {
            break;
        }
    }
    GAME->clean();

    return 0;
};
