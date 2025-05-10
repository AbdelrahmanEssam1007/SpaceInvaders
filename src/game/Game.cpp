//
// Created by Ryzen 2700 on 11-May-25.
//

#include "Game.h"

Game::Game() {
}
Game::~Game() {
}
void Game::Draw() const {
  ship.Draw();
  for (const auto &laser : ship.lasers) {
    laser->Draw();
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
