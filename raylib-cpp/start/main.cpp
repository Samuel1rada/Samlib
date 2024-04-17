#include "raylib.h"
#include <iostream>
#include <vector>

#pragma warning(disable:4576)
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 50
#define MAP_WIDTH (SCREEN_WIDTH / TILE_SIZE)
#define MAP_HEIGHT (SCREEN_HEIGHT / TILE_SIZE)

// Constants for unit spawning
#define SPAWN_INTERVAL 10
#define UNIT_SPEED 2

int mainBaseX = -1;
int mainBaseY = -1;
bool mainBasePlaced = false;

float spawnTimer = 0.0f;

typedef struct
{
    Vector2 position;
    Vector2 destination; 

    bool active;
    bool selected;  
} Unit;

std::vector<Unit> units; 

// Function to spawn a unit near the main base
void SpawnUnit(int baseX, int baseY)
{
    Unit newUnit;
    newUnit.selected = false;
    newUnit.position.x = (baseX + 1) * TILE_SIZE;
    newUnit.position.y = baseY * TILE_SIZE;
    newUnit.active = true;
    newUnit.destination = newUnit.position; 
    units.push_back(newUnit);

    std::cout << "Unit spawned at position (" << newUnit.position.x << ", " << newUnit.position.y << ")\n";
}

// Function to handle unit selection
void SelectUnits()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePosition = GetMousePosition();

        for (Unit &unit : units)
        {
            Rectangle unitBounds = {unit.position.x, unit.position.y, TILE_SIZE, TILE_SIZE};
            if (CheckCollisionPointRec(mousePosition, unitBounds))
            {
                unit.selected = !unit.selected;
            }
        }
    }
}

// Function to handle movement command
void IssueMovementCommand()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 targetTile = GetMousePosition();

        for (Unit &unit : units)
        {
            if (unit.selected)
            {
                unit.destination = targetTile;
            }
        }
    }
}

void UpdateUnitMovement()
{
    for (Unit &unit : units)
    {

        if (unit.position.x != unit.destination.x || unit.position.y != unit.destination.y)
        {
            Vector2 center = { unit.position.x + TILE_SIZE / 2, unit.position.y + TILE_SIZE / 2 };
            Vector2 direction = { unit.destination.x - center.x, unit.destination.y - center.y };
            float length = sqrt(direction.x * direction.x + direction.y * direction.y);

            if (length > 0)
            {
                direction.x /= length;
                direction.y /= length;

                center.x += direction.x * UNIT_SPEED;
                center.y += direction.y * UNIT_SPEED;

                unit.position.x = center.x - TILE_SIZE / 2;
                unit.position.y = center.y - TILE_SIZE / 2;
            }

            if (abs(unit.position.x - unit.destination.x) <= UNIT_SPEED && abs(unit.position.y - unit.destination.y) <= UNIT_SPEED)
            {
                unit.position = unit.destination;
            }

        }
    }
}

void AstarPath()
{
    
}


// Function to draw movement lines for selected units
void DrawMovementLines()
{
    for (const Unit &unit : units)
    {
        if (unit.selected)
        {
            DrawLine(unit.position.x + TILE_SIZE / 2, unit.position.y + TILE_SIZE / 2,
                     unit.destination.x, unit.destination.y, BLUE);
        }
    }
}

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RTS Game with Raylib");

    // Load images for tiles and unit
    Image grassTileImage = LoadImage("assets/grass.png");
    Image mainBaseImage = LoadImage("assets/mainbase.png");
    Image unitImage = LoadImage("assets/test.png");

    ImageResize(&grassTileImage, TILE_SIZE, TILE_SIZE);
    ImageResize(&mainBaseImage, TILE_SIZE, TILE_SIZE);
    ImageResize(&unitImage, TILE_SIZE, TILE_SIZE);

    Texture2D grassTileTexture = LoadTextureFromImage(grassTileImage);
    Texture2D mainBaseTexture = LoadTextureFromImage(mainBaseImage);
    Texture2D unitTexture = LoadTextureFromImage(unitImage);

    UnloadImage(grassTileImage);
    UnloadImage(mainBaseImage);
    UnloadImage(unitImage);

    // Define map
    int map[MAP_WIDTH][MAP_HEIGHT] = {0};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update

        if (!mainBasePlaced && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            int mouseX = GetMouseX() / TILE_SIZE;
            int mouseY = GetMouseY() / TILE_SIZE;

            if (mouseX >= 0 && mouseX < MAP_WIDTH && mouseY >= 0 && mouseY < MAP_HEIGHT)
            {

                if (map[mouseX][mouseY] == 0)
                {
                    mainBaseX = mouseX;
                    mainBaseY = mouseY;
                    map[mainBaseX][mainBaseY] = 1;
                    mainBasePlaced = true;
                }
            }
        }

        // Update timer
        spawnTimer += GetFrameTime();

        // Check if it's time to spawn a unit
        if (mainBasePlaced && spawnTimer >= SPAWN_INTERVAL)
        {
            // Spawn a unit near the main base
            SpawnUnit(mainBaseX, mainBaseY);

            // Reset spawn timer
            spawnTimer = 0.0f;
        }
        if (units.size() > 0) 
        {
            Vector2 firstUnitPosition = units[0].position;
            std::cout << "Position of the first unit: (" << firstUnitPosition.x << ", " << firstUnitPosition.y << ")" << std::endl;
        }

        // Handle unit selection and movement commands
        SelectUnits();
        // IssueMovementCommand();
        UpdateUnitMovement();

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw map
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            for (int x = 0; x < MAP_WIDTH; x++)
            {
                // Draw tiles
                Rectangle tileRect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                if (map[x][y] == 0) // Empty tile
                {
                    DrawTextureEx(grassTileTexture, (Vector2){(float)(x * TILE_SIZE), (float)(y * TILE_SIZE)}, 0.0f, 1.0f, WHITE);
                }
                else if (map[x][y] == 1) // Main base tile
                {
                    DrawTextureEx(mainBaseTexture, (Vector2){(float)(x * TILE_SIZE), (float)(y * TILE_SIZE)}, 0.0f, 1.0f, WHITE);
                }
                // You can add more types of tiles here as needed
            }
        }

        // Draw units
        for (const Unit &unit : units)
        {
            if (unit.active)
            {
                DrawTexture(unitTexture, unit.position.x, unit.position.y, WHITE);
            }
        }

        // Draw movement lines for selected units
        DrawMovementLines();

        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(grassTileTexture);
    UnloadTexture(mainBaseTexture);
    UnloadTexture(unitTexture);
    CloseWindow();

    return 0;
}
