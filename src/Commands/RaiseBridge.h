// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
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
