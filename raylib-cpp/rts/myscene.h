#ifndef MYSCENE_H
#define MYSCENE_H

#include "scene.h"
#include "raylib.h"
#include "mainbase.h"
#include "node.h"
#include "util.h"

class Myscene : public Scene
{
public:
    Myscene();
    virtual ~Myscene();

    virtual void update(float deltaTime);

    void p();
    void CreateGrid();

    void PlacePlayerMainbase();
    void PLaceEnemyMainBase();


    static const int nodeSize = 64;

    static const int mapWidth = 500 / nodeSize;
    static const int mapHeight =  500 / nodeSize;

    int map[mapHeight][mapWidth] = {0};
    int mainBaseX = -1;
    int mainBaseY = -1;
    int mouseX;
    int mouseY;

    float centerX = screenWidth / 2.0f;
    float centerY = screenHeight / 2.0f; 

    float oppPosX;
    float oppPosY;

    bool mainBasePlaced = false;

    Mainbase* playerMainBase = nullptr;
    Mainbase* enemyMainBase;

    Node* grassNode;
    Node* waterNode;

private:

    Util* util;

    std::vector<Node*> nodes;
    std::vector<Mainbase*> mainbases;

    std::vector<int> numbers = {1, 0, 4, 5}; 
    char stopChar = '-';
    std::string folderPath;
    std::string fullPath; 

};

#endif // MYSCENE_H