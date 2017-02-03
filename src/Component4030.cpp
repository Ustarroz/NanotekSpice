//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "Gate.hpp"
#include "Component4030.hpp"

nts::Component4030::Component4030() : AComponent("4030")
{
  pushTripletPin(this->_pins, 1, 2, 3);
  pushTripletPin(this->_pins, 5, 6, 4);
  pushTripletPin(this->_pins, 8, 9, 10);
  pushTripletPin(this->_pins, 12, 13, 11);
}

nts::Tristate nts::Component4030::Compute(size_t pin_num_this)
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
      std::vector<t_pin>::iterator kt;

      jt = it;
      ++jt;
      kt = jt;
      ++kt;
      res = gateXor(this->Compute(jt->link_pin),this->Compute(kt->link_pin));
    }
  it->value = res;
  return (res);
}
