//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "Gate.hpp"
#include "Component4008.hpp"

nts::Component4008::Component4008() : AComponent("4008")
{
  pushPin(this->_pins, 10, OUT);
  pushPin(this->_pins, 161, OUT);
  pushPin(this->_pins, 9, IN);
  pushPin(this->_pins, 6, IN);
  pushPin(this->_pins, 7, IN);

  pushPin(this->_pins, 11, OUT);
  pushPin(this->_pins, 171, OUT);
  pushPinInside(this->_pins, 162, 161, this);
  pushPin(this->_pins, 4, IN);
  pushPin(this->_pins, 5, IN);

  pushPin(this->_pins, 12, OUT);
  pushPin(this->_pins, 181, OUT);
  pushPinInside(this->_pins, 172, 171, this);
  pushPin(this->_pins, 2, IN);
  pushPin(this->_pins, 3, IN);

  pushPin(this->_pins, 13, OUT);
  pushPin(this->_pins, 14, OUT);
  pushPinInside(this->_pins, 182, 181, this);
  pushPin(this->_pins, 15, IN);
  pushPin(this->_pins, 1, IN);
}

nts::Tristate nts::Component4008::Compute(size_t pin_num_this)
{
  std::vector<t_pin>::iterator it;
  std::vector<t_pin>::iterator jt;
  std::vector<t_pin>::iterator kt;
  std::vector<t_pin>::iterator lt;
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
      jt = it;
      ++jt;
      if (it->pin_num < 14)
	++jt;
      kt = jt;
      ++kt;
      lt = kt;
      ++lt;

      if (it->pin_num < 14)
      	res = gateXor(this->Compute(jt->link_pin), gateXor(this->Compute(kt->link_pin), this->Compute(lt->link_pin)));
      else
	res = gateOr(gateAnd(this->Compute(kt->link_pin), this->Compute(lt->link_pin)),
		      gateAnd(this->Compute(jt->link_pin),
			      gateXor(this->Compute(kt->link_pin), this->Compute(lt->link_pin))));
    }
  it->value = res;
  return (res);
}
