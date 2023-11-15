//
// Created by grimk on 9/17/2023.
//

#ifndef M1OEP_GAMEPLAY_H
#define M1OEP_GAMEPLAY_H

#include <vector>
class GamePlay{
private:

     char fUserInput;
     char fPlayerIcon;
     char fWallIcon;
     int fGridSize;
     char fBlankSpace;

public:
    GamePlay();
    ~GamePlay();

    void setUserInput(char fUserInput);
    void getUserInput();
    void updateMove(std::vector<std::vector<char>> &pCurrentGrid, int pPLayerY, int pPlayerX);



};




#endif //M1OEP_GAMEPLAY_H
