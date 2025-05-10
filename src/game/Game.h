#ifndef GAME_H
#define GAME_H

#include "entities/SpaceShip.h"  

class Game {
public:
  Game();
  ~Game();
  void Draw() const;
  void update();
  void HandleInput();
private:
  SpaceShip ship;
};



#endif //GAME_H
