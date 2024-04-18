#ifndef NODE_H
#define NODE_H

#include "raylib.h"
#include "entity.h"

class Node : public Entity
{
public:
    Node(int Type);
    virtual ~Node();

    virtual void update(float deltaTime);
    int getType() const;
    int type;
private:


};


#endif // NODE_H