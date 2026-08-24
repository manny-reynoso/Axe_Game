#include <raylib.h>

int main() {

  // WIndow Dimensions
  int width;
  width = 1280;

  int height;
  height = 720;
  InitWindow(width, height, "Window");

  // circle Coordinates
  int circle_X_Pos{175};
  int circle_Y_Pos{100};

  int circle_Radius = 10;

  // Circle Collision

  int l_circle_x{circle_X_Pos - circle_Radius};
  int r_circle_x{circle_X_Pos + circle_Radius};
  int u_circle_y{circle_Y_Pos - circle_Radius};
  int b_circle_y{circle_Y_Pos + circle_Radius};
  // Axe Coordinates

  int axe_x{400};
  int axe_y{0};

  int direction{10};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Game Logic Start
    DrawCircle(circle_X_Pos, circle_Y_Pos, circle_Radius, BLACK);
    DrawRectangle(axe_x, axe_y, 50, 50, RED);

    // Axe Movement

    axe_y += direction;

    if (axe_y > 720 || axe_y < 0) {
      direction = -direction;
    }

    if (IsKeyDown(KEY_D) && circle_X_Pos < 1280) {
      circle_X_Pos += 10;
    }

    if (IsKeyDown(KEY_A) && circle_X_Pos > 0) {
      circle_X_Pos -= 10;
    }

    if (IsKeyDown(KEY_W) && circle_Y_Pos > 0) {
      circle_Y_Pos -= 10;
    }

    if (IsKeyDown(KEY_S) && circle_Y_Pos < 720) {
      circle_Y_Pos += 10;
    }

    EndDrawing();
  }

  // game Logi Ends
  CloseWindow();

  return 0;
}

// Spent time reading
