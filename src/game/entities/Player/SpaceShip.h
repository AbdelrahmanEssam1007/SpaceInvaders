#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <raylib.h>
#include <vector>

#include "../Laser.h"

class SpaceShip {
  public:
    SpaceShip();
    ~SpaceShip();
    void Draw() const;
    void Move(int direction);
    void Fire();
    std::vector<Laser*> lasers;
  private:
    Texture2D shipTexture;
    Vector2 shipPos;
};



#endif //SPACESHIP_H
