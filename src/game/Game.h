#ifndef GAME_H
#define GAME_H

#include "entities/Obstacles/Obstacles.h"
#include "entities/Player/SpaceShip.h"

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
