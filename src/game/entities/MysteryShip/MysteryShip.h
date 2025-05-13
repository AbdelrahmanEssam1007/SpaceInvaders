//
// Created by Ryzen 2700 on 13-May-25.
//

#ifndef MYSTERYSHIP_H
#define MYSTERYSHIP_H
#include "raylib.h"


class MysteryShip {
 public:
  MysteryShip();
  ~MysteryShip();
  void Draw() const;
  void Update();
  void Spawn();
  void Deactivate();
  [[nodiscard]] bool IsAlive() const;
  [[nodiscard]] Rectangle GetHitbox() const;

 private:
  Vector2 m_ShipPos;
  Texture2D m_ShipTexture;
  int m_ShipSpeed;
  bool m_IsAlive;
};


#endif  // MYSTERYSHIP_H
