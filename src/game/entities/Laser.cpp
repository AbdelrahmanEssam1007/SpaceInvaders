#include "Laser.h"

#include "../../utils/Colours.h"
Laser::Laser(const Vector2 pos, const int speed, const Color originColour) {
  this->pos = pos;
  this->speed = speed;
  this->originColour = originColour;
  isActive = true;
}
void Laser::Update() {
  pos.y += speed;
  if (pos.y > GetScreenHeight() || pos.y < 0) isActive = false;
}
void Laser::Draw() const {
  if (isActive) DrawRectangle(pos.x, pos.y, 4, 15, originColour);
}
