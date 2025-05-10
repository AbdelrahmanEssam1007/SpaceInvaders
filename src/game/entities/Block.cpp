#include "Block.h"

#include "../../utils/Colours.h"
Block::Block(const Vector2 pos) {
  this->pos = pos;
}
void Block::Draw() const {
  DrawRectangle(pos.x, pos.y, 3, 3, Colours::green);
}
