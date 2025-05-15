#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <raylib.h>
#include <vector>

#include "../Laser.h"

class SpaceShip {
 public:
  SpaceShip();
  ~SpaceShip();
  void Draw() const;
  void Move(int direction);
  void Fire();
  void Reset();
  std::vector<Laser*> lasers;
  [[nodiscard]] Rectangle GetHitbox() const;

 private:
  Texture2D m_ShipTexture;
  Vector2 m_ShipPos;
};


#endif  // SPACESHIP_H
