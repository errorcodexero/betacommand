// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _STARTCOLLECTOR_H_
#define _STARTCOLLECTOR_H_

#include <WPILib.h>

class StartCollector : public Command
{
public:
    StartCollector();
    virtual ~StartCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _STARTCOLLECTOR_H_
