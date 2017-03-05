//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock(std::string const &name) : ComponentInput(name)
{
  this->_first = false;
}

nts::ComponentClock::~ComponentClock()
{
}

nts::Tristate nts::ComponentClock::SubCompute(std::vector<t_pin>::iterator jt)
{
  return (jt->value);
}

void nts::ComponentClock::reset()
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  it->value = (it->value == nts::TRUE) ? nts::FALSE : nts::TRUE;
  it->done = false;
}

void nts::ComponentClock::setValue(nts::Tristate value)
{
  std::vector<t_pin>::iterator it;

  if (this->_first)
    return;

  it = this->_pins.begin();
  it->value = value;
  this->_first = true;
}