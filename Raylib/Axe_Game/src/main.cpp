#include <raylib.h>

int main() {

  // WIndow Dimensions
  int width;
  width = 350;

  int height;
  height = 200;
  InitWindow(width, height, "Window");

  // circle Coordinates
  int circle_X_Pos{175};
  int circle_Y_Pos{100};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircle(175, 100, 10, BLACK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}

// Spent time reading
