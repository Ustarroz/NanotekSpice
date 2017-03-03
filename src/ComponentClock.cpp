//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock(std::string const &name, size_t pin_out) : ASubComponent(name, SIZE_MAX, SIZE_MAX, pin_out)
{
}

nts::ComponentClock::~ComponentClock()
{
}

nts::Tristate nts::ComponentClock::SubCompute(std::vector<t_pin>::iterator jt)
{
  nts::Tristate res;

  res = jt->value;

  jt->value = (jt->value == nts::TRUE) ? nts::FALSE : nts::TRUE;
  return (res);
}