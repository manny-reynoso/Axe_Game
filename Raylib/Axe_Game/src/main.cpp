#include <raylib.h>

int main() {
  // Window dimensions
  int width{1280};
  int height{720};

  InitWindow(width, height, "Window");
  SetTargetFPS(60);

  // Circle coordinates
  int circle_X_Pos{175};
  int circle_Y_Pos{100};
  int circle_Radius{10};

  // Axe coordinates
  int axe_x{400};
  int axe_y{0};
  int axe_length{50};
  int axe_height{50};

  int direction{10};

  bool collision_with_axe{false};

  while (!WindowShouldClose()) {
    // Restart the game when R is pressed
    if (collision_with_axe && IsKeyPressed(KEY_R)) {
      circle_X_Pos = 175;
      circle_Y_Pos = 100;

      axe_x = 400;
      axe_y = 0;

      direction = 10;
      collision_with_axe = false;
    }

    // Only update the game while there has not been a collision
    if (!collision_with_axe) {
      // Axe movement
      axe_y += direction;

      // Keep the axe inside the window and reverse its direction
      if (axe_y + axe_height >= height) {
        axe_y = height - axe_height;
        direction = -direction;
      } else if (axe_y <= 0) {
        axe_y = 0;
        direction = -direction;
      }

      // Circle movement
      if (IsKeyDown(KEY_D) && circle_X_Pos + circle_Radius < width) {
        circle_X_Pos += 10;
      }

      if (IsKeyDown(KEY_A) && circle_X_Pos - circle_Radius > 0) {
        circle_X_Pos -= 10;
      }

      if (IsKeyDown(KEY_W) && circle_Y_Pos - circle_Radius > 0) {
        circle_Y_Pos -= 10;
      }

      if (IsKeyDown(KEY_S) && circle_Y_Pos + circle_Radius < height) {
        circle_Y_Pos += 10;
      }

      // Circle collision boundaries
      int l_circle_x{circle_X_Pos - circle_Radius};
      int r_circle_x{circle_X_Pos + circle_Radius};
      int u_circle_y{circle_Y_Pos - circle_Radius};
      int b_circle_y{circle_Y_Pos + circle_Radius};

      // Axe collision boundaries
      int l_axe_x{axe_x};
      int r_axe_x{axe_x + axe_length};
      int u_axe_y{axe_y};
      int b_axe_y{axe_y + axe_height};

      // Check for collision between the circle and axe
      collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y &&
                           r_axe_x >= l_circle_x && l_axe_x <= r_circle_x;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircle(circle_X_Pos, circle_Y_Pos, circle_Radius, BLACK);
    DrawRectangle(axe_x, axe_y, axe_length, axe_height, RED);

    if (collision_with_axe) {
      const char *gameOverMessage{"Game Over!"};
      const char *restartMessage{"Press R to restart"};

      int gameOverFontSize{40};
      int restartFontSize{20};

      int gameOverTextWidth{MeasureText(gameOverMessage, gameOverFontSize)};

      int restartTextWidth{MeasureText(restartMessage, restartFontSize)};

      DrawText(gameOverMessage, (width - gameOverTextWidth) / 2,
               (height - gameOverFontSize) / 2, gameOverFontSize, RED);

      DrawText(restartMessage, (width - restartTextWidth) / 2,
               (height / 2) + 50, restartFontSize, DARKGRAY);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
