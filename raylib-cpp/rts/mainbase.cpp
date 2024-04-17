#include "mainbase.h"


Mainbase::Mainbase(int Type) : Entity(), type(Type)
{

    if(type == 0)
    {
        addTexture("assets/mainbase.png");
    } 
    else if(type == 1)
    {
        addTexture("assets/mainbase2.png");
    }
}
Mainbase::~Mainbase()
{

}
void Mainbase::update(float deltaTime)
{

}
int Mainbase::getType() const
{
     return type;
}