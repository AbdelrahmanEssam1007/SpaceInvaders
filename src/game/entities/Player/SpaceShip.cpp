#include "SpaceShip.h"

#include "../../../utils/Colours.h"
SpaceShip::SpaceShip() {
  m_ShipTexture = LoadTexture("src/game/assets/spaceship.png");
  m_ShipPos.x = static_cast<float>((GetScreenWidth() - m_ShipTexture.width) / 2);
  m_ShipPos.y = static_cast<float>((GetScreenHeight() - m_ShipTexture.height - 100));
}

SpaceShip::~SpaceShip() {
  UnloadTexture(m_ShipTexture);
}
void SpaceShip::Draw() const {
  DrawTextureV(m_ShipTexture, m_ShipPos, WHITE);
}
void SpaceShip::Move(const int direction) {
  m_ShipPos.x += 10 * direction;
  if (m_ShipPos.x < 25) {
    m_ShipPos.x = 25;
  }
  if (m_ShipPos.x  > GetScreenWidth() - m_ShipTexture.width -25 ) {
    m_ShipPos.x = static_cast<float>(GetScreenWidth() - m_ShipTexture.width - 25);
  }
}
void SpaceShip::Fire() {
  lasers.push_back(new Laser(Vector2{m_ShipPos.x + m_ShipTexture.width / 2 - 2, m_ShipPos.y}, -6, Colours::red));
}
void SpaceShip::Reset() {
  m_ShipPos.x = static_cast<float>((GetScreenWidth() - m_ShipTexture.width) / 2);
  m_ShipPos.y = static_cast<float>((GetScreenHeight() - m_ShipTexture.height - 100));
  lasers.clear();
}
Rectangle SpaceShip::GetHitbox() const {
  return {m_ShipPos.x, m_ShipPos.y, static_cast<float>(m_ShipTexture.width), static_cast<float>(m_ShipTexture.height)};
}
