// Author: Adán G. Medrano-Chávez
// This modules generates ctrl signal being read from a trace file
// Its purpouse is provided ctrl signals to modules that need them

package mips.common;

import mips.base.Generator;

simple SignalGenerator extends Generator
{
    parameters:
        @class(SignalGenerator);
        string trace;
        string signalName;
        int size;
}

@license(LGPL);
