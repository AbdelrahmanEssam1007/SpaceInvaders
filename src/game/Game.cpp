//
// Created by Ryzen 2700 on 11-May-25.
//

#include "Game.h"

Game::Game() {
  obstacles = CreateObstacles();
}
Game::~Game() {
}
void Game::Draw() {
  ship.Draw();
  for (const auto &laser : ship.lasers) {
    laser->Draw();
  }
  for (auto &obstacle : obstacles) {
    obstacle.Draw();
  }
}
void Game::update() {
  for (const auto &laser : ship.lasers) {
    laser->Update();
  }
  CleanUpLasers();
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
std::vector<Obstacles> Game::CreateObstacles() {
  const int s_OBSTACLE_WIDTH = Obstacles::grid[0].size() * 3;
  const float s_GAP = (GetScreenWidth() - s_OBSTACLE_WIDTH*4)/5;

  for (int i = 0; i < 4; ++i) {
    const float xOffset = (i+1) * s_GAP + i * s_OBSTACLE_WIDTH;
    obstacles.push_back(Obstacles({xOffset, static_cast<float>(GetScreenHeight() - 100)}));
  }
  return obstacles;
}
