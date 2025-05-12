#ifndef ALIEN_H
#define ALIEN_H
#include "raylib.h"
#include <array>


//TODO: Implement Mystery
//TODO: Implement Alien Lasers
//TODO: Adjust Alien Colours

class Alien {
public:
  static std::array<Texture2D,3> g_alienTextures; //* maybe switched to map in the future
  static void UnloadTextures();
  int alienType;
  Vector2 alienPos;
  Color alienColour;
  explicit Alien(Vector2 pos, int alienType);
  void Draw() const;
  void Update(const int direction);
  int GetType() const;
private:
};



#endif //ALIEN_H
