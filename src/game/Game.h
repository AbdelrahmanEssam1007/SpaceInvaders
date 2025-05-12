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
  int m_AliensDirection;
  SpaceShip m_Ship;
  constexpr static float s_AlienLaserTimer = 1.5f;
  float m_AlienLaserTimer = s_AlienLaserTimer;
  std::vector<Obstacles> m_Obstacles;
  std::vector<Alien> m_Aliens;
  std::vector<Laser> m_AlienLasers;
  std::vector<Obstacles> CreateObstacles();
  static std::vector<Alien> CreateAliens();
  void CleanUpLasers();
  void MoveAliens();
  void MoveAliensDown(int distance);
  void ShootAlienLaser();
};


#endif  // GAME_H
