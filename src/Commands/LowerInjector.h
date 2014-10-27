#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

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


