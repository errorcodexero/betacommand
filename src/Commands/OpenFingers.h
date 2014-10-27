#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class OpenFingers : public Command
{
public:
    OpenFingers();
    virtual ~OpenFingers();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


