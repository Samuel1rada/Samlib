#include "raylib.h"
#include "myscene.h"
#include <core.h>
#include <util.h>


int main() {

    Core core;
    
    Myscene* myscene = new Myscene();
    while(myscene->isActive())
    {
        core.run(myscene);
    }
    
    delete myscene;
    return 0;

}