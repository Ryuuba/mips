package mips.common;

simple OutputPort
{
    parameters:
        @display("i=block/departure;is=n");
        int msgKind = default(0);
        string signalName;
    gates:
        output out;
}
