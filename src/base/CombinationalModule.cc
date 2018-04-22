#include "../base/CombinationalModule.h"

Register_Abstract_Class(CombinationalModule);

CombinationalModule::CombinationalModule(){
  delay = nullptr;
  module_delay = 0.0;
}

void CombinationalModule::initialize() {

}