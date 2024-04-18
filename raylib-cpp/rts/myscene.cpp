#include "myscene.h"

Myscene::Myscene() : Scene()
{
    CreateGrid();
    p();
    //util->CreateTxTfile( 4 ,4, numbers, stopChar);

}
Myscene::~Myscene()
{   
    for (auto it = nodes.begin(); it != nodes.end(); ++it) 
    {
        if ((*it)->type == 0)
        { 
            delete *it;
            it = nodes.erase(it);
        }
    }
    nodes.clear();

    delete playerMainBase;
    playerMainBase = nullptr;
}
void Myscene::update(float deltaTime) 
{
    PlacePlayerMainbase();
    PLaceEnemyMainBase();
}

void Myscene::p()
{
    // enemyMainBase = new Mainbase(1);
    // enemyMainBase->position.x = 150;
    // enemyMainBase->position.y = 100;
    // enemyMainBase->position.z = 0;
    // this->addChild(enemyMainBase);
    // mainbases.push_back(playerMainBase);
}



void Myscene::CreateGrid()
{
    nodes = std::vector<Node *>();
    mainbases = std::vector<Mainbase*>();

    for(int y = 0; y < 21; y++)
    {
        for(int x = 0; x < 21; x++)
        {
            if(map[x][y] == 0)
            {
                grassNode = new Node(0);
                grassNode->position = Vector3{ x*64.0f ,y*64.0f ,0};
                this->addChild(grassNode);
                nodes.push_back(grassNode);
            }
        }
    }
}

void Myscene::PlacePlayerMainbase()
{
    if (!mainBasePlaced && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        mouseX = GetMouseX() / nodeSize;
        mouseY = GetMouseY() / nodeSize;

        if (mouseX >= 0 && mouseX < mapWidth && mouseY >= 0 && mouseY < mapHeight)
        {
            if (map[mouseX][mouseY] == 0)
            {
                map[mouseX][mouseY] = 1;

                for (auto it = nodes.begin(); it != nodes.end(); ++it) 
                {
                    if ((*it)->position.x == mouseX * nodeSize && (*it)->position.y == mouseY * nodeSize) 
                    {
                        this->removeChild(*it);
                        nodes.erase(it);
                        break;
                    }
                }

                playerMainBase = new Mainbase(0);
                playerMainBase->position = Vector3{(float)mouseX * nodeSize, (float)mouseY * nodeSize, 0};
                this->addChild(playerMainBase);
                mainbases.push_back(playerMainBase);

                mainBaseX = mouseX;
                mainBaseY = mouseY;
                mainBasePlaced = true;

            }
        }
    }
}

void Myscene::PLaceEnemyMainBase()
{
    if(mainBasePlaced)
    {
        oppPosX = centerX - (playerMainBase->position.x - centerX);
        oppPosY = centerY - (playerMainBase->position.y - centerY);
        
        Vector3 oppPos = {oppPosX, oppPosY, 0}; 

        enemyMainBase = new Mainbase(1);
        enemyMainBase->position = oppPos;
        this->addChild(enemyMainBase);
        mainbases.push_back(enemyMainBase); 

        std::cerr << "posx: " << oppPosX << std::endl;
        std::cerr << "posy: " << oppPosY << std::endl;
    }
}
