#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "raylib.h"


class Obstacles {
public:
  explicit Obstacles(Vector2 pos) ;
  void Draw();
private:
  Vector2 pos;
};



#endif //OBSTACLES_H
