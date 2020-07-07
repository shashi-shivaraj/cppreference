#include "header.h"

static int s_Variable = 5; //static to this unit

void function()
{
    std::cout << "Static varaible = " << s_Variable << std::endl;
}