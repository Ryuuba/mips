// Author: Adán G. Medrano-Chávez
// Description: This module emits a clock signal which uses the omnetpp signal method.
//Sequential modules have to inherit cListerner
//in order to receive the clock signal

package mips.common;

simple ElectronicNode
{
    parameters:
        @display("i=mips/node");
        int outGateNumber = default(2);
    gates:
        input in;
        output out[outGateNumber];
}