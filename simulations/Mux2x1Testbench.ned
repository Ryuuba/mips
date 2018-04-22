package mips.simulations;

import mips.common.NumberGenerator;
import mips.simplehardware.Mux2x1;
import mips.common.Indicator;
import mips.common.SignalGenerator;

network Mux2x1Testbench
{
    @display("bgb=300,300");
    submodules:
        numberGeneratorB: NumberGenerator {
            @display("p=75,255");
        }
        numberGeneratorA: NumberGenerator {
            @display("p=75,45");
        }
        selector: SignalGenerator {
            @display("p=185,45");
        }
        mux2x1: Mux2x1 {
            @display("p=185,150");
        }
        indicator: Indicator {
            @display("p=250,150;is=n");
        }
    connections:
        numberGeneratorA.out --> mux2x1.portA;
        numberGeneratorB.out --> mux2x1.portB;
        selector.out --> mux2x1.selector;
        mux2x1.portF --> indicator.in;
}