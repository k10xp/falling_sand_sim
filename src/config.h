#ifndef CONFIG_H
#define CONFIG_H

#include "../external/raylib/src/raylib.h"

// app params
#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60
#define TITLE "Falling Sand Simulation"

// grid calculations
#define ROWS (SCREEN_HEIGHT / 8)
#define COLS (SCREEN_WIDTH / 8)

#define CELL_WIDTH (SCREEN_WIDTH / COLS)
#define CELL_HEIGHT (SCREEN_HEIGHT / ROWS)

// sand params
#define PILE_HEIGHT 6
#define SPREAD 2 // +1 to each side of base every SPREAD rows

#endif
