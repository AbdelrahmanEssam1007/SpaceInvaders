#include "Alien.h"

#include "../../../utils/Colours.h"

std::array<Texture2D, 3> Alien::g_alienTextures = {};

void Alien::UnloadTextures() {
  for (int i = 0; i < 3; i++) {
    UnloadTexture(g_alienTextures[i]);
  }
}
Alien::Alien(const Vector2 pos, const int alienType) {
  this->alienPos = pos;
  this->alienType = alienType;
  if (g_alienTextures[alienType-1].id == 0) {
    switch (alienType) {
      case 1:
        g_alienTextures[alienType-1] = LoadTexture("src/game/assets/alien_1.png");
        alienColour = Colours::magenta;
        break;
      case 2:
        g_alienTextures[alienType-1] = LoadTexture("src/game/assets/alien_2.png");
        alienColour = Colours::blue;
        break;
      case 3:
        g_alienTextures[alienType-1] = LoadTexture("src/game/assets/alien_3.png");
        alienColour = Colours::lime;
        break;
      default:
        g_alienTextures[alienType-1] = LoadTexture("src/game/assets/alien_1.png");
        alienColour = Colours::magenta;
        break;
    }
  }
}
void Alien::Draw() const {
  DrawTextureV(g_alienTextures[alienType - 1], alienPos, alienColour);
}
void Alien::Update(const int direction) {
  alienPos.x += direction *GetFrameTime()*60; //!needs more testing
}

