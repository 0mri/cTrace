#include "Agent.h"
#include <iostream>
//Constructor
//Copy Constructor
//distructor

Virus::Virus(int index) : Agent(), nodeInd(index)
{
}

void Virus::act(Session &session){
    std::cout << "Virus act" << std::endl;
}
