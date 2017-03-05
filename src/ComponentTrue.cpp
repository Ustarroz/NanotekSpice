//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue(std::string const &name) : ComponentInput(name)
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  (*it).value = TRUE;
}

nts::ComponentTrue::~ComponentTrue()
{
}

void nts::ComponentTrue::setValue(nts::Tristate value)
{
  (void) value;
}