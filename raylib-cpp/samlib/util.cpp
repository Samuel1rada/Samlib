#include "util.h"
#include <fstream>
#include <vector>

Util::Util()
{
}
Util::~Util()
{
}

void Util::CreateTxTfile(int rows, int columns, const std::vector<int>& numbers, char stopCharacter)
{

    std::ofstream TextFile("text.txt");

    // Ensure the file is open
    if (!TextFile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    for (int row = 0; row < rows; ++row) 
    {
        for (int col = 0; col < columns; ++col) 
        {

            for (int number : numbers) {
                TextFile << number;
            }
            if (col < columns - 1) {
                TextFile << " ";
            }
        }
        TextFile << std::endl;
    }

    TextFile.close();
}

