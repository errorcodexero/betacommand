// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _LOWERBRIDGE_H_
#define _LOWERBRIDGE_H_

#include <WPILib.h>

class LowerBridge : public Command
{
public:
    LowerBridge();
    virtual ~LowerBridge();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _LOWERBRIDGE_H_
