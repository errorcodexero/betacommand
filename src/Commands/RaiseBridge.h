#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class RaiseBridge : public Command
{
public:
    RaiseBridge();
    virtual ~RaiseBridge();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};


