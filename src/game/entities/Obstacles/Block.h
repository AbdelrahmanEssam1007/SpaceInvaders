//
// Created by Ryzen 2700 on 11-May-25.
//

#ifndef BLOCK_H
#define BLOCK_H
#include <raylib.h>


class Block {
 public:
  explicit Block(Vector2 position);
  void Draw() const;
  [[nodiscard]] Rectangle GetHitbox() const;

 private:
  Vector2 m_Position{};
};


#endif  // BLOCK_H
