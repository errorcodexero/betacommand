#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class StopCollector : public Command
{
public:
    StopCollector();
    virtual ~StopCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


