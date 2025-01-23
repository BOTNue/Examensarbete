#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

typedef struct Player
{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
} Player;

Player player = {
    .position = {300, 225},
    .velocity = {50.0f, 0.0f},
    .size = {50, 150},
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Online Fighting Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_D))
        {
            player.position.x += player.velocity.x * GetFrameTime();
        }

        if (IsKeyDown(KEY_A))
        {
            player.position.x -= player.velocity.x * GetFrameTime();
        }

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
        ClearBackground(BLACK);
        DrawRectangleV((Vector2){0, 375}, (Vector2){SCREEN_WIDTH, 125}, WHITE);
        DrawRectangleV(player.position, player.size, RED);
        EndDrawing();
    }
    CloseWindow();
}