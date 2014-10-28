// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _STOPCOLLECTOR_H_
#define _STOPCOLLECTOR_H_

#include <WPILib.h>

class StopCollector : public Command
{
public:
    StopCollector();
    virtual ~StopCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _STOPCOLLECTOR_H_
