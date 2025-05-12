#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <vector>

#include "Block.h"
#include "raylib.h"


class Obstacles {
 public:
  explicit Obstacles(Vector2 position);
  void Draw() const;
  Vector2 m_Position{};
  std::vector<Block> m_Blocks;
  static std::vector<std::vector<int>> Grid;

 private:
};


#endif  // OBSTACLES_H
