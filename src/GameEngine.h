//
// Created by grimk on 10/8/2023.
//

#ifndef M1OEP_GAMEENGINE_H
#define M1OEP_GAMEENGINE_H
/**
 * Courtesy https://github.com/llanillo/clion-cmake-sdl2-template/tree/main
 * For proving a template for SDL2 in CLion,
 * would have taken me a millenia had I not found this repo
 * I added a few things to CMakeLists to make sure it was configured for my project
 * but the SDL2 configuration was from here... yay!
 */

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>


#include <iostream>

class GameEngine {
public:
    /*!
     * Required: Nothing
     * Modifies: Nothing
     * Effects: is just default for calling purposes
     */
    GameEngine();
    /*!
     * Required: Nothing
     * Modifies: Nothing
     * Effects: is just default for calling purposes
     */
    ~GameEngine();

    /*!
     * Requires:
     * @param title
     * @param xpos
     * @param ypos
     * @param width     * @param height
     * @param fullscreen
     * Modifies: Nothing
     * Effects: Initiates a renderer window (just a white screen for now)
     * that will be used later to render my game!
     * Also checks to make sure everything can render correctly
     *
     */
    void init(const char* title, int xpos,int ypos, int width, int height, bool fullscreen);
    /*!
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: As the game is played, any inputs will be handled here to be later rendered
     * TODO: Add args for inputs HERE
     */
    void handleEvents();

    /*!
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Updates the state of the game before it is able to be rendered
     */
    void update();

    /*!
     * Requires: Nothing
     * Modifies: *renderer & *window
     * Effects: renders a window
     */
    void render();
    /**
     * Effects: cleans the current renderer and window of memory leaks and closes it
     */
    void clean();

    /**
     * Inline function that
     * returns a bool
     * @return isRunning
     * which will determine if game is running or not
     * if it is not, will be used to shut the window
     * and renderer down
     */
    bool running() {return isRunning;};


private:
    int cnt=0;
    bool isRunning{};
    SDL_Window *window{};
    SDL_Renderer *renderer{};

};

#endif //M1OEP_GAMEENGINE_H
