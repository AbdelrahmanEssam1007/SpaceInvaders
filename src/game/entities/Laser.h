#ifndef LASER_H
#define LASER_H
#include "raylib.h"


class Laser {
 public:
  Laser(Vector2 pos, int speed, Color originColour);
  void Update();
  void Draw() const;
  [[nodiscard]] bool IsActive() const;

 private:
  Vector2 m_Position;
  int m_Speed;
  Color m_OriginColour;
  bool m_IsActive;
};


#endif  // LASER_H
