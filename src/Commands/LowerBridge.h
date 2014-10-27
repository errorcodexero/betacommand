#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

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


