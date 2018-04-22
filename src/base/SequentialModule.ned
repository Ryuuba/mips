// Description: This module is an abstract class for sequential modules
// It co
package mips.base;

simple SequentialModule
{
    parameters:
        double delay @unit(s) = default(0s);
    gates:
        input clk;
}