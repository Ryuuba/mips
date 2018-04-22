// Description: This module implements a D Register with
// enable a parallel load

package mips.simplehardware;

import mips.base.SequentialModule;

simple Register extends SequentialModule
{
    parameters:
        @class(Register);
        @display("i=mips/register");
    gates:
        input d;
        input enable;
        output q;
}