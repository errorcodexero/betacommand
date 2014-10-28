// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _OPENFINGERS_H_
#define _OPENFINGERS_H_

#include <WPILib.h>

class OpenFingers : public Command
{
public:
    OpenFingers();
    virtual ~OpenFingers();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


#endif // _OPENFINGERS_H_
