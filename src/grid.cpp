#include "../external/raylib/src/raylib.h"
#include "config.h"

// use for debug
void DrawSandGrid(Color color) {
  // horizontal grid lines
  for (int i = 0; i <= ROWS; i++) {
    int posY = i * CELL_HEIGHT;
    DrawLine(0, posY, SCREEN_WIDTH, posY, color);
  }

  // vertical grid lines
  for (int i = 0; i <= COLS; i++) {
    int posX = i * CELL_WIDTH;
    DrawLine(posX, 0, posX, SCREEN_HEIGHT, color);
  }
}
