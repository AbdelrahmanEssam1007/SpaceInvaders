#include "Game.h"

Game::Game() {
  obstacles = CreateObstacles();
  aliens = CreateAliens();
  aliens_direction = 1;
}
Game::~Game() {
  Alien::UnloadTextures();
}
void Game::Draw() {
  ship.Draw();
  for (const auto &laser : ship.lasers) {
    laser->Draw();
  }
  for (auto &obstacle : obstacles) {
    obstacle.Draw();
  }

  for (auto &alien : aliens) {
    alien.Draw();
  }
}
void Game::update() {
  for (const auto &laser : ship.lasers) {
    laser->Update();
  }
  CleanUpLasers();

  MoveAliens();
}
void Game::HandleInput() {
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    ship.Move(1);
  else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    ship.Move(-1);
  if (IsKeyPressed(KEY_SPACE)) ship.Fire();
}
void Game::CleanUpLasers() {
  for (auto it = ship.lasers.begin(); it != ship.lasers.end();) {
    if (!(*it)->isActive) {
      it = ship.lasers.erase(it);
    }
    else {
      ++it;
    }
  }
}
void Game::MoveAliens() {
  for (auto &alien : aliens) {
    if (alien.alienPos.x + alien.g_alienTextures[alien.alienType - 1].width >= GetScreenWidth()) {
      aliens_direction = -1;
      MoveAliensDown(5);
    }

    if (alien.alienPos.x <= 0) {
      aliens_direction = 1;
      MoveAliensDown(5);
    }
    alien.Update(aliens_direction);
  }
}
void Game::MoveAliensDown(const int dist) {
  for (auto &alien : aliens) {
    alien.alienPos.y += dist;
  }
}
std::vector<Obstacles> Game::CreateObstacles() {
  const int s_OBSTACLE_WIDTH = Obstacles::grid[0].size() * 3;
  const float s_GAP = (GetScreenWidth() - s_OBSTACLE_WIDTH * 4) / 5;

  for (int i = 0; i < 4; ++i) {
    const float xOffset = (i + 1) * s_GAP + i * s_OBSTACLE_WIDTH;
    obstacles.push_back(Obstacles({xOffset, static_cast<float>(GetScreenHeight() - 100)}));
  }
  return obstacles;
}
std::vector<Alien> Game::CreateAliens() {
  std::vector<Alien> s_aliens;
  for (int row =0; row < 5; ++row ) {
    int s_alienType;
    if (row == 0) s_alienType = 3;
    else if (row == 1 || row == 2) s_alienType = 2;
    else s_alienType = 1;
    
    for (int column = 0; column < 11; ++column) {
      const float x = 80 + column * 50;
      const float y = 115 + row * 50;
      s_aliens.push_back(Alien({x,y}, s_alienType));
    }
  }
  return s_aliens;
}
