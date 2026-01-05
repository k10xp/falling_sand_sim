#include "../external/raylib/src/raylib.h"
#include "config.h"

// simple cell-state array: 0 = empty, 1 = green
int grid[ROWS][COLS] = {0};

// grain = 1 pixel, pile = many grains as isoceles triangle
void UpdateSand(void) {
  // process from bottom to top so each grain moves at most once per frame
  for (int r = ROWS - 2; r >= 0; r--) { // skip last row (cannot fall further)
    for (int c = 0; c < COLS; c++) {
      if (grid[r][c] != 1)
        continue;

      // check cell below, fill if empty
      if (grid[r + 1][c] == 0) {
        grid[r + 1][c] = 1;
        grid[r][c] = 0;
        continue;
      }

      // check diagonal if cell below was filled
      bool moved = false;

      // pick L vs R diagonal to fill at random
      if (GetRandomValue(0, 1) == 0) {
        // down-left
        if (c > 0 && grid[r + 1][c - 1] == 0) {
          grid[r + 1][c - 1] = 1;
          grid[r][c] = 0;
          moved = true;
        } else if (c < COLS - 1 && grid[r + 1][c + 1] == 0) {
          grid[r + 1][c + 1] = 1;
          grid[r][c] = 0;
          moved = true;
        }
      } else {
        // down-right
        if (c < COLS - 1 && grid[r + 1][c + 1] == 0) {
          grid[r + 1][c + 1] = 1;
          grid[r][c] = 0;
          moved = true;
        } else if (c > 0 && grid[r + 1][c - 1] == 0) {
          grid[r + 1][c - 1] = 1;
          grid[r][c] = 0;
          moved = true;
        }
      }

      // stay if can't move anywhere else
      // suppress unused-variable warning if unused (fill cell below)
      (void)moved;
    }
  }
}

void DrawTitle(const char *title) {
  int fontSize = 20;
  int textWidth = MeasureText(title, fontSize);
  int titleX = (SCREEN_WIDTH - textWidth) / 2;
  int titleY = 10;

  DrawText(title, titleX, titleY, fontSize, RAYWHITE);
}

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
  SetTargetFPS(TARGET_FPS);

  while (!WindowShouldClose()) {
    // click to add sand pile (clicked pixel is top of pile)
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 mouse = GetMousePosition();

      // mouse.x & mouse.y is float
      int col = (int)mouse.x / CELL_WIDTH;
      int row = (int)mouse.y / CELL_HEIGHT;

      if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        for (int dy = 0; dy < PILE_HEIGHT; dy++) {
          int r = row + dy;
          if (r < 0 || r >= ROWS)
            break;

          // +1 to each side of base every SPREAD rows
          int halfWidth = dy / SPREAD;

          int cStart = col - halfWidth;
          int cEnd = col + halfWidth;

          if (cStart < 0)
            cStart = 0;
          if (cEnd >= COLS)
            cEnd = COLS - 1;

          for (int c = cStart; c <= cEnd; c++) {
            grid[r][c] = 1;
          }
        }
      }
    }

    UpdateSand();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTitle(TITLE);

    // create pile
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (grid[r][c] == 1) {
          DrawRectangle(c * CELL_WIDTH, r * CELL_HEIGHT, CELL_WIDTH,
                        CELL_HEIGHT, GREEN);
        }
      }
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
