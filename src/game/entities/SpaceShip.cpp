#include "SpaceShip.h"
SpaceShip::SpaceShip() {
  shipTexture = LoadTexture("src/game/assets/spaceship.png");
  shipPos.x = static_cast<float>((GetScreenWidth() - shipTexture.width)/2);
  shipPos.y = static_cast<float>((GetScreenHeight() - shipTexture.height));
}

SpaceShip::~SpaceShip() {
  UnloadTexture(shipTexture);
}
void SpaceShip::Draw() const {
  DrawTextureV(shipTexture, shipPos, WHITE);
}
void SpaceShip::Move(const int direction) {
  shipPos.x += 10 * direction;
  if (shipPos.x < 0) {
    shipPos.x = 0;
  }
  if (shipPos.x + shipTexture.width > GetScreenWidth()) {
    shipPos.x = static_cast<float>(GetScreenWidth() - shipTexture.width);
  }
}
void SpaceShip::Fire() {
}
