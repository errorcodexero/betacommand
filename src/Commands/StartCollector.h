#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class StartCollector : public Command
{
public:
    StartCollector();
    virtual ~StartCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


