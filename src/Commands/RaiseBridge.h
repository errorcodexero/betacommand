// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _RAISEBRIDGE_H_
#define _RAISEBRIDGE_H_

#include <WPILib.h>

class RaiseBridge : public Command
{
public:
    RaiseBridge();
    virtual ~RaiseBridge();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _RAISEBRIDGE_H_
