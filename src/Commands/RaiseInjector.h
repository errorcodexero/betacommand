// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _RAISEINJECTOR_H_
#define _RAISEINJECTOR_H_

#include <WPILib.h>

class RaiseInjector : public Command
{
public:
    RaiseInjector();
    virtual ~RaiseInjector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _RAISEINJECTOR_H_
