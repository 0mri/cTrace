#ifndef AGENT_H_
#define AGENT_H_

#include "Session.h"

class Agent
{
public:
    Agent();
    virtual ~Agent() = default;
    virtual void act(Session &session) = 0;
    
    virtual Agent* clone() const = 0;
};

class ContactTracer : public Agent
{
public:
    ContactTracer();
    virtual ~ContactTracer() = default;
    virtual void act(Session &session);

    virtual ContactTracer* clone() const;
};

class Virus : public Agent
{
public:
    Virus(int nodeInd);
    virtual ~Virus() = default;
    virtual Virus* clone() const;

    virtual void act(Session &session);

private:
    const int nodeInd;
};

#endif