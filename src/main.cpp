#include <raylib.h>
#include "game/Game.h" 
#include "utils/Colours.h"

constexpr int g_SCREEN_WIDTH = 700;
constexpr int g_SCREEN_HEIGHT = 750;

int main() {
  InitWindow(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Space Invaders");
  SetTargetFPS(60);

  Game game;
  
  while (!WindowShouldClose()) {
    game.HandleInput();
    game.update();
    BeginDrawing();
    ClearBackground(Colours::grey);
    game.Draw();
    EndDrawing();
  }
  CloseWindow();
}
