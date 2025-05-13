//
// Created by Ryzen 2700 on 13-May-25.
//

#include "MysteryShip.h"
MysteryShip::MysteryShip() {
  m_ShipTexture = LoadTexture("src/game/assets/mystery.png");
  m_IsAlive = false;
}
MysteryShip::~MysteryShip() {
  UnloadTexture(m_ShipTexture);
}
void MysteryShip::Draw() const {
  if (m_IsAlive) {
    DrawTextureV(m_ShipTexture, m_ShipPos, WHITE);
  }
}
void MysteryShip::Update() {
  if (m_IsAlive) {
    m_ShipPos.x += m_ShipSpeed;
    if (m_ShipPos.x < 0 || m_ShipPos.x + m_ShipTexture.width > GetScreenWidth()) {
      m_IsAlive = false;
    }
  }
}
void MysteryShip::Spawn() {
  m_ShipPos.y = 90;
  int startSide = GetRandomValue(0, 1);
  if (startSide == 0) {
    m_ShipPos.x = 0;
    m_ShipSpeed = 3;
  }
  else {
    m_ShipPos.x = GetScreenWidth() - m_ShipTexture.width;
    m_ShipSpeed = -3;
  }
  m_IsAlive = true;
}
void MysteryShip::Deactivate() {
  m_IsAlive = false;
}
bool MysteryShip::IsAlive() const {
  return m_IsAlive;
}
Rectangle MysteryShip::GetHitbox() const {
  if (m_IsAlive) {
    return {m_ShipPos.x, m_ShipPos.y, static_cast<float>(m_ShipTexture.width), static_cast<float>(m_ShipTexture.height)};
  }
  else {
    return {m_ShipPos.x, m_ShipPos.y, 0, 0}; 
  }
}


