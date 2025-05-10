#ifndef GAME_H
#define GAME_H

#include "entities/SpaceShip.h"
#include "entities/Obstacles.h"

class Game {
public:
  Game();
  ~Game();
  void Draw();
  void update();
  void HandleInput();
private:
  SpaceShip ship;
  std::vector<Obstacles> obstacles;
  void CleanUpLasers();
  std::vector<Obstacles> CreateObstacles();
};



#endif //GAME_H
