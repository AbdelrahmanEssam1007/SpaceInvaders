#ifndef GAME_H
#define GAME_H

#include "entities/Aliens/Alien.h"
#include "entities/Obstacles/Obstacles.h"
#include "entities/Player/SpaceShip.h"

// TODO: implement health for players and enemies
// TODO: implement score

class Game {
 public:
  Game();
  ~Game();
  void Draw() const;
  void update();
  void HandleInput();

 private:
  SpaceShip m_Ship;
  std::vector<Obstacles> m_Obstacles;
  std::vector<Alien> m_Aliens;
  std::vector<Obstacles> CreateObstacles();
  static std::vector<Alien> CreateAliens();
  int m_AliensDirection;
  void CleanUpLasers();
  void MoveAliens();
  void MoveAliensDown(int distance);
};


#endif  // GAME_H
