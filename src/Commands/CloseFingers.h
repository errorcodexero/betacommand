#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class CloseFingers : public Command
{
public:
    CloseFingers();
    virtual ~CloseFingers();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


