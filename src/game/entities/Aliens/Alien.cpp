#include "Alien.h"

#include "../../../utils/Colours.h"

std::array<Texture2D, 3> Alien::s_AlienTextures = {};

void Alien::UnloadTextures() {
  for (int i = 0; i < 3; i++) {
    UnloadTexture(s_AlienTextures[i]);
  }
}
Alien::Alien(const Vector2 position, const int alienType) {
  this->m_AlienPos = position;
  this->m_AlienType = alienType;

  switch (m_AlienType) {
    case 1:
      m_AlienColour = Colours::magenta;
      break;
    case 2:
      m_AlienColour = Colours::cyan;
      break;
    case 3:
      m_AlienColour = Colours::lime;
      break;
    default:
      m_AlienColour = Colours::magenta;
      break;
  }

  if (s_AlienTextures[m_AlienType - 1].id == 0) {
    switch (m_AlienType) {
      case 1:
        s_AlienTextures[m_AlienType - 1] = LoadTexture("src/game/assets/alien_1.png");
        break;
      case 2:
        s_AlienTextures[m_AlienType - 1] = LoadTexture("src/game/assets/alien_2.png");
        break;
      case 3:
        s_AlienTextures[m_AlienType - 1] = LoadTexture("src/game/assets/alien_3.png");
        break;
      default:
        s_AlienTextures[m_AlienType - 1] = LoadTexture("src/game/assets/alien_1.png");
        break;
    }
  }
}
void Alien::Draw() const {
  DrawTextureV(s_AlienTextures[m_AlienType - 1], m_AlienPos, WHITE);
}
int Alien::GetType() const {
  return m_AlienType;
}
Color Alien::GetColour() const {
  return m_AlienColour;
}
Rectangle Alien::GetHitbox() const {
  return {m_AlienPos.x, m_AlienPos.y, static_cast<float>(s_AlienTextures[m_AlienType - 1].width),
          static_cast<float>(s_AlienTextures[m_AlienType - 1].height)};
}
