#include "Agent.h"
#include <iostream>
ContactTracer::ContactTracer() : Agent() {}

void ContactTracer::act(Session &session)
{
    std::cout << "C.Traver act" << std::endl;
}