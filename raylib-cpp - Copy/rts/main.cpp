#include "raylib.h"
#include "myscene.h"
#include <core.h>


int main() {

    Core core;
    
    Myscene* myscene = new Myscene();
    while(myscene->isActive())
    {
        core.runScene(myscene);
    }
    
    delete myscene;
    return 0;
}