// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _CLOSEFINGERS_H_
#define _CLOSEFINGERS_H_

#include <WPILib.h>

class CloseFingers : public Command
{
public:
    CloseFingers();
    virtual ~CloseFingers();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


#endif // _CLOSEFINGERS_H_
