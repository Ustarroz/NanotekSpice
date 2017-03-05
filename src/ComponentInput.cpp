//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(std::string const &name) : ASubComponent(name, SIZE_MAX, SIZE_MAX, 1)
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  it->value = UNDEFINED;
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
  it->value = value;
}

nts::Tristate nts::ComponentInput::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (UNDEFINED);
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  return (it->value);
}

bool nts::ComponentInput::CheckValue() const
{
  std::vector<t_pin>::const_iterator it;

  it = this->_pins.begin();
  return (it->value != nts::UNDEFINED);
}