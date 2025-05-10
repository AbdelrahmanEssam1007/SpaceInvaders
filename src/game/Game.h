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
  void CleanUpLasers();
  SpaceShip ship;
};



#endif //GAME_H
