//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(std::string const &name, size_t pin_out, Tristate value) : ASubComponent(name, SIZE_MAX, SIZE_MAX, pin_out)
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  (*it).value = value;
}

nts::ComponentInput::~ComponentInput()
{
}

nts::Tristate nts::ComponentInput::SubCompute(std::vector<t_pin>::iterator jt)
{
  return (jt->value);
}

void nts::ComponentInput::setValue(nts::Tristate value)
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  (*it).value = value;
}