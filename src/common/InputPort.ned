
package mips.common;

simple InputPort
{
    parameters:
        @display("i=block/arrival;is=n");
        int msgKind = default(0);
        string signalName;
    gates:
        input in;
}
