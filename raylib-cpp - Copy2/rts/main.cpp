#include "raylib.h"
#include "myscene.h"
#include "core.h"


int main() {
    
    Core core;
    
    MyScene* myscene = new MyScene();
    while(myscene->isActive())
    {
        core.runScene(myscene);
    }
    delete myscene;
    return 0;
}