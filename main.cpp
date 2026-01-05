#include "./external/raylib/src/raylib.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int TARGET_FPS = 60;

// number of cells
const int ROWS = SCREEN_HEIGHT / 8;
const int COLS = SCREEN_WIDTH / 8;

// create pixel instead of grid
const int CELL_WIDTH = SCREEN_WIDTH / COLS;
const int CELL_HEIGHT = SCREEN_HEIGHT / ROWS;

// simple cell-state array: 0 = empty, 1 = green
int grid[ROWS][COLS] = {0};

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

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Falling sand");
  SetTargetFPS(TARGET_FPS);

  while (!WindowShouldClose()) {
    // click to turn pixel green
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 mouse = GetMousePosition();

      // x is col, y is row
      int col = mouse.x / CELL_WIDTH;
      int row = mouse.y / CELL_HEIGHT;

      // confirm in bounds
      if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        grid[row][col] = 1;
      }
    }

    BeginDrawing();
    ClearBackground(BLACK);

    // toggle green
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (grid[r][c] == 1) {
          DrawRectangle(c * CELL_WIDTH, r * CELL_HEIGHT, CELL_WIDTH,
                        CELL_HEIGHT, GREEN);
        }
      }
    }

    // grid: doesn't look nice, good for debug
    // DrawSandGrid(WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
