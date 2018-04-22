// Author: Adán G. Medrano-Chávez
// This is a super class of all kind of generators

package mips.base;

simple Generator
{
    parameters:
        double delay @unit(s) = default(0s);
        double offset @unit(s) = default(0s);
        @display("i=block/tx");
    gates:
        output out;
}

@license(LGPL);