#ifndef GAME_H
#define GAME_H

#include "entities/Aliens/Alien.h"
#include "entities/Obstacles/Obstacles.h"
#include "entities/Player/SpaceShip.h"

//TODO: implement health for players and enemies
//TODO: implement score

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
  std::vector<Alien> aliens;
  std::vector<Obstacles> CreateObstacles();
  static std::vector<Alien> CreateAliens();
  int aliens_direction;
  void CleanUpLasers();
  void MoveAliens();
  void MoveAliensDown(int dist);
};


#endif  // GAME_H
