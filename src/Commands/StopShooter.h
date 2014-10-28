// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _STOPSHOOTER_H_
#define _STOPSHOOTER_H_

#include <WPILib.h>

class StopShooter : public Command
{
public:
    StopShooter();
    virtual ~StopShooter();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _STOPSHOOTER_H_
