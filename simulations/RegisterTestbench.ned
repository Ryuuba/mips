//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package mips.simulations;

import mips.common.NumberGenerator;
import mips.simplehardware.Register;
import mips.common.Indicator;
import mips.common.ClockGenerator;
import mips.common.SignalGenerator;

network RegisterTestbench
{
    @display("bgb=400,400");
    submodules:
        numberGenerator: NumberGenerator {
            @display("p=260,80");
        }
        enable: SignalGenerator {
            @display("p=40,160");
        }
        register: Register {
            @display("p=260,200;i=,blue");
        }
        indicator: Indicator {
            @display("p=260,320;is=n");
        }
        clock: ClockGenerator {
            @display("p=40,240;is=n");
        }
    connections:

        enable.out --> register.enable;
        numberGenerator.out --> register.d;
        register.q --> indicator.in;
        clock.out --> register.clk;
}
