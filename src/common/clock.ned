// Author: Adán G. Medrano-Chávez
// Description: This module emits a clock signal which uses the omnetpp signal method.
//Sequential modules have to inherit cListerner
//in order to receive the clock signal

package mips.common;

simple ClockGenerator
{
    parameters:
        @display("i=mips/clock");
        double period @unit(s) = default(100ns);
        double offset @unit(s) = default(0s);
    gates:
        output out;
}
