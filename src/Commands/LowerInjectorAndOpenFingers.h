#include <WPILib.h>
#include <Commands/Command.h>
#include "../Robot.h"
#include "LowerInjector.h"
#include "OpenFingers.h"

class LowerInjectorAndOpenFingers : public CommandGroup
{
public:
    LowerInjectorAndOpenFingers();
    virtual ~LowerInjectorAndOpenFingers();
};

