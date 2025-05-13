#include "Game.h"

Game::Game() {
  m_Obstacles = CreateObstacles();
  m_Aliens = CreateAliens();
  m_AliensDirection = 1;
  m_TimeSinceLastLaser = 0;
  m_TimeSinceLastMove = 0;
  m_TimeSinceLastSpawn = 0;
  m_MysteryShipInterval = GetRandomValue(10.0, 20.0);
}
Game::~Game() {
  Alien::UnloadTextures();
}
void Game::Draw() const {
  m_Ship.Draw();
  m_MysteryShip.Draw();
  for (const auto& laser : m_Ship.lasers) {
    laser->Draw();
  }
  for (auto& obstacle : m_Obstacles) {
    obstacle.Draw();
  }

  for (auto& alien : m_Aliens) {
    alien.Draw();
  }

  for (auto& laser : m_AlienLasers) {
    laser.Draw();
  }
}
void Game::update() {
  double currentTime = GetTime();
  if (currentTime - m_TimeSinceLastSpawn >= m_MysteryShipInterval) {
    m_MysteryShip.Spawn();
    m_TimeSinceLastSpawn = GetTime();
    m_MysteryShipInterval = GetRandomValue(10.0, 20.0);
  }
  m_AlienMoveInterval = std::max(0.5f, 1.0f * (m_Aliens.size() / 55.0f));
  for (const auto& laser : m_Ship.lasers) {
    laser->Update();
  }
  const float dt = GetFrameTime();
  m_TimeSinceLastMove += dt;
  if (m_TimeSinceLastMove >= m_AlienMoveInterval) {
    MoveAliens();
    m_TimeSinceLastMove = 0.0f;
  }

  ShootAlienLaser();

  for (auto& laser : m_AlienLasers) {
    laser.Update();
  }

  CleanUpLasers();
  m_MysteryShip.Update();

  CheckForCollisions();
}
void Game::HandleInput() {
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    m_Ship.Move(1);
  else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    m_Ship.Move(-1);
  if (IsKeyPressed(KEY_SPACE)) m_Ship.Fire();
}
void Game::CleanUpLasers() {
  for (auto it = m_Ship.lasers.begin(); it != m_Ship.lasers.end();) {
    if (!(*it)->IsActive()) {
      it = m_Ship.lasers.erase(it);
    }
    else {
      ++it;
    }
  }

  for (auto it = m_AlienLasers.begin(); it != m_AlienLasers.end();) {
    if (!(*it).IsActive()) {
      it = m_AlienLasers.erase(it);
    }
    else {
      ++it;
    }
  }
}
void Game::MoveAliens() {
  bool shouldMoveDown = false;
  constexpr int moveDistance = 20;  // Discrete pixel movement per step

  // Check if any alien has hit the boundary
  for (auto& alien : m_Aliens) {
    const int alienWidth = alien.s_AlienTextures[alien.GetType() - 1].width;
    if ((alien.m_AlienPos.x + alienWidth >= GetScreenWidth() && m_AliensDirection > 0) ||
        (alien.m_AlienPos.x <= 0 && m_AliensDirection < 0)) {
      shouldMoveDown = true;
      break;
    }
  }

  if (shouldMoveDown) {
    m_AliensDirection *= -1;  // Reverse direction
    MoveAliensDown(moveDistance);
  }
  else {
    // Move all aliens horizontally
    for (auto& alien : m_Aliens) {
      alien.m_AlienPos.x += moveDistance * m_AliensDirection;
    }
  }
}
void Game::MoveAliensDown(const int distance) {
  for (auto& alien : m_Aliens) {
    alien.m_AlienPos.y += distance;
  }
}
void Game::ShootAlienLaser() {
  double currentTime = GetTime();
  if (currentTime - m_TimeSinceLastLaser >= s_AlienLaserInterval && !m_Aliens.empty()) {
    const int RandomAlien = GetRandomValue(0, m_Aliens.size() - 1);
    const Alien& alien = m_Aliens[RandomAlien];
    const int x = alien.m_AlienPos.x + alien.s_AlienTextures[alien.GetType() - 1].width / 2;
    const int y = alien.m_AlienPos.y + alien.s_AlienTextures[alien.GetType() - 1].height;
    m_AlienLasers.push_back(Laser({static_cast<float>(x), static_cast<float>(y)}, 6, alien.GetColour()));
    m_TimeSinceLastLaser = GetTime();
  }
}
void Game::CheckForCollisions() {
  // spaceship lasers
  for (const auto& laser : m_Ship.lasers) {
    auto it = m_Aliens.begin();
    while (it != m_Aliens.end()) {
      if (CheckCollisionRecs(it->GetHitbox(), laser->GetHitbox())) {
        it = m_Aliens.erase(it);
        laser->DeactivateLaser();
      }
      else {
        ++it;
      }
    }
    for (auto& obstacle : m_Obstacles) {
      auto bit = obstacle.m_Blocks.begin();
      while (bit != obstacle.m_Blocks.end()) {
        if (CheckCollisionRecs(bit->GetHitbox(), laser->GetHitbox())) {
          bit = obstacle.m_Blocks.erase(bit);
          laser->DeactivateLaser();
        }
        else {
          ++bit;
        }
      }
    }

    if (CheckCollisionRecs(m_MysteryShip.GetHitbox(), laser->GetHitbox())) {
      m_MysteryShip.Deactivate();
      laser->DeactivateLaser();
    }
  }
  // alien lasers
  for (auto& laser : m_AlienLasers) {
    if (CheckCollisionRecs(m_Ship.GetHitbox(), laser.GetHitbox())) {
      laser.DeactivateLaser();
    }
    for (auto& obstacle : m_Obstacles) {
      auto bit = obstacle.m_Blocks.begin();
      while (bit != obstacle.m_Blocks.end()) {
        if (CheckCollisionRecs(bit->GetHitbox(), laser.GetHitbox())) {
          bit = obstacle.m_Blocks.erase(bit);
          laser.DeactivateLaser();
        }
        else {
          ++bit;
        }
      }
    }
  }

  // alien collisions
  for (auto& alien : m_Aliens) {
    for (auto& obstacle : m_Obstacles) {
      auto it = obstacle.m_Blocks.begin();
      while (it != obstacle.m_Blocks.end()) {
        if (CheckCollisionRecs(it->GetHitbox(), alien.GetHitbox())) {
          it = obstacle.m_Blocks.erase(it);
        }
        else {
          ++it;
        }
      }
    }

    if (CheckCollisionRecs(alien.GetHitbox(), m_Ship.GetHitbox())) {
    }
  }
}

std::vector<Obstacles> Game::CreateObstacles() {
  const int s_OBSTACLE_WIDTH = Obstacles::Grid[0].size() * 3;
  const float s_GAP = (GetScreenWidth() - s_OBSTACLE_WIDTH * 4) / 5;

  for (int i = 0; i < 4; ++i) {
    const float xOffset = (i + 1) * s_GAP + i * s_OBSTACLE_WIDTH;
    m_Obstacles.push_back(Obstacles({xOffset, static_cast<float>(GetScreenHeight() - 100)}));
  }
  return m_Obstacles;
}
std::vector<Alien> Game::CreateAliens() {
  std::vector<Alien> s_aliens;
  for (int row = 0; row < 5; ++row) {
    int AlienType;
    if (row == 0)
      AlienType = 3;
    else if (row == 1 || row == 2)
      AlienType = 2;
    else
      AlienType = 1;

    for (int column = 0; column < 11; ++column) {
      const float x = 80 + column * 50;
      const float y = 115 + row * 50;
      s_aliens.push_back(Alien({x, y}, AlienType));
    }
  }
  return s_aliens;
}
