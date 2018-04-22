// Author: Adán G. Medrano-Chávez
// This modules generates random numbers draw from a uniform discrete 
// distribution. Its purpouse is provided operands to combinational modules.

package mips.common;
import mips.base.Generator;

simple NumberGenerator extends Generator
{
    parameters:
        @class(NumberGenerator);
        //lower limit of a discrete uniform distribution
        int a = default(-1024);
        //upper limit of a discrete uniform distribution
        int b = default(1023);
}

@license(LGPL);
