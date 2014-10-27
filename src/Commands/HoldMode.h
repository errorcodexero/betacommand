#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"

class HoldMode : public CommandGroup
{
public:
    HoldMode();
    virtual ~HoldMode();
};

