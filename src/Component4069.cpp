//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "Gate.hpp"
#include "Component4069.hpp"

nts::Component4069::Component4069() : AComponent("4069")
{
  pushDoublePin(this->_pins, 1, 2);
  pushDoublePin(this->_pins, 3, 4);
  pushDoublePin(this->_pins, 5, 6);
  pushDoublePin(this->_pins, 9, 8);
  pushDoublePin(this->_pins, 11, 10);
  pushDoublePin(this->_pins, 13, 12);
}

nts::Tristate nts::Component4069::Compute(size_t pin_num_this)
{
  std::vector<t_pin>::iterator it;
  nts::Tristate res;

  it = find(this->_pins->begin(), this->_pins->end(), pin_num_this);
  if (it == this->_pins->end())
    return (UNDEFINED);
  if (it->type == IN)
    {
      if (it->link_comp)
	res = it->link_comp->Compute(it->link_pin);
      else
	res = UNDEFINED;
    }
  else
    {
      std::vector<t_pin>::iterator jt;

      jt = it;
      ++jt;
      res = gateNot(this->Compute(jt->link_pin));
    }
  it->value = res;
  return (res);
}
