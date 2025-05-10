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
}
void Game::HandleInput() {
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) ship.Move(1);
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) ship.Move(-1);
  if (IsKeyPressed(KEY_SPACE)) ship.Fire();
}
