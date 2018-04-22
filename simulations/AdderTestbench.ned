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
import mips.simplehardware.Adder;
import mips.common.Indicator;

network AdderTestbench
{
    @display("bgb=300,300");
    submodules:
        numberGeneratorA: NumberGenerator {
            @display("p=80,265");
            delay = 1s;
        }
        numberGeneratorB: NumberGenerator {
            @display("p=80,55");
            delay = 1s;
        }
        adder: Adder {
            @display("p=80,160");
        }
        indicator: Indicator {
            @display("p=240,160;is=n");
        }
    connections:
        numberGeneratorA.out --> adder.portA;
        numberGeneratorB.out --> adder.portB;
        adder.result --> indicator.in;
}
