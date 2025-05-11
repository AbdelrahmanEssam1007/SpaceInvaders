#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <vector>

#include "Block.h"
#include "raylib.h"


class Obstacles {
public:
  explicit Obstacles(Vector2 pos) ;
  void Draw();
  Vector2 pos;
  std::vector<Block> blocks;
  static std::vector<std::vector<int>> grid;
private:
};



#endif //OBSTACLES_H
