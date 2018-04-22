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

import mips.simplehardware.RegisterFile;
import mips.common.NumberGenerator;
import mips.common.Indicator;
import mips.common.ClockGenerator;
import mips.common.AddressGenerator;
import mips.common.SignalGenerator;
import mips.common.ElectronicNode;

network RegisterFileTestbench
{
    @display("bgb=1443.84,1287.424;bgl=2");
    submodules:
        clk: ClockGenerator {
            @display("i=mips/clock;p=171.456,1146.048;is=s");
        }
        rs: AddressGenerator {
            @display("p=171.456,264.704;is=n");
        }
        rt: AddressGenerator {
            @display("p=171.456,430.14398");
        }
        rd: AddressGenerator {
            @display("p=171.456,601.6");
        }
        rng: NumberGenerator {
            @display("p=171.456,770.048");
        }
        sg: SignalGenerator {
            @display("p=171.456,959.552");
        }
        i1: Indicator {
            @display("p=1365.632,887.36");
        }
        i2: Indicator {
            @display("p=1365.632,484.288");
        }
        regFile: RegisterFile {
            @display("i=mips/register,yellow;b=,,rect;is=s;p=815.16797,655.744");
        }
    connections:
        rng.out --> { @display("m=a"); } --> regFile.dataIn;
        rt.out --> { @display("m=w"); } --> regFile.regAddr2;
        rs.out --> { @display("m=w"); } --> regFile.regAddr1;
        rd.out --> { @display("m=w"); } --> regFile.regAddrDest;
        regFile.rs --> i2.in;
        regFile.rt --> i1.in;
        clk.out --> regFile.clk;
        sg.out --> regFile.regWrite;
}
