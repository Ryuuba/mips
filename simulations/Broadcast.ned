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
import mips.common.Indicator;
import mips.common.ElectronicNode;

network Broadcast
{
    parameters:
        int numberOfNeighbors = default(5);
        @display("bgb=400,400");
    submodules:
        ng: NumberGenerator {
            @display("p=90,179");
        }
        indicator[numberOfNeighbors]: Indicator {
            @display("p=288,50");
        }
        node[numberOfNeighbors - 1]: ElectronicNode {
            outGateNumber = 2;
        }
    connections:
        ng.out --> node[0].in;
        for i=0..numberOfNeighbors-3 {
            node[i].out[0] --> indicator[i].in;
            node[i].out[1] --> node[i+1].in;
        }
        node[numberOfNeighbors-2].out[0] --> indicator[numberOfNeighbors-2].in;
        node[numberOfNeighbors-2].out[1] --> indicator[numberOfNeighbors-1].in;
}
