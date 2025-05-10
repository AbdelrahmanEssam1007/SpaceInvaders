
#ifndef LASER_H
#define LASER_H
#include "raylib.h"


class Laser {
public:
  Laser(Vector2 pos, int speed, Color originColour);
  void Update();
  void Draw() const;
  bool isActive;
private:
  Vector2 pos;
  int speed;
  Color originColour;
  
};



#endif //LASER_H
