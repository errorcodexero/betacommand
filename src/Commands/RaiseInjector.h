#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

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


