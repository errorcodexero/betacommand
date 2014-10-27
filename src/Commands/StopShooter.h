#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

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


