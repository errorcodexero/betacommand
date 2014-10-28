// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _REVERSECOLLECTOR_H_
#define _REVERSECOLLECTOR_H_

#include <WPILib.h>

class ReverseCollector : public Command
{
public:
    ReverseCollector();
    virtual ~ReverseCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _REVERSECOLLECTOR_H_
