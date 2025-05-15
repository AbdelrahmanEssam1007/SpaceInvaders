#ifndef GAME_H
#define GAME_H

#include "entities/Aliens/Alien.h"
#include "entities/MysteryShip/MysteryShip.h"
#include "entities/Obstacles/Obstacles.h"
#include "entities/Player/SpaceShip.h"

class Game {
 public:
  Game();
  ~Game();
  void Draw() const;
  void update();
  void HandleInput();
  [[nodiscard]] int GetLives() const;
  int m_Score;
  bool m_Running;
  int m_LevelNumber;
  int m_HighScore;
  Music m_Music;

 private:
  int m_AliensDirection;
  int m_PlayerLives;
  bool m_IsStageCleared;
  SpaceShip m_Ship;
  MysteryShip m_MysteryShip;
  constexpr static float s_AlienLaserInterval = 1.5f;
  float m_TimeSinceLastLaser;
  float m_AlienMoveInterval;
  float m_TimeSinceLastMove;
  float m_MysteryShipInterval;
  float m_TimeSinceLastSpawn;
  std::vector<Obstacles> m_Obstacles;
  std::vector<Alien> m_Aliens;
  std::vector<Laser> m_AlienLasers;
  std::vector<Obstacles> CreateObstacles();
  static std::vector<Alien> CreateAliens();
  void ClearStage();
  void CleanUpLasers();
  void MoveAliens();
  void MoveAliensDown(int distance);
  void ShootAlienLaser();
  void GameOver();
  void CheckForCollisions();
  void Reset();
  void InitGame();
  void CheckHighScore();
  void SaveHighScore(int score);
  static int LoadHighScore();
  Sound m_ExplosionSound;
};


#endif  // GAME_H
