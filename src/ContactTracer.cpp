#include "Agent.h"
#include <iostream>
ContactTracer::ContactTracer() : Agent() {}

void ContactTracer::act(Session &session)
{
    std::cout << "Virus act" << std::endl;
}