#include "node.h"

Node::Node(int Type) : Entity(), type(Type)
{
     if(type == 0)
     {
          this->addTexture("assets/grass.png");
     }
     else if(type == 1)
     {
          this->addTexture("assets/water.png");
     } 
     
}
Node::~Node()
{

}
void Node::update( float deltaTime )
{

} 
int Node::getType() const
{
     return type;
}