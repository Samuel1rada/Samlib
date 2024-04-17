
#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include <entity.h>
#include <vector>
#include <map>
#include <string>

class Util
{
public:
    Util();
    virtual~Util();

    void CreateTxTfile(int rows, int columns, const std::vector<int>& numbers, char stopCharacter);

private:

};

#endif /*UTIL_H*/
