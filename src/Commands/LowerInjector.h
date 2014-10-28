// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _LOWERINJECTOR_H_
#define _LOWERINJECTOR_H_

#include <WPILib.h>

class LowerInjector : public Command
{
public:
    LowerInjector();
    virtual ~LowerInjector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // _LOWERINJECTOR_H_
