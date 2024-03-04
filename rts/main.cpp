#include "raylib.h"
#include "homebase.h"
#include "myscene.h"
#include "scene.h"

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

int main(void)
{
    // Myscene myscene;   

    // HomeBase homebase;
    // homebase.position = {100.0f, 100.0f, 0.0f};

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture("assets/test.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
    
}
