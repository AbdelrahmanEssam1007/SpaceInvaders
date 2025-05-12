#include "Laser.h"

#include "../../utils/Colours.h"
Laser::Laser(const Vector2 pos, const int speed, const Color originColour) {
  this->m_Position = pos;
  this->m_Speed = speed;
  this->m_OriginColour = originColour;
  m_IsActive = true;
}
void Laser::Update() {
  m_Position.y += m_Speed;
  if (m_Position.y > GetScreenHeight() || m_Position.y < 0) m_IsActive = false;
}
void Laser::Draw() const {
  if (m_IsActive) DrawRectangle(m_Position.x, m_Position.y, 4, 15, m_OriginColour);
}
bool Laser::IsActive() const {
  return m_IsActive;
}
