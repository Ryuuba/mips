// Author: Adán G. Medrano-Chávez
// Description: This module receives a word and shows 
// its fields if it's an instruction, otherwise shows
// the data value

package mips.common;

simple Indicator
{
    parameters:
        @display("i=block/rx");
    gates:
        input in;
}
