// Author: Adán G. Medrano-Chávez
// This module generates addressess rs, rt or rd
//kind rs --> 3, rt --> 4, rd --> 5

package mips.common;

import mips.base.Generator;

simple AddressGenerator extends Generator
{
    parameters:
        @class(AddressGenerator);
        int msgKind = default(3);//rs
}

@license(LGPL);