#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class ReverseCollector : public Command
{
public:
    ReverseCollector();
    virtual ~ReverseCollector();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


