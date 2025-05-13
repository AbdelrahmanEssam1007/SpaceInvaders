#ifndef ALIEN_H
#define ALIEN_H
#include <array>

#include "raylib.h"


class Alien {
 public:
  static std::array<Texture2D, 3> s_AlienTextures;  //* maybe switched to map in the future
  static void UnloadTextures();
  Vector2 m_AlienPos;
  explicit Alien(Vector2 position, int alienType);
  void Draw() const;
  // void Update(int direction);
  [[nodiscard]] int GetType() const;
  [[nodiscard]] Color GetColour() const;
  [[nodiscard]] Rectangle GetHitbox() const;

 private:
  Color m_AlienColour;
  int m_AlienType;
};


#endif  // ALIEN_H
