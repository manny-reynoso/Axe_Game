#include <raylib.h>

int main() {

  int width;
  width = 350;

  int height;
  height = 200;
  InitWindow(width, height, "Window");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
