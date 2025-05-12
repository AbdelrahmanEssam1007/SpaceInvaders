#include "Block.h"

#include "../../../utils/Colours.h"
Block::Block(const Vector2 position) {
  this->m_Position = position;
}
void Block::Draw() const {
  DrawRectangle(m_Position.x, m_Position.y, 3, 3, Colours::green);
}
