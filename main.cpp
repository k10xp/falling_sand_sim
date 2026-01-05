#include "./external/raylib/src/raylib.h"

// SCREEN PROPERTIES
const int screenWidth = 900;
const int screenHeight = 600;
const int targetFPS = 60;

// Grid properties
// Im trying to keep the grid to appear as squares
// thats why im dividing by the same factor
int rows = screenHeight / 8;
int cols = screenWidth / 8;

// Grid Functions
void DrawSandGrid(Color color) {
  // Im using the notation for matrices(col,row);
  // rows control horiontal line therefore controls y axis
  for (int i = 0; i < rows; i++) {
    int posY = i * screenHeight / rows;
    DrawLine(0, posY, screenWidth, posY, color);
  }

  for (int i = 0; i < cols; i++) {
    int posX = i * screenWidth / cols;
    DrawLine(posX, 0, posX, screenHeight, color);
  }
}

int main() {
  InitWindow(screenWidth, screenHeight, "Falling sand");
  SetTargetFPS(targetFPS);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawSandGrid(WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
