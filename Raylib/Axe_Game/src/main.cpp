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

  // Axe Coordinates

  int axe_x{400};
  int axe_y{0};

  int axe_length{50};
  int axe_height{50};

  int direction{10};

  bool collision_with_axe{true};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (collision_with_axe) {
      DrawText("Game Over!", 310, 640, 20, RED);
    }

    else {

      // Axe Movement

      axe_y += direction;

      // Circle Collision

      int l_circle_x{circle_X_Pos - circle_Radius};
      int r_circle_x{circle_X_Pos + circle_Radius};
      int u_circle_y{circle_Y_Pos - circle_Radius};
      int b_circle_y{circle_Y_Pos + circle_Radius};

      // Axe Collision

      int l_axe_x{axe_x};
      int r_axe_x{axe_x + axe_length};
      int u_axe_y{axe_y};
      int b_axe_y{axe_y + axe_height};

      if (b_axe_y > height || u_axe_y < 0) {
        direction = -direction;
      }

      // Game Logic Start
      DrawCircle(circle_X_Pos, circle_Y_Pos, circle_Radius, BLACK);
      DrawRectangle(axe_x, axe_y, axe_length, axe_height, RED);

      if (IsKeyDown(KEY_D) && circle_X_Pos < width) {
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
  }

  return 0;
}

// Spent time reading
