//
// Created by grimk on 10/8/2023.
//
#include "GameEngine.h"
using std::cout, std::endl;
SDL_Window *m_pWindow = NULL;
SDL_Renderer *m_pRenderer = NULL;
GameEngine::GameEngine() = default;

GameEngine::~GameEngine() = default;


void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    // if fullscreen is set to true, we set window to fullscreen
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    // check to see if SDL was initialized
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Successfully Initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, 0, flags);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer initialized" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
        std::cout << "SDL Failed to initialize!" << std::endl;
    }

//    SDL_Surface *fontSurface = SDL_LoadBMP("path/to/font.bmp");
//    fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
//    SDL_FreeSurface(fontSurface);
}

void GameEngine::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    // for now just until we do quit
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    // Quit the game when the escape key is pressed
                    isRunning = false;
                    break;
                    // Handle other key events as needed
                    // case SDL_SCANCODE_A:
                    //     // Handle 'A' key press
                    //     break;
                    // case SDL_SCANCODE_B:
                    //     // Handle 'B' key press
                    //     break;
                default:
                    break;
            }
        case SDLK_ESCAPE:
            // going to quit the game when the escape key is pressed
            isRunning = false;
            break;
        case SDL_KEYUP:
            break;
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void GameEngine::update() {
    // counter for everytime the game updates
    ++cnt;

}

//void GameEngine::renderText(const char *text, int x, int y) {
//    int length = strlen(text);
//
//    for (int i = 0; i < length; ++i) {
//        char currentChar = text[i];
//        int charIndex = currentChar - ' ';  // Adjust index based on ASCII value
//
//        SDL_Rect srcRect = {charIndex * CHAR_WIDTH, 0, CHAR_WIDTH, CHAR_WIDTH};
//        SDL_Rect destRect = {x + i * CHAR_WIDTH, y, CHAR_WIDTH, CHAR_WIDTH};
//
//        SDL_RenderCopy(renderer, fontTexture, &srcRect, &destRect);
//    }
//}

void GameEngine::render() {
    SDL_RenderClear(renderer);
    // TODO: Add stuff to render
    // Render text at position (100, 100)

    SDL_RenderPresent(renderer);

}

void GameEngine::clean() {
    // Takes the game out
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Quit!" << std::endl;
}

