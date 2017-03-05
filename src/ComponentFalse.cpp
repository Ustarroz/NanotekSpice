//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse(std::string const &name) : ComponentInput(name)
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  (*it).value = FALSE;
}

nts::ComponentFalse::~ComponentFalse()
{
}

void nts::ComponentFalse::setValue(nts::Tristate value)
{
  (void) value;
}