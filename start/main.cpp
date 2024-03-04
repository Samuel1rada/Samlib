#include <iostream>
#include <fstream>
#include "raylib.h"

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

int main()
{

    
    std::ifstream file("test.png");

    // Check if the file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file 'test.png'" << std::endl;
        // Handle the error accordingly, such as exiting the program or returning an error code
        return 1;
    }

    // File opened successfully, proceed with reading or other operations

    file.close(); // Close the file when done


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture("test.png");

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
