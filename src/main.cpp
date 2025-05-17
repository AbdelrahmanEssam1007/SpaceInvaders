#include <raylib.h>
#include <string>

#include "game/Game.h"
#include "utils/Colours.h"

constexpr int g_OFFSET = 50;
constexpr int g_SCREEN_WIDTH = 750;
constexpr int g_SCREEN_HEIGHT = 700;
const Image g_LOGO = LoadImage("src/game/assets/logo.png");

std::string FormatScore(const int score, const int width) {
  std::string scoreString = std::to_string(score);
  const int zeros = width - scoreString.length();
  scoreString = std::string(zeros, '0') + scoreString;
  return scoreString;
}


int main() {
  InitWindow(g_SCREEN_WIDTH + g_OFFSET, g_SCREEN_HEIGHT + 2 * g_OFFSET, "Space Invaders");
  InitAudioDevice();

  const Font font = LoadFontEx("src/game/assets/font.ttf", 64, nullptr, 0);
  const Texture2D shipImage = LoadTexture("src/game/assets/spaceship.png");

  SetWindowIcon(g_LOGO);
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.m_Music);
    game.HandleInput();
    game.update();
    BeginDrawing();
    ClearBackground(Colours::grey);
    DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, WHITE);
    DrawLineEx({10, 730}, {790, 730}, 2, WHITE);
    game.Draw();
    if (!game.m_Running) {
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(GRAY, 0.5f));

      const auto msg1 = "Game Over";
      const auto msg2 = "Press Enter to Restart";

      constexpr float fontSize1 = 60;
      constexpr float fontSize2 = 30;

      Vector2 pos1 = MeasureTextEx(font, msg1, fontSize1, 2);
      Vector2 pos2 = MeasureTextEx(font, msg2, fontSize2, 2);

      const float centerY = GetScreenHeight() / 2.0f;

      DrawTextEx(font, msg1, {(GetScreenWidth() - pos1.x) / 2, centerY - pos1.y}, fontSize1, 2, WHITE);

      DrawTextEx(font, msg2, {(GetScreenWidth() - pos2.x) / 2, centerY + 10}, fontSize2, 2, WHITE);
    }
    else {
      std::string levelString = "Level: " + std::to_string(game.m_LevelNumber);
      DrawTextEx(font, levelString.c_str(), {500, 750}, 20, 2, WHITE);
    }

    for (size_t i = 0; i < game.GetLives(); ++i) {
      DrawTextureV(shipImage, {static_cast<float>(g_OFFSET + (i + 1) * 50), 745}, WHITE);
    }

    DrawTextEx(font, "SCORE", {50, 20}, 20, 2, WHITE);
    std::string scoreString = FormatScore(game.m_Score, 5);
    DrawTextEx(font, scoreString.c_str(), {50, 50}, 20, 2, WHITE);
    DrawTextEx(font, "HIGH-SCORE", {500, 20}, 20, 2, WHITE);
    std::string highScoreString = FormatScore(game.m_HighScore, 5);
    DrawTextEx(font, highScoreString.c_str(), {500, 50}, 20, 2, WHITE);

    EndDrawing();
  }
  CloseAudioDevice();
  CloseWindow();
}
