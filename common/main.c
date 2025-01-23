#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Online Fighting Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER) && IsKeyDown(KEY_LEFT_ALT))
        {
            int display = GetCurrentMonitor();

            if (IsWindowFullscreen())
            {
                SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            else
            {
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
            }

            ToggleFullscreen();
        }

        BeginDrawing();
        DrawRectangleV((Vector2){0, 375}, (Vector2){SCREEN_WIDTH, 125}, WHITE);
        EndDrawing();
    }
    CloseWindow();
}