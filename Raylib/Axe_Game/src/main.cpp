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

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Game Logic Start
    DrawCircle(circle_X_Pos, circle_Y_Pos, 10, BLACK);

    if (IsKeyDown(KEY_D)) {
      circle_X_Pos = circle_X_Pos + 10;
    }

    if (IsKeyDown(KEY_A)) {
      circle_X_Pos = circle_X_Pos - 10;
    }

    if (IsKeyDown(KEY_W)) {
      circle_Y_Pos = circle_Y_Pos - 10;
    }

    if (IsKeyDown(KEY_S)) {
      circle_Y_Pos = circle_Y_Pos + 10;
    }

    EndDrawing();
  }

  // game Logi Ends
  CloseWindow();

  return 0;
}

// Spent time reading
